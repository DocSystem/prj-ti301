//
// Created by Antoine Souben-Fink on 06/12/2023.
//
#include "agenda.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


AgendaEntry *create_agenda_entry(Contact *contact) {
    AgendaEntry *entry = malloc(sizeof(AgendaEntry));
    entry->contact = contact;
    entry->events = NULL;
    entry->nexts = malloc(sizeof(AgendaEntry*) * 4);
    return entry;
}

/**
 * Adds an entry to the agenda.
 * @param agenda the agenda to add the entry to.
 * @param entry the entry to add to the agenda.
 */
void add_entry_to_agenda(Agenda *agenda, AgendaEntry *entry) {
    int level = 3;
    char* id = entry->contact->id;
    // We find the max level of the entry
    // At level 0, we put all the entries
    // At level 1, two first letters are the same as the first two letters of any entry, but not the third
    // At level 2, first letter is the same as the first letter of any entry, but not the second
    // At level 3, first letter is different
    // We start with level max and go down until we find the right level
    AgendaEntry *current = agenda->entries[0];
    while (current != NULL) {
        if (strncmp(id, current->contact->id, 3) == 0) {
            level = 0;
            break;
        }
        current = current->nexts[0];
    }
    if (level != 0) {
        current = agenda->entries[1];
        while (current != NULL) {
            if (strncmp(id, current->contact->id, 2) == 0) {
                level = 1;
                break;
            }
            current = current->nexts[1];
        }
    }
    if (level != 0 && level != 1) {
        current = agenda->entries[2];
        while (current != NULL) {
            if (strncmp(id, current->contact->id, 1) == 0) {
                level = 2;
                break;
            }
            current = current->nexts[2];
        }
    }

    // We add the entry to the agenda at the right level and levels below
    for (int i = level; i >= 0; --i) {
        current = agenda->entries[i];
        if (current == NULL) {
            agenda->entries[i] = entry;
        } else {
            while (current->nexts[i] != NULL) {
                current = current->nexts[i];
            }
            current->nexts[i] = entry;
        }
    }
}

Agenda *create_agenda(int nbLevels) {
    Agenda *agenda = malloc(sizeof(Agenda));
    agenda->nbLevels = nbLevels;
    agenda->entries = malloc(sizeof(AgendaEntry*) * nbLevels);
    for (int i = 0; i < nbLevels; ++i) {
        agenda->entries[i] = NULL;
    }
    return agenda;
}

void display_agenda(Agenda *agenda) {
    for (int i = 0; i < agenda->nbLevels; ++i) {
        printf("Level %d:\n", i);
        AgendaEntry *entry = agenda->entries[i];
        while (entry != NULL) {
            printf("\t");
            display_contact(entry->contact);
            EventList *event = entry->events;
            while (event != NULL) {
                printf("\t\t");
                display_event(event->value);
                event = event->next;
            }
            entry = entry->nexts[i];
        }
    }
}

AgendaEntry* search_entry_contact(Agenda *agenda, char* id_beginning) {
    // todo: OPTIMIZE
    AgendaEntry *current = agenda->entries[0];
    while (current != NULL) {
        if (strncmp(id_beginning, current->contact->id, strlen(id_beginning)) == 0) {
            return current;
        }
        current = current->nexts[0];
    }
    return NULL;
}
