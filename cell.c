//
// Created by IamaU on 16/11/2023.
//

#include <stdlib.h>
#include "cell.h"

t_d_cell * create_cell(int value, int lvl){
    t_d_cell cell;
    cell.size = lvl;
    cell.level = (t_d_cell * *)malloc(lvl * sizeof(t_d_cell*)); //creation of a dynamic array of lvl levels
    cell.value = value;
    for(int i = 0; i < lvl; i++){
        cell.level = NULL;
    }
    return &cell;
}

BOOL insert_cell_fist(t_d_cell * list, t_d_cell * cell){
    if(list->size < cell->size){
        return FALSE;
    }
    else{
        for(int i = 0; i < list->size; i++){
             list->level[i] = cell;
        }
    }
    return TRUE;
}
