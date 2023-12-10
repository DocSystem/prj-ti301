//
// Created by Antoine Souben-Fink on 06/12/2023.
//
#include "agenda.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


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
    AgendaEntry *previous[4];
    previous[0] = agenda->entries[0];
    previous[1] = agenda->entries[1];
    previous[2] = agenda->entries[2];
    previous[3] = agenda->entries[3];
    while (current != NULL) {
        if (strncmp(id, current->contact->id, 3) == 0) {
            AgendaEntry *next = current->nexts[0];
            level = 0;
            if (next == NULL) {
                previous[0] = current;
                break;
            }
            if (next->contact->id[3] > id[3]) {
                previous[0] = current;
                break;
            }
            previous[0] = current;
        }
        current = current->nexts[0];
    }
    if (level != 0) {
        current = agenda->entries[1];
        while (current != NULL) {
            if (strncmp(id, current->contact->id, 2) == 0) {
                AgendaEntry *next = current->nexts[1];
                level = 1;
                if (next == NULL) {
                    previous[1] = current;
                    break;
                }
                if (next->contact->id[2] > id[2]) {
                    previous[1] = current;
                    break;
                }
                previous[1] = current;
            }
            current = current->nexts[1];
        }
    }
    if (level != 0 && level != 1) {
        current = agenda->entries[2];
        while (current != NULL) {
            if (strncmp(id, current->contact->id, 1) == 0) {
                AgendaEntry *next = current->nexts[2];
                level = 2;
                if (next == NULL) {
                    previous[2] = current;
                    break;
                }
                if (next->contact->id[1] > id[1]) {
                    previous[2] = current;
                    break;
                }
                previous[2] = current;
            }
            current = current->nexts[2];
        }
    }
    if (level != 0 && level != 1 && level != 2) {
        current = agenda->entries[3];
        while (current != NULL) {
            AgendaEntry *next = current->nexts[3];
            level = 3;
            if (next == NULL) {
                previous[3] = current;
                break;
            }
            if (next->contact->id[0] > id[0]) {
                previous[3] = current;
                break;
            }
            current = current->nexts[3];
        }
    }
    // We add the entry to the agenda at the right level and levels below
    for (int i = level; i >= 0; --i) {
        if (previous[i] == NULL) {
            agenda->entries[i] = entry;
        }
        else {
            if (i == level) {
                if (previous[i]->nexts[i] != NULL) {
                    entry->nexts[i] = previous[i]->nexts[i];
                }
                previous[i]->nexts[i] = entry;
            }
            else {
                while (previous[i]->nexts[i] != NULL && previous[i]->nexts[i]->contact->id[3 - i] < id[3 - i]) {
                    previous[i] = previous[i]->nexts[i];
                }
                if (previous[i]->nexts[i] != NULL) {
                    entry->nexts[i] = previous[i]->nexts[i];
                }
                previous[i]->nexts[i] = entry;
            }
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
            EventCell *event = entry->events;
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
    AgendaEntry *current = agenda->entries[3];
    while (current != NULL) {
        if (strncmp(current->contact->id, id_beginning, 1) == 0) {
            break;
        }
        current = current->nexts[3];
    }
    while (current != NULL) {
        if (strncmp(current->contact->id, id_beginning, 2) == 0) {
            break;
        }
        current = current->nexts[2];
    }
    while (current != NULL) {
        if (strncmp(current->contact->id, id_beginning, 3) == 0) {
            break;
        }
        current = current->nexts[1];
    }
    while (current != NULL) {
        if (strncmp(current->contact->id, id_beginning, strlen(id_beginning)) == 0) {
            break;
        }
        current = current->nexts[0];
    }
    return current;
}

/**
 * Fills the agenda with 1000 contacts.
 * @param agenda the agenda to fill.
 */
void fill_agenda(Agenda *agenda) {
    // read 2000 random lines from names.csv
    FILE* file = fopen("names.csv", "r");
    int numLines = 2000;

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Count the total number of lines in the file
    int totalLines = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            totalLines++;
        }
    }

    // Set the seed for random number generation
    srand(time(NULL));

    // Ensure we don't try to read more lines than the total number of lines in the file
    if (numLines > totalLines) {
        numLines = totalLines;
    }

    // Reset file position to the beginning
    fseek(file, 0, SEEK_SET);

    // Read and print 2000 random lines
    char* lines[numLines];
    for (int i = 0; i < numLines; i++) {
        int randomLine = rand() % totalLines;

        // Move to the beginning of the file
        fseek(file, 0, SEEK_SET);

        // Read lines until the randomly selected line
        for (int j = 0; j < randomLine; j++) {
            while ((ch = fgetc(file)) != '\n' && ch != EOF) {
            }
        }

        // Read the selected line
        char* line = malloc(sizeof(char) * 100);
        fgets(line, 100, file);
        line[strlen(line) - 1] = '\0';
        // remove \n
        for (int j = 0; j < strlen(line); ++j) {
            if (line[j] == '\n') {
                line[j] = '\0';
            }
        }
        lines[i] = line;
    }
    fclose(file);

    for (int i = 0; i < 2000; i += 2) {
        char* name = malloc(sizeof(char) * strlen(lines[i]));
        char* surname = malloc(sizeof(char) * strlen(lines[i + 1]));
        strcpy(name, lines[i]);
        strcpy(surname, lines[i + 1]);
        Contact* contact = create_contact(name, surname);
        AgendaEntry* entry = create_agenda_entry(contact);
        add_entry_to_agenda(agenda, entry);
    }
}
