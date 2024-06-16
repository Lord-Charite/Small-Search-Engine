/*
 * delete.h
 * Header file for delete functions for student data management.
 */

#ifndef DELETE_H
#define DELETE_H

#include "student.h"

// Function prototypes for delete operations
void deleteAverage(int *N, int *sort_studentdata, student_t *studentdata);
void deleteTest1(int *N, int *sort_studentdata, student_t *studentdata);
void delete_data(int *N, int *sort_array, student_t *studentdata);

#endif // DELETE_H
