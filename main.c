// main.c
#include "time_comparison.h"
#include "timer.h"

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

    t_d_list  * L = NULL;
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



    return 0;
}
