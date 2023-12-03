//
// Created by IamaU on 01/12/2023.
//
#include "time_comparison.h"

int int_pow(int x, int y){
    int tmp = x;
    if(y == 1){
        return 1;
    }
    for(int i = 0; i < y-1; i++){
        x = x * tmp;
    }
    return x;
}

int * generate_array(int n){
    int size = pow(2,n) - 1;
    int * tab = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        tab[i] = 0;
    }

    int j = 2;
    while(j <= size){
        for(int i = 0; i < size; i++){
            if((i+1) % j == 0){
                tab[i] ++;
            }

        }
        j = j * 2;
    }
    return tab;
}

t_d_list * create_time_comparison_list(int n){
    int * tab = generate_array(n);
    t_d_list * L = create_list(n);
    int size = pow(2,n) - 1;
    int cell_level;
    for(int i = 0; i < size; i++){
        cell_level = tab[i] + 1;
        insert_cell(L, create_cell(i+1,cell_level));
    }
    return L;
}

int classic_seek_value(t_d_list * L, int n){
    t_d_cell * tmp = L->level[0];
    int i = 1;
    while(tmp != NULL){
        if(tmp->value == n){
            return i;
        }
        tmp = tmp->level[0];
        i++;
    }
    return 0;
}

int advanced_seek_value(t_d_list *L, int n){
    int i = 1;
    int lvl = L->size - 1;
    t_d_cell * tmp = L->level[lvl];
    t_d_cell * pretmp = tmp;

    while(tmp != NULL || lvl != 0){
        if(tmp->value == n){
            return i;
        }
        pretmp = tmp;
        tmp = tmp->level[lvl];
        i = i + pow(2,lvl);
        if(tmp == NULL || tmp->value > n){
            tmp = pretmp->level[lvl-1];
            pretmp = tmp;
            lvl;
        }

    }
    return 0;
}