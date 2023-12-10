//
// Created by Antoine Souben-Fink on 10/12/2023.
//

#ifndef UTILS_H
#define UTILS_H
#include "agenda.h"

int showMenu();

void safeScanf(char *format, int *var);

void saveAgenda(Agenda *agenda);

Agenda *loadAgenda();

#endif //UTILS_H
