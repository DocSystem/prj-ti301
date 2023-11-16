//
// Created by IamaU on 16/11/2023.
//

// list.h
#ifndef LIST_H
#define LIST_H

#include "cell.h"

typedef struct s_d_list {
    t_d_cell *head;
} t_d_list;

t_d_list *create_list();

void insert_cell(t_d_list *list, int value);

void display_list(t_d_list *list);

#endif
