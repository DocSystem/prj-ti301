//
// Created by Antoine Souben-Fink on 10/12/2023.
//

#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int showMenu() {
    int choice;
    printf("====================================================================\n");
    printf("1. Rechercher un contact\n");
    printf("2. Afficher les rendez-vous d'un contact\n");
    printf("3. Créer un contact\n");
    printf("4. Créer un rendez-vous pour un contact\n");
    printf("5. Supprimer un rendez-vous\n");
    printf("6. Sauvegarder le fichier de tous les rendez-vous\n");
    printf("7. Charger un fichier de rendez-vous\n");
    printf("8. Fournir les temps de calcul pour une insertion de nouveau contact\n");
    printf("9. Quitter\n");
    printf("====================================================================\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 9) {
        printf("Entrez votre choix : ");
        scanf("%d", &choice);
    }
    fflush(stdin);
    return choice;
}

void safeScanf(char* format, int* var) {
    if (format == "date") {
        int result = scanf("%d/%d/%d", &var[0], &var[1], &var[2]);
        while (result != 3) {
            printf("Entrez une date valide (jj/mm/aaaa) : ");
            result = scanf("%d/%d/%d", &var[0], &var[1], &var[2]);
        }
    }
    else if (format == "time") {
        int result = scanf("%dh%d", &var[0], &var[1]);
        while (result != 2) {
            printf("Entrez une heure valide (HHhMM) : ");
            result = scanf("%dh%d", &var[0], &var[1]);
        }
    }
}

void saveAgenda(Agenda* agenda) {
    // save agenda to csv format in a file
    FILE *file = fopen("agenda.csv", "w");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier agenda.csv\n");
        return;
    }
    fprintf(file, "Nom;Prenom;Date;Heure;Durée;Nom du rendez-vous\n");
    AgendaEntry *entry = agenda->entries[0];
    while (entry != NULL) {
        EventList *event = entry->events;
        while (event != NULL) {
            fprintf(file, "%s;%s;%d/%d/%d;%dh%d;%dh%d;%s\n", entry->contact->surname, entry->contact->name, event->value->date.day, event->value->date.month, event->value->date.year, event->value->time.hour, event->value->time.minute, event->value->duration.hour, event->value->duration.minute, event->value->name);
            event = event->next;
        }
        entry = entry->nexts[0];
    }
    fclose(file);
    printf("Agenda sauvegardé !\n");
}

Agenda* loadAgenda() {
    // load agenda from csv file agenda.csv and return it
    FILE *file = fopen("agenda.csv", "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier agenda.csv\n");
        return NULL;
    }
    Agenda *agenda = create_agenda(4);
    char line[1024];
    fgets(line, 1024, file);
    while (fgets(line, 1024, file) != NULL) {
        char *surname = strtok(line, ";");
        char *name = strtok(NULL, ";");
        char *date = strtok(NULL, ";");
        char *hour = strtok(NULL, ";");
        char *duration = strtok(NULL, ";");
        char *event_name = strtok(NULL, "\n");
        int date_int[3];
        int hour_int[2];
        int duration_int[2];
        char *name_copy = malloc(sizeof(char) * strlen(name));
        strcpy(name_copy, name);
        char *surname_copy = malloc(sizeof(char) * strlen(surname));
        strcpy(surname_copy, surname);
        char *event_name_copy = malloc(sizeof(char) * strlen(event_name));
        strcpy(event_name_copy, event_name);
        sscanf(date, "%d/%d/%d", &date_int[0], &date_int[1], &date_int[2]);
        sscanf(hour, "%dh%d", &hour_int[0], &hour_int[1]);
        sscanf(duration, "%dh%d", &duration_int[0], &duration_int[1]);
        Event *event = create_event(date_int[0], date_int[1], date_int[2], hour_int[0], hour_int[1], duration_int[0], duration_int[1], event_name_copy);
        char* contact_id = malloc(sizeof(char) * (strlen(name) + strlen(surname) + 1));
        sprintf(contact_id, "%s_%s", surname_copy, name_copy);
        AgendaEntry *entry = search_entry_contact(agenda, contact_id);
        if (entry == NULL) {
            Contact *contact = create_contact(name_copy, surname_copy);
            printf("Ajout de %s à l'agenda\n", contact->id);
            entry = create_agenda_entry(contact);
            add_entry_to_agenda(agenda, entry);
        }
        if (entry->events == NULL) {
            entry->events = create_event_list(event);
        }
        else {
            EventList *current = entry->events;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = create_event_list(event);
        }
    }
    return agenda;
}
