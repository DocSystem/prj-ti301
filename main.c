// main.c
#include "agenda.h"
#include "list.h"
#include "time_comparison.h"
#include "timer.h"

int showMenu() {
    int choice;
    printf("1. Rechercher un contact\n");
    printf("2. Afficher les rendez-vous d'un contact\n");
    printf("3. Créer un contact\n");
    printf("4. Créer un rendez-vous pour un contact\n");
    printf("5. Supprimer un rendez-vous\n");
    printf("6. Sauvegarder le fichier de tous les rendez-vous\n");
    printf("7. Charger un fichier de rendez-vous\n");
    printf("8. Fournir les temps de calcul pour une insertion de nouveau contact\n");
    printf("9. Quitter\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 9) {
        printf("Enter your choice : ");
        scanf("%d", &choice);
    }
    return choice;
}

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

    Contact *contact1 = create_contact("Antoine", "Souben-Fink");
    AgendaEntry *entry1 = create_agenda_entry(contact1);
    add_entry_to_agenda(agenda, entry1);

    Contact *contact2 = create_contact("Yoan", "Souben-Fink");
    AgendaEntry *entry2 = create_agenda_entry(contact2);
    add_entry_to_agenda(agenda, entry2);

    Contact *contact3 = create_contact("Antoine", "Saaben-Fink");
    AgendaEntry *entry3 = create_agenda_entry(contact3);
    add_entry_to_agenda(agenda, entry3);

    Contact *contact4 = create_contact("Paul", "Zanolin");
    AgendaEntry *entry4 = create_agenda_entry(contact4);
    add_entry_to_agenda(agenda, entry4);

    display_agenda(agenda);

    /*while (isRunning) {
        int choice = showMenu();

        switch (choice) {
            case 1:
                //todo
                break;
            case 2:
                //todo
                break;
            case 3:
                //todo
                break;
            case 4:
                //todo
                break;
            case 5:
                //todo
                break;
            case 6:
                //todo
                break;
            case 7:
                //todo
                break;
            case 8:
                //todo
                break;
            case 9:
                printf("Bye bye !");
                isRunning = 0;
                break;
        }
    }*/

    return 0;
}
