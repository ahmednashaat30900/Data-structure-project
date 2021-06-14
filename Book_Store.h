#ifndef BOOK_STORE_H_INCLUDED
#define BOOK_STORE_H_INCLUDED

typedef long  l;

typedef struct Node{

l Id;
struct Node *next;
char *Name;
char *Author;
}Book;

void Add_Book(l id,char*name,char*author);
void Display();
void Delete_Book(l id);
void Find_Book_Id(l id);
void Find_Book_Name(char *name);
void Find_Book_Author(char *author);
void action();
void writeToFile(l id,char book_name[],char author_name[]);
void ReadFromFile();


#endif // BOOK_STORE_H_INCLUDED
