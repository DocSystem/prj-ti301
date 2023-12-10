//
// Created by Antoine Souben-Fink on 06/12/2023.
//

#ifndef PRJ_TI301_AGENDA_H
#define PRJ_TI301_AGENDA_H

#include "event.h"
#include "contact.h"

typedef struct AgendaEntry {
    Contact *contact;
    EventCell *events;
    struct AgendaEntry **nexts;
} AgendaEntry;

typedef struct Agenda {
    int nbLevels;
    AgendaEntry **entries;
} Agenda;

AgendaEntry *create_agenda_entry(Contact *contact);
void add_entry_to_agenda(Agenda *agenda, AgendaEntry *entry);

Agenda *create_agenda(int nbLevels);
void display_agenda(Agenda *agenda);

AgendaEntry *search_entry_contact(Agenda *agenda, char *id_beginning);

#endif //PRJ_TI301_AGENDA_H
