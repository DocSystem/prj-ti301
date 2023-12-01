//
// Created by IamaU on 16/11/2023.
//

// list.c
#include "list.h"

t_d_list * create_list(int lvl){
    static t_d_list L; //static to avoid stack memory issue
    L.size = lvl;
    L.level = (t_d_cell * *)malloc(lvl * sizeof(t_d_cell *)); //creation of a dynamic array of lvl levels
    for(int i = 0; i < lvl; i++){
        L.level[i] = NULL;
    }
    return &L;
}

BOOL insert_cell_first(t_d_list * list, t_d_cell * cell){
    if (list->size < cell->size){
        return FALSE;
    }
    else{
        for(int i = 0; i < cell->size; i++){
            if(list->level[i] != NULL) {
                cell->level[i] = list->level[i];
                list->level[i] = cell;
            }
            else{
                list->level[i] = cell;
            }
        }
    } // If the list isn't empty, the heads are attached to the cell according the size of cell
    return TRUE;
}

void display_list(t_d_list * list, int lvl_number){
    printf("[list head_%d @-]-->", lvl_number);
    if(list->level[lvl_number] != NULL){
        t_d_cell * tmp = list->level[lvl_number];
        while(tmp != NULL){
            printf("[ %d|@-]-->", tmp->value);
            tmp = tmp->level[lvl_number];
        }
    }
    printf("NULL");
}

void display_every_list(t_d_list * list){
    for(int i = 0; i < list->size; i++){
        display_list(list,i);
        printf("\n");
    }
}

BOOL insert_cell(t_d_list *list, t_d_cell *cell) {
    if (list->size < cell->size) {
        return FALSE;
    } else {
        for (int i = 0; i < cell->size; i++) {
            t_d_cell *pretmp = NULL;
            t_d_cell *tmp = list->level[i];

            while (tmp != NULL && tmp->value < cell->value) {
                pretmp = tmp;
                tmp = tmp->level[i];
            }

            if (pretmp == NULL) {
                // Insert at the beginning of the list
                cell->level[i] = list->level[i];
                list->level[i] = cell;
            } else {
                pretmp->level[i] = cell;
                cell->level[i] = tmp;
            }
        }
    }
    return TRUE;
}