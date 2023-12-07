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
    if(L->size == 1){
        return classic_seek_value(L, n);
    }
    else {
        int pretmp_lvl = L->size - 2;
        int i = pow(2, pretmp_lvl+1);

        t_d_cell *pretmp = L->level[pretmp_lvl];
        t_d_cell *tmp = L->level[pretmp_lvl+1];

       while(tmp->value >= n && tmp == L->level[pretmp_lvl+1] && pretmp_lvl > 0){
           if(tmp->value == n){
               return i;
           }
           else{
               pretmp_lvl--;
               i = pow(2, pretmp_lvl+1);
               pretmp = L->level[pretmp_lvl];
               tmp = L->level[pretmp_lvl+1];
           }
       }
       if(pretmp_lvl == 0){
           i = i - pow(2, pretmp_lvl);
           while(pretmp != NULL){
               if(pretmp->value == n){
                   return i;
               }
               pretmp = pretmp->level[0];
               i++;
           }
           return 0; //everything is supposed ok here
       }
       else{
           while(pretmp_lvl > 0){
               if(tmp == NULL){
                   i = i - pow(2, pretmp_lvl);
                   tmp = pretmp->level[pretmp_lvl];
                   pretmp_lvl--;

               }
               else{
                   if(tmp->value <= n){
                       if(tmp->value == n){
                           return i;
                       }
                       else{
                           pretmp = tmp;
                           tmp = tmp->level[pretmp_lvl + 1];
                           i = i + pow(2, pretmp_lvl+1);
                       }
                   }
                   else{
                       i = i - pow(2, pretmp_lvl);
                       tmp = pretmp->level[pretmp_lvl];
                       pretmp_lvl--;
                   }
               }
           }
           i = i - pow(2, pretmp_lvl+1);
           while(pretmp != NULL){
               if(pretmp->value == n){
                   return i;
               }
               pretmp = pretmp->level[0];
               i++;
           }
           return 0;
       }

    }
}