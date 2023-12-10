//
// Created by Antoine Souben-Fink on 05/12/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

Contact *create_contact(char *first_name, char *last_name) {
    Contact *contact = malloc(sizeof(Contact));
    contact->name = first_name;
    contact->surname = last_name;
    char *id = malloc(sizeof(char) * (strlen(first_name) + strlen(last_name) + 1));
    sprintf(id, "%s_%s", last_name, first_name);
    for (int i = 0; i < strlen(id); ++i) {id[i] = tolower(id[i]);}
    contact->id = id;
    return contact;
}

Contact *scan_new_contact() {
    char* first_name = malloc(sizeof(char) * 100);
    printf("Entrez le prénom : ");
    fgets(first_name, 100, stdin);
    first_name[strlen(first_name) - 1] = '\0';
    char* last_name = malloc(sizeof(char) * 100);
    printf("Entrez le nom de famille : ");
    fgets(last_name, 100, stdin);
    last_name[strlen(last_name) - 1] = '\0';
    return create_contact(first_name, last_name);
}

void display_contact(Contact *contact) {
    printf("%s %s\n", contact->name, contact->surname);
}
