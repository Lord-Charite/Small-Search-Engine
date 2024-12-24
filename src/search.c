/*
 * search.c
 * Implementation of search functions for student data management.
 */

#include <stdio.h>
#include "search.h"

// Function to search students by average
void searchAverage(int *N, int *sort_studentdata, student_t *studentdata){
    int num, i, foundData = 0; 
    printf("Enter the average grade you are looking: "); 
    scanf("%d", &num); 
    for (i = 0; i < *N; i++){
        if (studentdata[i].average == num){
            foundData++; 
            printf("%-16s %-14s %9.2f %9d %9d %12d\n", 
                   studentdata[i].firstName,  
                   studentdata[i].lastName, 
                   studentdata[i].test1, 
                   studentdata[i].test2, 
                   studentdata[i].test3, 
                   studentdata[i].average);
        }
    }
    if(foundData == 0){
        printf("No data was found!\n");
    }
}

// Function to search students by test1 score
void searchTest1(int *N, int *sort_studentdata, student_t *studentdata){
    int i, foundData = 0; 
    float num;
    printf("Enter the test1 (a float data type) score you are looking: "); 
    scanf("%f", &num); 
    for (i = 0; i < *N; i++){
        if (studentdata[i].test1 == num){
            foundData++; 
            printf("%-16s %-14s %9.2f %9d %9d %12d\n", 
                   studentdata[i].firstName,  
                   studentdata[i].lastName, 
                   studentdata[i].test1, 
                   studentdata[i].test2, 
                   studentdata[i].test3, 
                   studentdata[i].average);
        }
    }
    if(foundData == 0){
        printf("No data was found!\n");
    }
}

// Function to search students by selected criteria
void search(int *N, int *sort_array, student_t *studentdata){
    char userOption; 
    printf("\n\n Choose option to search your data\n");
    printf("\n Choose:\n- [a]verage\n- [t]est1\n");
    printf("Your option:");
    scanf(" %c", &userOption);
    if(userOption == 't'){
        searchTest1(N, sort_array, studentdata); 
    } else if(userOption == 'a'){
        searchAverage(N, sort_array, studentdata); 
    }
}
