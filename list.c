//
// Created by IamaU on 16/11/2023.
//

// list.c
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_d_list * create_list(int lvl){
    t_d_list L;
    L.size = lvl;
    L.level = (t_d_cell * *)malloc(lvl * sizeof(t_d_cell *)); //creation of a dynamic array of lvl levels
    for(int i = 0; i < lvl; i++){
        L.level = NULL;
    }
    return &L;
}

void display_list(t_d_list * list){

}

