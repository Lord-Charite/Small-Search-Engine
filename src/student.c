/*
 * student.c
 * Implementation of basic operations for student data management.
 */

#include <stdio.h>
#include <string.h>
#include "student.h"

// Function to display student data
void display(int *N, int *sort_array, student_t *studentdata){
    int i;
    printf("\n Your Current data is:\n\n");
    printf("\n Firstname %5s Lastname %5s Test1 %5s Test2 %5s Test3 %5s Average\n\n", "", "", "", "", "");
    for(i = 0; i < *N; i++){
        printf("%-16s %-14s %9.2f %9d %9d %12d\n", 
               studentdata[sort_array[i]].firstName,  
               studentdata[sort_array[i]].lastName, 
               studentdata[sort_array[i]].test1, 
               studentdata[sort_array[i]].test2, 
               studentdata[sort_array[i]].test3, 
               studentdata[sort_array[i]].average);
    }
    printf("\n");
}

// Function to save student data to file
void save(int *N, int *sort_array, student_t *studentdata){
    FILE* filesave;
    char filename[50];
    int i;
    printf("Enter the name of the file with .txt extension: ");
    scanf("%s", filename);
    filesave = fopen(filename, "w");
    if(filesave == NULL){
        printf("Error opening file for writing!\n");
        return;
    }
    for(i = 0; i < *N; i++){
        fprintf(filesave, "%s,%s,%.2f,%d,%d,%d\n", 
                studentdata[sort_array[i]].firstName,  
                studentdata[sort_array[i]].lastName, 
                studentdata[sort_array[i]].test1, 
                studentdata[sort_array[i]].test2, 
                studentdata[sort_array[i]].test3, 
                studentdata[sort_array[i]].average);
    }
    fclose(filesave);
}

// Function to add a new student
void add(int *N, int *sort_array, student_t *studentdata){
    printf("You've chosen to add a new record. Follow instructions below to proceed\n\n");
    printf("- First Name: "); 
    scanf("%s", studentdata[*N].firstName);
    printf("- Last Name: "); 
    scanf("%s", studentdata[*N].lastName);
    printf("- Test1 (float): "); 
    scanf("%f", &studentdata[*N].test1);
    printf("- Test2 (integer): "); 
    scanf("%d", &studentdata[*N].test2); 
    printf("- Test3 (integer): "); 
    scanf("%d", &studentdata[*N].test3); 
    printf("- Average (integer): "); 
    scanf("%d", &studentdata[*N].average);
    (*N)++;
    display(N, sort_array, studentdata);
}
