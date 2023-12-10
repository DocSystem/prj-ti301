// main.c
#include <string.h>
#include "agenda.h"
#include "list.h"
#include "time_comparison.h"
#include "timer.h"
#include "utils.h"


int main() {

    //Test part 1:
    /*
    t_d_cell * test_cell_1= create_cell(21,1);
    t_d_cell * test_cell_2 = create_cell(7,3);
    t_d_cell * test_cell_3 = create_cell(14,1);
    t_d_cell * test_cell_4 = create_cell(28,4);
    t_d_list * test_list = create_list(5);



    insert_cell(test_list,test_cell_1);
    insert_cell(test_list,test_cell_2);
    insert_cell(test_list,test_cell_3);
    insert_cell(test_list,test_cell_4);

    display_every_list(test_list);
    */

    //Test part 2:
    /*
    int n = 3, i ;
    t_d_list * L = create_time_comparison_list(n);
    advanced_display_list(L);

    for(int a = 0; a < pow(2,n); a++){
        i = advanced_seek_value(L,a);
        printf("Indice finale + 1 = %d\n",i);
    }
    */

    //Time comparison test:

    /* t_d_list  * L = NULL;
    int n = 10, j = 1;
    int search_value;


    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level;
    char *time_lvl0;
    char *time_all_levels;

    while(j <= n){
        srand(1);
        L = create_time_comparison_list(j);
        printf("Parcours du niveau d'une liste de taille N = %d\n",j);
        int number_of_value = pow(2,j);

        startTimer();

        for(int i = 0; i < 10000000; i++){
            search_value = rand() % number_of_value;
            classic_seek_value(L, search_value);
        }
        stopTimer();

        time_lvl0 = getTimeAsString(); // fonction du module timer

        startTimer();

        for(int i = 0; i < 10000000; i++){
            search_value = rand() % number_of_value;
            advanced_seek_value(L,search_value);
        }

        stopTimer();

        time_all_levels = getTimeAsString();
        fprintf(log_file,format,level,time_lvl0, time_all_levels);

        j++;
    }
    fclose(log_file);


    /* t_d_list * L = create_time_comparison_list(4);
    display_every_list(L);
    int i = advanced_seek_value(L,6);
    printf("%d",i); */

    // Part 3

    int isRunning = 1;

    Agenda *agenda = create_agenda(4);

    /* Contact *contact1 = create_contact("Antoine", "Souben-Fink");
    Contact *contact2 = create_contact("Yoan", "Souben-Fink");
    Contact *contact3 = create_contact("Antoine", "Saaben-Fink");
    Contact *contact4 = create_contact("Paul", "Zanolin");

    AgendaEntry *entry1 = create_agenda_entry(contact1);
    AgendaEntry *entry2 = create_agenda_entry(contact2);
    AgendaEntry *entry3 = create_agenda_entry(contact3);
    AgendaEntry *entry4 = create_agenda_entry(contact4);

    add_entry_to_agenda(agenda, entry1);
    add_entry_to_agenda(agenda, entry2);
    add_entry_to_agenda(agenda, entry3);
    add_entry_to_agenda(agenda, entry4);

    display_agenda(agenda); */

    while (isRunning) {
        int choice = showMenu();

        switch (choice) {
            case 1: {
                char* id_beginning = malloc(sizeof(char) * 100);
                printf("Entrez un nom : ");
                fgets(id_beginning, 100, stdin);
                id_beginning[strlen(id_beginning) - 1] = '\0';
                AgendaEntry *entry = search_entry_contact(agenda, id_beginning);
                if (entry != NULL) {
                    printf("Contact trouvé : ");
                    display_contact(entry->contact);
                } else {
                    printf("Contact introuvable !\n");
                }
                printf("\n");
                break;
            }
            case 2: {
                char* id_beginning = malloc(sizeof(char) * 100);
                printf("Entrez le nom du contact : ");
                fgets(id_beginning, 100, stdin);
                id_beginning[strlen(id_beginning) - 1] = '\0';
                AgendaEntry *entry = search_entry_contact(agenda, id_beginning);
                if (entry != NULL) {
                    printf("Contact trouvé : ");
                    display_contact(entry->contact);
                    printf("Rendez-vous : \n");
                    EventList *event = entry->events;
                    while (event != NULL) {
                        printf("\t\t- ");
                        display_event(event->value);
                        event = event->next;
                    }
                } else {
                    printf("Contact introuvable !\n");
                }
                printf("\n");
                break;
            }
            case 3: {
                Contact *new_contact = scan_new_contact();
                AgendaEntry *new_entry = create_agenda_entry(new_contact);
                add_entry_to_agenda(agenda, new_entry);
                printf("\n");
                break;
            }
            case 4: {
                printf("Entrez le nom du contact : ");
                char* id_beginning = malloc(sizeof(char) * 100);
                fgets(id_beginning, 100, stdin);
                id_beginning[strlen(id_beginning) - 1] = '\0';
                AgendaEntry *entry = search_entry_contact(agenda, id_beginning);
                if (entry == NULL) {
                    printf("Contact introuvable !\n");
                    Contact *new_contact = scan_new_contact();
                    entry = create_agenda_entry(new_contact);
                    add_entry_to_agenda(agenda, entry);
                    display_contact(entry->contact);
                }
                printf("Ajout d'un évènement pour %s %s\n", entry->contact->name, entry->contact->surname);
                printf("Entrez le nom de l'évènement : ");
                char* event_name = malloc(sizeof(char) * 100);
                fgets(event_name, 100, stdin);
                event_name[strlen(event_name) - 1] = '\0';
                printf("Entrez la date (JJ/MM/AAAA) : ");
                int date[3];
                safeScanf("date", date);
                printf("Entrez l'heure de début (HHhMM) : ");
                int start[2];
                safeScanf("time", start);
                printf("Entrez la durée (HHhMM) : ");
                int duration[2];
                safeScanf("time", duration);
                Event *event = create_event(date[0], date[1], date[2], start[0], start[1], duration[0], duration[1], event_name);
                EventList *event_list = create_event_list(event);
                EventList *current = entry->events;
                if (current == NULL) {
                    entry->events = event_list;
                }
                else {
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = event_list;
                }
                break;
            }
            case 5: {
                printf("Entrez le nom du contact : ");
                char* id_beginning = malloc(sizeof(char) * 100);
                fgets(id_beginning, 100, stdin);
                id_beginning[strlen(id_beginning) - 1] = '\0';
                AgendaEntry *entry = search_entry_contact(agenda, id_beginning);
                if (entry == NULL) {
                    printf("Contact introuvable !\n");
                    break;
                }
                printf("Entrez le nom de l'évènement : ");
                char* event_name = malloc(sizeof(char) * 100);
                fgets(event_name, 100, stdin);
                event_name[strlen(event_name) - 1] = '\0';
                EventList *current = entry->events;
                EventList *previous = NULL;
                while (current != NULL) {
                    if (strcmp(current->value->name, event_name) == 0) {
                        if (previous == NULL) {
                            entry->events = current->next;
                        } else {
                            previous->next = current->next;
                        }
                        free(current);
                        printf("Évènement supprimé !\n");
                        break;
                    }
                    previous = current;
                    current = current->next;
                }
                if (current == NULL) {
                    printf("Évènement introuvable !\n");
                }
                break;
            }
            case 6: {
                saveAgenda(agenda);
                printf("\n");
                break;
            }
            case 7: {
                Agenda *loadedAgenda = loadAgenda();
                if (loadedAgenda != NULL) {
                    agenda = loadedAgenda;
                    printf("Agenda chargé avec succès");
                }
                printf("\n");
                break;
            }
            case 8: {
                Contact *new_contact = scan_new_contact();
                AgendaEntry *new_entry = create_agenda_entry(new_contact);
                startTimer();
                add_entry_to_agenda(agenda, new_entry);
                printf("Temps d'ajout : %s\n", getTimeAsString());
                stopTimer();
                printf("\n");
                break;
            }
            case 9:
                printf("Bye bye !");
                isRunning = 0;
                break;
            default: break;
        }
    }
    return 0;
}
