//
// Created by IamaU on 16/11/2023.
//

// cell.h
#ifndef CELL_H
#define CELL_H

typedef struct s_d_cell
{
    int value;
    struct s_d_cell * level; //tableau dynamique de pointeur
} t_d_cell;

t_d_cell * create_cell(int value, int lvl);

#endif
