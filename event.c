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

void display_event(Event* event) {
    printf("%s: %d/%d/%d %d:%d for %d:%d\n", event->name, event->date.day, event->date.month, event->date.year, event->time.hour, event->time.minute, event->duration.hour, event->duration.minute);
}
