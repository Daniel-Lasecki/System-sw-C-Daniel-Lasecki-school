#include <stdio.h>
#include <string.h>
#include <stdint.h>


typedef struct 
{
    char title[50];
    uint16_t book_id;
    int isloaned;
}Book_t;

int main(int argc, char *argv[]){


    Book_t book;
    char *command = malloc(10);
    printf("Enter string here: ");
    scanf("%9s",command);
    printf("\n%s\n",command);

    while(1){
        if(strcmp(command,"add") == 0){
            addBook();
        }
        if(strcmp(command,"delete") == 0){
            deleteBook();
        }
        if(strcmp(command,"available") == 0){
            listAvailableBooks();
        }
        if(strcmp(command,"all") == 0){
            listAllBooks();
        }
        if(strcmp(command,"id") == 0){
            showBookByID();
        }
        if(strcmp(command,"loan") == 0){
            loanBook();
        }
        if(strcmp(command,"return") == 0){
            returnBook();
        }
        if(strcmp(command,"exit") == 0){
            printf("Exiting book program......\n");
            break;
        }


    }
    
    free(command);
    return 0;
}


void addBook(){


    return 0;
}
void deleteBook(){

    return 0;
}
void listAvailableBooks(){

    return 0;
}
void listAllBooks(){
    
    return 0;
}
void showBookByID(uint16_t id){


    return 0;
}
void loanBook(uint16_t id){

    return 0;

}
void returnBook(uint16_t id){
    
    return 0;
}
