/*
 * delete.c
 * Implementation of delete functions for student data management.
 */

#include <stdio.h>
#include "delete.h"

// Function to delete student data by average
void deleteAverage(int *N, int *sort_studentdata, student_t *studentdata){
    int i, foundData = 0, num, option, j;
    printf("Enter the average grade you wish to delete: "); 
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
    } else if(foundData == 1){
        for(i = 0; i < *N; i++){
            if(studentdata[i].average == num){
                for(j = i; j < *N; j++){
                    studentdata[j] = studentdata[j+1];
                }
            }
        }
    } else {
        printf("To delete the above data enter \"1\", if not, enter \"0\": ");
        scanf("%d", &option);
        if(option == 1){
            for(i = 0; i < *N; i++){
                if(studentdata[i].average == num){
                    for(j = i; j < *N; j++){
                        studentdata[j] = studentdata[j+1];
                    }
                }
            }
        }
    }
    *N = *N - foundData;
}

// Function to delete student data by test1 score
void deleteTest1(int *N, int *sort_studentdata, student_t *studentdata){
    int i, foundData = 0, option, j;
    float num;
    printf("Enter the test1 score you wish to delete: "); 
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
    } else if(foundData == 1){
        for(i = 0; i < *N; i++){
            if(studentdata[i].test1 == num){
                for(j = i; j < *N; j++){
                    studentdata[j] = studentdata[j+1];
                }
            }
        }
    } else {
        printf("To delete the above data enter \"1\", if not, enter \"0\": ");
        scanf("%d", &option);
        if(option == 1){
            for(i = 0; i < *N; i++){
                if(studentdata[i].test1 == num){
                    for(j = i; j < *N; j++){
                        studentdata[j] = studentdata[j+1];
                    }
                }
            }
        }
    }
    *N = *N - foundData;
}

// Function to delete student data by selected criteria
void delete_data(int *N, int *sort_array, student_t *studentdata){
    char userOption; 
    printf("\n\n Choose option to delete your data\n");
    printf("\n Choose:\n- [a]verage\n- [t]est1\n");
    printf("Your option:");
    scanf(" %c", &userOption);
    if(userOption == 't'){
        deleteTest1(N, sort_array, studentdata); 
    } else if(userOption == 'a'){
        deleteAverage(N, sort_array, studentdata); 
    }
}
