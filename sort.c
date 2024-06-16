#ifndef SORT_H
#define SORT_H

#include "student.h"

// Function to sort students by average
void sortAverage(int *N, int *sort_array, student_t *studentdata){ 
    int i, j, userOption, swap;
    printf("Enter:\n[1] to sort in ascending order.\n[2] to sort in descending order\n");
    printf("Enter your input here: ");
    scanf("%d",  &userOption); 
    while (userOption < 1 || userOption > 2){ 
        printf("Invalid option, try again! "); 
        scanf("%d",  &userOption); 
    } 
    if (userOption == 1){ 
        for(i= 0; i < *N-1; i++){ 
            for(j = 0; j < *N-1; j++){ 
                if(studentdata[sort_array[j]].average > studentdata[sort_array[j+1]].average){
                    swap = sort_array[j]; 
                    sort_array[j] = sort_array[j+1];  
                    sort_array[j+1] = swap; 
                } 
            } 
        }   
    } else if (userOption == 2){ 
        for(i= 0; i < *N-1; i++){ 
            for(j = 0; j < *N-1; j++){ 
                if(studentdata[sort_array[j]].average < studentdata[sort_array[j+1]].average){
                    swap = sort_array[j]; 
                    sort_array[j] = sort_array[j+1];  
                    sort_array[j+1] = swap; 
                } 
            } 
        } 
    }
    display(N, sort_array, studentdata);
} 

// Function to sort students by first name
void sortFirstname(int *N, int *sort_array, student_t *studentdata){ 
    int i, j, userOption, swap; 
    printf("Enter:\n(1) to sort from 'z' to 'a'.\n(2) to sort from 'a' to 'z'.\n"); 
    scanf("%d", &userOption); 
    if(userOption == 1){ 
        for(i= 0; i < *N-1; i++){ 
            for(j = 0; j < *N-1; j++){ 
                if(strcmp(studentdata[sort_array[j]].firstName, studentdata[sort_array[j+1]].firstName) < 0){ 
                    swap = sort_array[j]; 
                    sort_array[j] = sort_array[j+1];  
                    sort_array[j+1] = swap; 
                } 
            } 
        } 
    } else if(userOption == 2){ 
        for(i= 0; i < *N-1; i++){ 
            for(j = 0; j < *N-1; j++){ 
                if(strcmp(studentdata[sort_array[j]].firstName, studentdata[sort_array[j+1]].firstName) > 0){
                    swap = sort_array[j]; 
                    sort_array[j] = sort_array[j+1];  
                    sort_array[j+1] = swap; 
                } 
            } 
        } 
    }
    display(N, sort_array, studentdata);
} 

// Function to sort students by selected criteria
void sort(int *N, int *sort_array, student_t *studentdata){ 
    char userOption; 
    printf("\n\n Choose option to sort your data\n");
    printf("\n Choose:\n- [a]verage\n- [f]irstname\n");
    printf("Input your choice here: ");
    scanf(" %c", &userOption);
    while (userOption != 'a' && userOption != 'f'){
        printf("Invalid Option. Try again: ");
        scanf(" %c", &userOption);
    }
    if(userOption == 'f'){
        sortFirstname(N, sort_array, studentdata); 
    } else if(userOption == 'a'){
        sortAverage(N, sort_array, studentdata); 
    }
}

#endif // SORT_H
