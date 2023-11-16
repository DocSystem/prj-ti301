//
// Created by IamaU on 16/11/2023.
//

// list.c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_d_list *create_list() {
    t_d_list *new_list = (t_d_list *)malloc(sizeof(t_d_list));
    if (new_list != NULL) {
        new_list->head = NULL;
    }
    return new_list;
}

void insert_cell(t_d_list *list, int value) {
    t_d_cell *new_cell = create_cell(value);
    if (new_cell != NULL) {
        new_cell->next = list->head;
        list->head = new_cell;
    }
}

void display_list(t_d_list *list) {
    t_d_cell *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}
