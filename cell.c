//
// Created by IamaU on 16/11/2023.
//

// cell.c
#include <stdlib.h>
#include "cell.h"

t_d_cell *create_cell(int value) {
    t_d_cell *new_cell = (t_d_cell *)malloc(sizeof(t_d_cell));
    if (new_cell != NULL) {
        new_cell->value = value;
        new_cell->next = NULL;
    }
    return new_cell;
}
