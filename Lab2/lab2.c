#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct 
{
    char title[50];
    uint16_t book_id;
    int isloaned;
}Book_t;

// book storage
#define MAX_BOOKS 20
Book_t library[MAX_BOOKS];
int book_count = 0;


void addBook();
void deleteBook();
void listAvailableBooks();
void listAllBooks();
void showBookByID();
void loanBook();
void returnBook();
void loadLibraryFromFile(const char *filename);
void saveLibraryToFile(const char *filename);

int main(int argc, char *argv[]){
    
    const char *filename = argv[1]; // get filename from command line // REMEMBER TO ADD FILE NAME WHEN CALLING ./lab2 in TERMINAL (eg. ./lab2 library.csv)
    loadLibraryFromFile(filename);

    char command[20];
    printf("Welcome to the library program!\n");
    printf("Library file: %s\n", filename);

    while(1){
        printf("\nEnter command (add, delete, available, all, id, loan, return, exit): ");
        scanf("%s", command);

        if(strcmp(command,"add") == 0){
            addBook();
        }
        else if(strcmp(command,"delete") == 0){
            deleteBook();
        }
        else if(strcmp(command,"available") == 0){
            listAvailableBooks();
        }
        else if(strcmp(command,"all") == 0){
            listAllBooks();
        }
        else if(strcmp(command,"id") == 0){
            showBookByID();
        }
        else if(strcmp(command,"loan") == 0){
            loanBook();
        }
        else if(strcmp(command,"return") == 0){
            returnBook();
        }
        else if(strcmp(command,"exit") == 0){
            printf("Exiting book program..\n");
            saveLibraryToFile(filename);
            break;
        }
        else {
            printf("Unknown command\n");
        }
        
    }
    return 0;
}

// CSV file format: id,title,isloaned
void loadLibraryFromFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[128];
    book_count = 0;
    while (fgets(line, sizeof(line), fp) && book_count < MAX_BOOKS) {
        if (strlen(line) < 5) continue; // skip empty lines
        Book_t books;
        char loaned[10];
        
        if (sscanf(line, "%hd,%49[^,],%9s", &books.book_id, books.title, loaned) == 3) {
            books.isloaned = (strcmp(loaned, "Loaned") == 0) ? 1 : 0;
            library[book_count++] = books;
        }
    }
    fclose(fp);
}

void saveLibraryToFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    
    for (int i = 0; i < book_count; i++) {
        fprintf(fp, "%d,%s,%s\n", library[i].book_id, library[i].title, library[i].isloaned ? "Loaned" : "Available");
    }
    fclose(fp);
}

// commands for program

void addBook(){
    if (book_count >= MAX_BOOKS) {
        printf("Book list is full\n");
        return;
    }
    Book_t newBook;
    printf("Enter book title: ");

    getchar(); 
    fgets(newBook.title, sizeof(newBook.title), stdin);
    size_t len = strlen(newBook.title);
    if (len > 0 && newBook.title[len-1] == '\n') newBook.title[len-1] = '\0';


    printf("Enter book ID: ");
    scanf("%hd", &newBook.book_id);
    newBook.isloaned = 0;
    library[book_count++] = newBook;
    printf("Book added\n");
}

void deleteBook(){
    uint16_t id;
    printf("Enter book ID to delete: ");
    scanf("%hd", &id);
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (library[i].book_id == id) {
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1];
            }
            book_count--;
            found = 1;
            printf("Book deleted\n");
            break;
        }
    }
    if (!found) {
        printf("Book not found\n");
    }
}

void listAvailableBooks(){
    printf("Available books:\n");
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (!library[i].isloaned) {
            printf("ID: %hd, Title: %s\n", library[i].book_id, library[i].title);
            found = 1;
        }
    }
    if (!found) {
        printf("No available books\n");
    }
}

void listAllBooks(){
    printf("All books:\n");
    if (book_count == 0) {
        printf("No books in the library\n");
        return;
    }
    for (int i = 0; i < book_count; i++) {
        printf("ID: %hd, Title: %s, %s\n", library[i].book_id, library[i].title, library[i].isloaned ? "Loaned" : "Available");
    }
}

void showBookByID(){
    uint16_t id;
    printf("Enter book ID: ");
    scanf("%hd", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].book_id == id) {
            printf("ID: %hd, Title: %s, %s\n", library[i].book_id, library[i].title, library[i].isloaned ? "Loaned" : "Available");
            return;
        }
    }
    printf("Book not found\n");
}

void loanBook(){
    uint16_t id;
    printf("Enter book ID to loan: ");
    scanf("%hd", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].book_id == id) {
            if (library[i].isloaned) {
                printf("Book is already loaned\n");
            } else {
                library[i].isloaned = 1;
                printf("Book loaned\n");
            }
            return;
        }
    }
    printf("Book not found\n");
}

void returnBook(){
    uint16_t id;
    printf("Enter book ID to return: ");
    scanf("%hd", &id);
    for (int i = 0; i < book_count; i++) {
        if (library[i].book_id == id) {
            if (!library[i].isloaned) {
                printf("Book is not loaned\n");
            } else {
                library[i].isloaned = 0;
                printf("Book returned\n");
            }
            return;
        }
    }
    printf("Book not found\n");
}
