// main.c
#include "time_comparison.h"

int main() {
    /*
    //Test part 1:

    t_d_cell * test_cell_1= create_cell(21,1);
    t_d_cell * test_cell_2 = create_cell(7,3);
    t_d_cell * test_cell_3 = create_cell(14,1);

    t_d_list * test_list = create_list(5);



    insert_cell(test_list,test_cell_1);
    insert_cell(test_list,test_cell_2);
    insert_cell(test_list,test_cell_3);

    display_every_list(test_list);
     */

    //Test part 2:
    int * tab = generate_array(4);
    int size = pow(2,3);
    for(int i = 0; i < size; i++){
        printf("%d ",tab[i]);
    }

    int puissance = pow(2,3) - 1;
    printf("\n%d",puissance);
    /*
    t_d_list * L = create_time_comparison_list(3);
    display_every_list(L);
     */
    return 0;
}
