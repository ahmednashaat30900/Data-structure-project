#include <stdio.h>
#include <stdlib.h>
#include "Book_Store.h"
#include "Book_Store.c"
#include "File.c"
int main()
{
        int choice;
        long id;
        printf("welcome to the book store\n\n");

        ReadFromFile();

        do{
        char *y;
        y=(char*)malloc(sizeof(15));
        char *z;
        z=(char*)malloc(sizeof(15));
        action();
        scanf("%d",&choice);
            switch (choice){

        case 1:

            printf("*************************************\n");
            printf("please,enter the Id of the book:    *\n");
            scanf("%ld",&id);
            printf("please,enter Name of the book:      *\n");
            fflush(stdin);
            scanf("%[^\n]s",y);
            printf("please,enter the Author of the book:*\n");
            fflush(stdin);
            scanf("%[^\n]s",z);
            Add_Book(id,y,z);
            writeToFile(id,y,z);
            printf("\nBook Added Successful!!\n");
            printf("*************************************\n\n");
            break;

        case 2 :
            printf("please,enter the Id of the book\n");
            scanf("%ld",&id);
            Delete_Book(id);
            printf("\nBook Deleted Successful!!\n");
            printf("*************************************\n");
            break;

        case 3 :
                printf("please,enter the Id of the book\n");
                scanf("%ld",&id);
                Find_Book_Id(id);
            break;
        case 4:
            printf("please,enter the Id of the book\n");
            scanf("%ld",&id);
            Delete_Book(id);
            printf("please,enter new Name of the book:      *\n");
            fflush(stdin);
            gets(y);
            printf("please,enter the new Author of the book:*\n");
            fflush(stdin);
            gets(z);
            Add_Book(id,y,z);
            writeToFile(id,y,z);
            printf("\nBook Edited Successful!!\n");
            printf("*************************************\n");
            break;

        case 5 :
                Display();
                break;

        default :
            if(choice!=0)
            printf("please,enter a valid number from [1] to [5]!!\n");
            }
        }while(choice!=0);
    return 0;
}
