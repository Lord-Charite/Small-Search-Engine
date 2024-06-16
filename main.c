/*
 * main.c
 * Main file that includes headers and calls the functions for student data management.
 */

#include <stdio.h>
#include "student.h"
#include "sort.h"
#include "search.h"
#include "delete.h"

int main(void){
    FILE *file; // File declaration
    int sort_array[50]; 
    int i = 0; 
    int data = 0; 
    student_t studentdata[50]; // Struct array containing the data
    char junkc;
    char option;
    char filename[50]; 

    // Asking user for file name
    printf("- Enter [a] to give a file name\n- enter any char or key to use default file\n- Your input: "); 
    scanf("%c", &option);
    scanf ("%c", &junkc);

    if(option == 'a'){ 
        printf("Enter the name of the file: ");
        scanf("%s", filename); 
        file = fopen(filename, "r");
        if(file == NULL){
            printf("Invalid File!\n");
        } else {
            while (!feof(file)){
                fscanf(file, "%[^,],%[^,],%f,%d,%d,%d",
                    studentdata[i].firstName, 
                    studentdata[i].lastName,
                    &studentdata[i].test1, 
                    &studentdata[i].test2, 
                    &studentdata[i].test3, 
                    &studentdata[i].average);
                i++;
                data++; 
            }
            fclose(file);
        }
    } else {
        file = fopen("StudentInfo.txt", "r"); 
        if(file == NULL){
            printf("INVALID FILE!");
        } else {
            while (!feof(file)){
                fscanf(file, "%[^,],%[^,],%f,%d,%d,%d", 
                    studentdata[i].firstName, 
                    studentdata[i].lastName,
                    &studentdata[i].test1, 
                    &studentdata[i].test2, 
                    &studentdata[i].test3, 
                    &studentdata[i].average);
                i++;
                data++;
            }
            fclose(file);
        }
    }
   
    for(i = 0; i < 50; i++){
        sort_array[i] = i;
    } 
    mainMenu(&data, sort_array, studentdata);
}

// Function to display main menu and call appropriate functions
void mainMenu(int *N, int *sort_array, student_t *studentdata){
    char entry, again, junkc; 
    do { 
        printf("\nTo visualize data choose from options below:\n\n" 
            "Dis[p]lay\n" 
            "S[o]rt\n" 
            "Sea[r]ch\n" 
            "[a]dd\n" 
            "Del[e]te\n"
            "Sa[v]e\n"); 
        printf("\nTo proceed, Enter(p, o, r, a, e, v) [p]: "); 
        scanf(" %c", &entry); 
        printf("You selected option %c.\n", entry); 
        if(entry == 'p'){ 
            display(N, sort_array, studentdata); 
        } else if (entry == 'o'){ 
            sort(N, sort_array, studentdata); 
        } else if(entry == 'r'){ 
            search(N, sort_array, studentdata);
        } else if(entry == 'a'){ 
            add(N, sort_array, studentdata);
        } else if(entry == 'e'){ 
            delete_data(N, sort_array, studentdata); 
        } else if(entry == 'v'){ 
            save(N, sort_array, studentdata); 
        } else { 
            printf("Invalid option, try again!\n"); 
        }
        printf("\nAgain? Enter [q] to quit or any other alphabet to continue: "); 
        scanf(" %c", &again);
    } while(again != 'q'); 
    printf("\n\nYou've opted to stop visualizing the data!!\n");  
}
