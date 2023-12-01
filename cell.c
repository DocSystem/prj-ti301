//
// Created by IamaU on 16/11/2023.
//
#include "cell.h"

t_d_cell * create_cell(int value, int lvl){
    t_d_cell * cell = (t_d_cell * )malloc(sizeof(t_d_cell)); //static to avoid stack memory issue
    cell->level = (t_d_cell * *)malloc(lvl * sizeof(t_d_cell *)); //creation of a dynamic array of lvl levels
    for(int i = 0; i < lvl; i++){
        cell->level[i] = NULL;
    }
    cell->value = value;
    cell->size = lvl;
    return cell;
}
