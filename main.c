// main.c
#include "time_comparison.h"

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

    t_d_list * L = create_time_comparison_list(3);
    advanced_display_list(L);
    display_every_list(L);
    int i = advanced_seek_value(L,6);
    printf("%d",i);

    return 0;
}
