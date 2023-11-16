//
// Created by IamaU on 16/11/2023.
//

#include <stdlib.h>
#include "cell.h"

t_d_cell * create_cell(int value, int lvl){
    t_d_cell cell;
    cell.level = (t_d_cell *)malloc(lvl * sizeof(t_d_cell)); //creation of a dynamic array of lvl levels
    cell.value = value;
    return &cell;
}
