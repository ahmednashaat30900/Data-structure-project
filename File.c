#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Book_Store.h"


void writeToFile(l id,char book_name[],char author_name[])
{
    FILE *fptr=fopen("Book Store.csv","a+");
if(fptr==NULL)
    printf("file not found");
else{
    fprintf(fptr,"%d,%s,%s\n",id,book_name,author_name);
}
}
void ReadFromFile()
{
    int id=0;
    char name[100];
    char author_name[100];
    char*ptr;
    char str[1024];
    FILE *fp;
    if((fp=fopen("Book Store.csv","r"))==NULL)
        printf("file not found");
         while(fgets(str, sizeof str, fp) !=NULL){
                if ((strlen(str)>0) && (str[strlen (str) - 1] == '\n'))
            str[strlen (str) - 1] = '\0';
         ptr=strtok(str,",");
         id=atoi(ptr);
         ptr=strtok(NULL,",");
         strcpy(name, ptr);
         ptr=strtok(NULL,",");
         strcpy(author_name,ptr);
         Add_Book(id,name,author_name);
      }
      printf("\n");
      fclose(fp);
}
void del(int ID){
FILE *fp1=fopen("Book Store.csv","r");
FILE *fp2=fopen("New Book Store.csv","a");
    int id;
    char book_name[100];
    char author_name[100];
    char*ptr;
    char str[1024];
    int i;
if(fp1==NULL)
    printf("file not exist");
     while(fgets(str, sizeof str, fp1) !=NULL){
                if ((strlen(str)>0) && (str[strlen (str) - 1] == '\n'))
            str[strlen (str) - 1] = '\0';
         ptr=strtok(str,",");
         id=atoi(ptr);
         ptr=strtok(NULL,",");
         strcpy(book_name, ptr);
         ptr=strtok(NULL,",");
         strcpy(author_name,ptr);
    if(id!=ID){
      fprintf(fp2,"%d,%s,%s\n",id,book_name,author_name);
    }
    }
fclose(fp1);
fclose(fp2);
remove("Book Store.csv");
rename("New Book Store.csv","Book Store.csv");
}


void action()
{
printf("****************************************\n");
printf("please,enter a number to take an action*\n");
printf("****************************************\n");
printf("1| Add a new book                      *\n");
printf("****************************************\n");
printf("2| Remove a book                       *\n");
printf("****************************************\n");
printf("3| Find a book                         *\n");
printf("****************************************\n");
printf("4| Edit a book                         *\n");
printf("****************************************\n");
printf("5|Display all books                    *\n");
printf("****************************************\n");
printf("0| End the program                     *\n");
printf("****************************************\n");
}
