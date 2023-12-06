//
// Created by IamaU on 16/11/2023.
//

#ifndef LIST_H
#define LIST_H

#include "cell.h"

typedef struct s_d_list
{
    int size;
    t_d_cell * *  level;
} t_d_list;

t_d_list * create_list(int lvl);

BOOL insert_cell_first(t_d_list * list, t_d_cell * cell);

void display_list(t_d_list * list, int lvl_number);

void display_every_list(t_d_list * list);

void advanced_display_list(t_d_list * list);

BOOL insert_cell(t_d_list * list, t_d_cell * cell);
#endif
