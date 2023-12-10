//
// Created by Antoine Souben-Fink on 05/12/2023.
//

#ifndef PRJ_TI301_CONTACT_H
#define PRJ_TI301_CONTACT_H

typedef struct {
    char *name;
    char *surname;
    char *id;
} Contact;

Contact *create_contact(char *first_name, char *last_name);

Contact *scan_new_contact();

void display_contact(Contact *contact);

#endif //PRJ_TI301_CONTACT_H
