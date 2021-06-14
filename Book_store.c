#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include <conio.h>
#include "Book_Store.h"


Book *head=NULL;

void Add_Book(l id,char*name,char*author)
{
Book *new_Book,*last;
new_Book=(Book*)malloc(sizeof(Book));
new_Book->Id=id;
new_Book->Name=malloc(strlen(name)+1);
        strcpy(new_Book->Name,name);
        new_Book->Author=malloc(strlen(author)+1);
        strcpy(new_Book->Author,author);

if(head==NULL){

    head=new_Book;
    new_Book->next=NULL;
}
else if(new_Book->Id<head->Id)
{
    new_Book->next=head;
    head=new_Book;
}

else{
    last=head;
while(last->next!=NULL){
        if(new_Book->Id<last->next->Id)
            break;
    last=last->next;
}
if(last->next==NULL)
{
    last->next=new_Book;
new_Book->next=NULL;
}
else
    {
    new_Book->next=last->next;
    last->next=new_Book;
    }
}
}
void Display()
{
int i=1;
Book* current_Book;
if(head==NULL){
    printf("Linked list is empty\n");
}
else
{
    current_Book=head;
    while(current_Book!=NULL){ ;
        printf("\n****************************************\n");
        printf("the Id of the book [%d] is :%ld\n",i,current_Book->Id);
        printf("the name of the book [%d] is :%s\n",i,current_Book->Name);
        printf("the Author of the book [%d] is :%s\n",i,current_Book->Author);
        printf("****************************************\n\n");
        current_Book=current_Book->next;
        i++;
    }
}
}

void Delete_Book(l id)
{
Book* current_Book,*previous_Book;
current_Book=head;
    previous_Book=head;

if(head==NULL){
    printf("Linked list is empty");
}
else if(current_Book->Id==id){
    head=current_Book->next;
    free(current_Book);
}
else
{
    while(current_Book->Id!=id)
    {
        if(current_Book->next==NULL)
        {
            return ;
        }
        previous_Book=current_Book;
        current_Book=current_Book->next;

    }
    previous_Book->next=current_Book->next;
    free(current_Book);

}
if(head!=NULL)
    del(id);
}

void Find_Book_Id(l id)
{
Book *current_Book;
current_Book=head;

while(current_Book->Id!=id){
    current_Book=current_Book->next;
}
printf("\n****************************************\n");
printf("the Id of the book is %ld\n",current_Book->Id);
printf("the name of the book is %s\n",current_Book->Name);
printf("the author of the book is %s\n",current_Book->Author);
printf("\nBook Finded Successful!!\n");
printf("****************************************\n\n");
}

