/*
 * student.h
 * Header file defining the student_t struct and basic function prototypes.
 */

#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char firstName[50];
    char lastName[50];
    float test1;
    int test2;
    int test3;
    int average;
} student_t;

void mainMenu(int *N, int *sort_array, student_t *studentdata);
void save(int *N, int *sort_array, student_t *studentdata);
void add(int *N, int *sort_array, student_t *studentdata);
void display(int *N, int *sort_array, student_t *studentdata);

#endif // STUDENT_H
