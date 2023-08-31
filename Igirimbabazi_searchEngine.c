#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
void add (int *N, int *sort_array, student_t *studentdata);
void delete_data(int *N, int *sort_array, student_t *studentdata);
void deleteTest1(int *N, int *sort_studentdata, student_t *studentdata);
void deleteAverage(int *N, int *sort_studentdata, student_t *studentdata);
void searchTest1(int *N, int *sort_studentdata, student_t *studentdata);
void search (int *N, int *sort_studentdata, student_t *studentdata);
void searchAverage(int *N, int *sort_studentdata, student_t *studentdata);
void sort(int *N, int *sort_array, student_t *studentdata);
void sortFirstname(int *N, int *sort_array, student_t *studentdata);
void display(int *N, int *sort_array, student_t *studentdata);
void sortAverage(int *N, int *sort_array, student_t *studentdata);

int main(void){
  FILE *file;//file name declartion
  int sort_array[50]; 
  int i = 0; 
  int data; 
  data = 0;
  student_t studentdata[50]; // the struct array containing the data
  char junkc;//junk characater
  char option;
  char filename[50]; 
  printf("- Enter [a] to give a file name\n- enter any char or key to use default file\n- Your input: "); 
  scanf("%c", &option);//scaning 
  scanf ("%c", &junkc);
  if(option == 'a'){ 
    printf("Enter the name of the file:  ");
    scanf("%s", filename); 
    file = fopen(filename, "r");
    if(file == NULL){
      printf("Invalid File!\n");//reading file to an array of struct
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
  fclose(file);//closing file
  }
  }
  else{
    //open default file
    file = fopen("StudentInfo.txt", "r"); 
    if(file == NULL){
      printf("INVALID FILE!");
      }
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
   
    for(i = 0; i<50; i++){
      sort_array[i] = i;
    } 
//calling menu function
mainMenu(&data, sort_array, studentdata);

}

//display function
void display(int *N, int *sort_array, student_t *studentdata){
  int i;

  printf("\n");
  //data entries
  printf ("\n Your Current data is:\n\n");
  printf("\n Firstname %5s Lastname %5s Test1 %5s Test2 %5s Test3 %5s Average\n\n", "", "", "", "", "");
  for(i = 0; i < *N; i++){
    printf("%-16s %-14s %9.2f %9d %9d %12d", 
                studentdata[sort_array[i]].firstName,  
                studentdata[sort_array[i]].lastName, 
                studentdata[sort_array[i]].test1, 
                studentdata[sort_array[i]].test2, 
                studentdata[sort_array[i]].test3, 
                studentdata[sort_array[i]].average);
  }
printf("\n");
}

//sort avergae function definition
void sortAverage(int *N, int *sort_array, student_t *studentdata){ 
  int i, j, userOption, swap;
  
  char junk [50], junkc;

  printf("Enter:\n[1] to sort in ascending order.\n[2] to sort in descendingorder\n");
  printf("Enter your input here: ");
  scanf("%d",  &userOption); 
  //getting option for sorting
    while (userOption < 1 || userOption > 2){ 

    printf("Invalid option, try again! "); 
    scanf("%d",  &userOption); 
    } 
    if (userOption == '\n') userOption = 2;
    else{ 
    scanf("%c", &junkc); 
    } 
  
    if (userOption == 1){ 
    //Bubble sorting
    for(i= 0; i < *N-1; i++){ 
    for(j = 0; j < *N-1; j++){ 
      if(studentdata[sort_array[j]].average > studentdata[sort_array[j+1]].average){//comparing points 
      swap = sort_array[j]; 
      sort_array[j] = sort_array[j+1];  
      sort_array[j+1] = swap; 
      } 
    } 
    }   
    display(N, sort_array, studentdata);//call for function that prints the  sort studentdata 
    printf("\n");
    } 
      
    //descending order
    else if (userOption == 2){ 
    //bubble sort
      for(i= 0; i < *N-1; i++){ 
      for(j = 0; j < *N-1; j++){ 
        if((studentdata[sort_array[j]].average <  
        studentdata[sort_array[j+1]].average)) { 
        swap = sort_array[j]; 
        sort_array[j] = sort_array[j+1];  
        sort_array[j+1]= swap; 
    } 
    } 
    } 
    display(N, sort_array, studentdata); 
  } 
} 

// fucntion to sort 1st name definition
void sortFirstname(int *N, int *sort_array, student_t *studentdata){ 
    int i, j, userOption, swap; 
    char junkc; 
    //prompting user input 
    printf("Enter:\n(1)to sort from 'z' to 'a'.\n(2)to sort from 'a' to 'z'.\n"); 

    scanf("%d", &userOption); 
    printf("You choose option %d.\n", userOption); 
    //sort by ascending and descending order. 
  //bubble sort used
    if(userOption == 1){ 
      for(i= 0; i < *N-1; i++){ 
        for(j = 0; j < *N-1; j++){ 
        if(strcmp(studentdata[sort_array[j]].firstName,  
          studentdata[sort_array[j+1]].firstName)<0){ 
          swap = sort_array[j]; 
          sort_array[j] = sort_array[j+1];  
          sort_array[j+1] = swap; 
      } 
      } 
    } 
    display(N, sort_array, studentdata); 
    } 
    //sorting from a to z
    else if(userOption == 2){ 
    //Bubble sort
    for(i= 0; i < *N-1; i++){ 
      for(j = 0; j < *N-1; j++){ 
               
    if(strcmp(studentdata[sort_array[j]].firstName,studentdata[sort_array[j+1]].firstName) > 0){
        swap = sort_array[j]; 
        sort_array[j] = sort_array[j+1];  
        sort_array[j+1]= swap; 
      } 
      } 
    } 
    display(N, sort_array, studentdata);//calling function display
    } 
} 

//function definitionn for sort 
void sort(int *N, int *sort_array, student_t *studentdata){ 
  char userOption, junkc, junk[30]; 
  //giving the user options
  printf("\n\n Choose option to sort your data\n");
  printf("\n Choose:\n- [a]verage\n- [f]irstname\n");
  printf ("Input your choice here: ");

  scanf("%c", &userOption);
  scanf("%c", &junkc); 
 
  while (userOption != 'a' && userOption != 'f' && userOption != '\n'){
  
    printf("Invalid Option.Try again (g, f) [g]: ");//default 'g' 
    scanf("%c", &userOption);
    scanf("%c", &junkc); 
  }
 
  if(userOption == 'f'){//sorting firstnames
    sortFirstname(N, sort_array, studentdata); 
  } 
  else if(userOption == 'a'){//sorting grade
    sortAverage(N, sort_array, studentdata); 
  } 
}

//funtion definition for searching for a specific average
void searchAverage(int *N, int *sort_studentdata, student_t *studentdata){
  int num, i, foundData, catch; 
  foundData = 0;
  char junkc; 
  printf("Enter the average grade you are looking: "); 
  scanf("%d", &num); 
  for (i=0; i<*N; i++ ){
    if (studentdata[i].average==num){
    foundData++; //incrementring the matched data
    printf("%-16s %-14s %9.2f %9d %9d %12d\n", 
              studentdata[i].firstName,  
              studentdata[i].lastName, 
              studentdata[i].test1, 
              studentdata[i].test2, 
              studentdata[i].test3, 
              studentdata[i].average);
    printf("\n"); 
  } 
}

if(foundData == 0){
  printf("No data was found!\n");
}
  
}

//function definition for searching grades for  test1
void searchTest1(int *N, int *sort_studentdata, student_t *studentdata){
  int i, foundData, catch; 
  float num;
  foundData = 0;
  char junkc; 
  printf("Enter the test1 (a float data type) score you are looking: "); 
  scanf("%f", &num); 
  for (i=0; i<*N; i++ ){
    if (studentdata[i].test1==num){
    foundData++; //incrementing the mathced data
    printf("%-16s %-14s %9.2f %9d %9d %12d\n", 
              studentdata[i].firstName,  
              studentdata[i].lastName, 
              studentdata[i].test1, 
              studentdata[i].test2, 
              studentdata[i].test3, 
              studentdata[i].average);
    printf("\n"); 
  } 
}

if(foundData == 0){
  printf("No data was found!\n");
}
  
}


//search function definition includes search average and search test1
void search (int *N, int *sort_array, student_t *studentdata){
  char userOption, junkc, junk[30]; 
  //giving the user options
  printf("\n\n Choose option to delete your data\n");
  printf("\n Choose:\n- [a]verage\n- [t]est1\n");
  printf("Your option:");
  scanf("%c", &userOption);
  scanf("%c", &junkc); 
  if(userOption == 't'){
    searchTest1(N, sort_array, studentdata); 
  } 
  else if(userOption == 'a'){
    searchAverage(N, sort_array, studentdata); 
  } 
}

//funtion definition for delete average
void deleteAverage(int *N, int *sort_studentdata, student_t *studentdata){
  int i, foundData;
  int num;
  int option, j;
  char junkc;
  foundData = 0;
  printf("Enter the average grade you wish to delete: "); 
  scanf("%d", &num);
  scanf("%c", &junkc);
  for (i=0; i<*N; i++){
    if (studentdata[i].average == num){
    foundData++;//incrementing if similar data are found
    printf("\n"); 
    printf("%-16s %-14s %9.2f %9d %9d %12d\n", 
              studentdata[i].firstName,  
              studentdata[i].lastName, 
              studentdata[i].test1, 
              studentdata[i].test2, 
              studentdata[i].test3, 
              studentdata[i].average);
    printf("\n"); 
  } 
}

if(foundData == 0){
  printf("No data was found!\n");
}

else if(foundData == 1){//if data is only one just delete
  for(i = 0; i<*N; i++){
  if(studentdata[i].average == num){
    for(j = i; j<*N; j++){
    studentdata[j] = studentdata[j+1];
    }
  }
}
}

else{
  //if data found > 1 ask give user a choice
  printf("To delete the above data enter \"1\", if not, enter \"0\":   ");
  scanf("%d", &option);
  if(option  == 1){
    for(i = 0; i<*N; i++){
      // printf("Here is the data to be deleted: ");
      if(studentdata[i].average == num){
        for(j = i; j<*N; j++){
          studentdata[j] = studentdata[j+1];
        }
      }
    }
  }
}
*N = *N-foundData;
}

//deletetest1 function definition
void deleteTest1(int *N, int *sort_studentdata, student_t *studentdata){
  int i, foundData;
  float num;
  int option, j;
  char junkc;
  foundData = 0;
  printf("Enter the  you wish to delete: "); 
  scanf("%f", &num);
  scanf("%c", &junkc);
  for (i=0; i<*N; i++){
    if (studentdata[i].test1 == num){
    foundData++;//incrementing mathed data
    printf("\n"); 
    printf("%-16s %-14s %9.2f %9d %9d %12d\n", 
              studentdata[i].firstName,  
              studentdata[i].lastName, 
              studentdata[i].test1, 
              studentdata[i].test2, 
              studentdata[i].test3, 
              studentdata[i].average);
    printf("\n"); 
  } 
}

if(foundData == 0){
  printf("No data was found!\n");
}

else if(foundData == 1){
  for(i = 0; i<*N; i++){
  if(studentdata[i].test1 == num){
    for(j = i; j<*N; j++){
    studentdata[j] = studentdata[j+1];
    }
  }
}
}

else{
  //hiving the user option if mathced data>1
  printf("To delete the above data enter \"1\", if not, enter \"0\":   ");
  scanf("%d", &option);
  if(option  == 1){
    for(i = 0; i<*N; i++){
      // printf("Here is the data to be deleted: ");
      if(studentdata[i].test1 == num){
        for(j = i; j<*N; j++){
          studentdata[j] = studentdata[j+1];
        }
      }
    }
  }
}
*N = *N-foundData;
}

//delete data function definition includes delete average and delete test 1

void delete_data(int *N, int *sort_array, student_t *studentdata){
  char userOption, junkc, junk[30]; 
  //giving the user options
  printf("\n\n Choose option to search your data\n");
  printf("\n Choose:\n- [a]verage\n- [t]est1\n");
  printf("Your option:");
  scanf("%c", &userOption);
  scanf("%c", &junkc); 
  if(userOption == 't'){
    deleteTest1(N, sort_array, studentdata); 
  } 
  else if(userOption == 'a'){
    deleteAverage(N, sort_array, studentdata); 
  } 
}

//function definition for adding record
void add (int *N, int *sort_array, student_t *studentdata){
  
  char junkc, junk[50];
  printf("You've chosen to add a new record. Follow isntructions below to preoceed\n\n");
  printf("- First Name: "); 
  //scanning and getting user inputs
  scanf("\n%s", studentdata[*N].firstName);
  
  printf("- Last Name: "); 
  scanf("%s", studentdata[*N].lastName);
  
  printf("- Test1(float): "); 
  scanf("%f", &studentdata[*N].test1);
  
  printf("- Test2(integer): "); 
  scanf("%d", &studentdata[*N].test2); 
  
  printf("- Test3(integer): "); 
  scanf("%d", &studentdata[*N].test3); 

  printf("- Average(integer): "); 
  scanf("%d", &studentdata[*N].average);

  *N = *N+1;
  printf("\n\n");
  display(N, sort_array, studentdata);
  }


//save funtion definition
void save(int *N, int *sort_array, student_t *studentdata){
  FILE* filesave;
  char junkc;
  char junk [40];
  int option;
  char filename[50];
  int choice;
  int i;
  printf("Enter:\n- [1] to save to a file of your choice and any key to save to default file\n\n");
  scanf("%d", &choice);
  if(choice == 1){
  printf("Enter the name of the file with .txt extension:  ");
  scanf("%s", filename);
  filesave= fopen(filename, "r");//reading a file to check if later if file already exits
  if(filesave  == NULL){// file no exist
    filesave = fopen(filename, "w");//writing to a file
    for(i = 0; i<*N; i++){
        fprintf(filesave,"%s,%s,%f,%d,%d,%d", 
              studentdata[sort_array[i]].firstName,  
              studentdata[sort_array[i]].lastName, 
              studentdata[sort_array[i]].test1, 
              studentdata[sort_array[i]].test2, 
              studentdata[sort_array[i]].test3, 
              studentdata[sort_array[i]].average);
  }
    fclose(filesave);//closing file
  } 
  else if (filesave != NULL){//file does already exist
    fclose(filesave);
    filesave = fopen( filename, "w");//writing the file
    printf("File alreadyd exist! Enter: -[3] to overwrite -[any key]to not overwrite");
    scanf("%d", &option);

    if(option  == 3){
      for(i = 0; i<*N; i++){//writing to the file
        fprintf(filesave,"%s,%s,%.2f,%d,%d,%d", 
              studentdata[sort_array[i]].firstName,  
              studentdata[sort_array[i]].lastName, 
              studentdata[sort_array[i]].test1, 
              studentdata[sort_array[i]].test2, 
              studentdata[sort_array[i]].test3, 
              studentdata[sort_array[i]].average);
  }
      fclose(filesave);//close file
  } 
}
    } 
else {
  filesave = fopen("newfile.txt", "r");
  if(filesave  == NULL){
   //opening the default file
  filesave = fopen("newfile.txt", "w");
  for(i = 0; i<*N; i++){
    //writing to default file
    fprintf(filesave,"%s,%s,%.2f,%d,%d,%d", 
            studentdata[sort_array[i]].firstName,  
            studentdata[sort_array[i]].lastName, 
            studentdata[sort_array[i]].test1, 
            studentdata[sort_array[i]].test2, 
            studentdata[sort_array[i]].test3, 
            studentdata[sort_array[i]].average);
}
  fclose(filesave);//closing file
     
} 
 else if (filesave != NULL){
  printf("File already exist! Enter: \n- [1] to overwrite \n-[any key]to not overwrite");
  printf ("\nYour Option: ");
  scanf("%d", &option );
  if(option == 1){
    for(i = 0; i<*N; i++){//writing to a file
       fprintf(filesave,"%s,%s,%.2f,%d,%d,%d\n", 
          studentdata[sort_array[i]].firstName,  
          studentdata[sort_array[i]].lastName, 
          studentdata[sort_array[i]].test1, 
          studentdata[sort_array[i]].test2, 
          studentdata[sort_array[i]].test3, 
          studentdata[sort_array[i]].average);
    } 
      
fclose(filesave);//closing file
    }
   }
  }
  
}


//main menu function definition to take multiple inputs from user

void mainMenu(int *N, int *sort_array, student_t *studentdata){
char entry, again, junkc; 
printf("\nTo visualize data choose from options below:\n\n" 
 "Dis[p]lay\n" 
 "S[o]rt\n" 
 "Sea[r]ch\n" 
 "[a]dd\n" 
 "Del[e]te\n"
  "Sa[v]e\n"); 

  // do while loop to take user inputs as long as they don't wish ti quit
  do { 
  printf("\nTo proceed, Enter(p, o, r, a, e, v) [p]: "); 
  scanf("%c", &entry); 
  if(entry == '\n') entry = 't';//default 
  else scanf("%c", &junkc); 
  printf("You selected option %c.\n", entry); 
  if(entry == 'p'){ 
  display(N,sort_array, studentdata);//displaying function 
  } 
  else if (entry == 'o'){ 
  sort(N, sort_array, studentdata); //sorting function 
   } 
  else if(entry == 'r'){ 
  search(N, sort_array, studentdata);//search function 
  } 
  else if(entry == 'a'){ 
  add(N, sort_array, studentdata);//adding function 
  } 
  else if(entry == 'e'){ 
  delete_data(N, sort_array, studentdata);//deleting function 
  } 
  else if(entry == 'v'){ 
    save(N, sort_array, studentdata);//saving function 
  }
  else if(entry != 'o' && entry != 'r' && entry != 'a' && entry != 'e'&& entry != 'p' && entry != 'v'){ 
  printf("Invalid option, try again!\n"); 
  }
  printf("\n"); 
  printf("Again? Enter [q] to quit or any other alphabet to continue: "); 
  scanf("%c", &again);
  if(again == '\n') again = 'y';//default 
  else scanf("%c", &junkc);
} while(again != 'q'); 
printf("\n\nYou've opted to stop visualizing the data!!\n");  
} 

