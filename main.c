// main.c
#include "list.h"

int main() {
    t_d_list *my_list = create_list();

    insert_cell(my_list, 5);
    insert_cell(my_list, 10);
    insert_cell(my_list, 3);

    display_list(my_list);

    return 0;
}
