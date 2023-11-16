//
// Created by IamaU on 16/11/2023.
//

#ifndef LIST_H
#define LIST_H

#include "cell.h"

typedef struct s_d_list
{
    t_d_cell * level;
} t_d_list;

t_d_list * create_list(int lvl);

#endif
