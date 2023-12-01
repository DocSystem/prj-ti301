// main.c
#include "list.h"

int main() {

    t_d_cell * test_cell_1= create_cell(21,1);
    t_d_cell * test_cell_2 = create_cell(7,3);
    t_d_cell * test_cell_3 = create_cell(14,1);

    t_d_list * test_list = create_list(5);



    insert_cell(test_list,test_cell_1);
    insert_cell(test_list,test_cell_2);
    insert_cell(test_list,test_cell_3);

    display_every_list(test_list);
    return 0;
}
