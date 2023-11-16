//
// Created by IamaU on 16/11/2023.
//

// cell.h
#ifndef CELL_H
#define CELL_H

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct s_d_cell
{
    int value;
    int size;
    struct s_d_cell * * level; //dynamic array of pointer
} t_d_cell;

t_d_cell * create_cell(int value, int lvl);

int count_level()

BOOL insert_cell_fist(t_d_cell * list, t_d_cell * cell);

#endif
