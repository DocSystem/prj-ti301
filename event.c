//
// Created by Antoine Souben-Fink on 06/12/2023.
//

#include "event.h"

#include <stdio.h>
#include <stdlib.h>

Event* create_event(int day, int month, int year, int start_hour, int start_minute, int duration_hour, int duration_minute, char* name) {
    Event *event = malloc(sizeof(Event));
    event->date.day = day;
    event->date.month = month;
    event->date.year = year;
    event->time.hour = start_hour;
    event->time.minute = start_minute;
    event->duration.hour = duration_hour;
    event->duration.minute = duration_minute;
    event->name = name;
    return event;
}

EventList* create_event_list(Event* event) {
    EventList *list = malloc(sizeof(EventList));
    list->value = event;
    list->next = NULL;
    return list;
}

char* proper_display_int(int number) {
    char* value = malloc(sizeof(char) * 3);
    if (number < 10) {
        sprintf(value, "0%d", number);
    } else {
        sprintf(value, "%d", number);
    }
    return value;
}

void display_event(Event* event) {
    printf("%s: %s/%s/%s à %sh%s pendant %sh%s\n", event->name, proper_display_int(event->date.day), proper_display_int(event->date.month), proper_display_int(event->date.year), proper_display_int(event->time.hour), proper_display_int(event->time.minute), proper_display_int(event->duration.hour), proper_display_int(event->duration.minute));
}
