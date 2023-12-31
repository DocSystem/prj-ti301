//
// Created by Antoine Souben-Fink on 06/12/2023.
//

#ifndef PRJ_TI301_EVENT_H
#define PRJ_TI301_EVENT_H

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    Date date;
    Time time;
    Time duration;
    char *name;
} Event;

typedef struct EventCell {
    Event *value;
    struct EventCell *next;
} EventCell;

Event *create_event(int day, int month, int year, int start_hour, int start_minute, int duration_hour, int duration_minute, char *name);

EventCell *create_event_cell(Event* event);

void display_event(Event *event);

#endif //PRJ_TI301_EVENT_H
