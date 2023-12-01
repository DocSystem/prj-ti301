//
// Created by IamaU on 01/12/2023.
//
#include "time_comparison.h"

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
    for(int i = 1; i < size; i++){
        cell_level = tab[i] + 1;
        insert_cell(L, create_cell(i,cell_level));
    }
    return L;
}