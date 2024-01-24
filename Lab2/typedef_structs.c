/******************************************************************************

typedef'd structures

Jarno Tuominen, TUAS

*******************************************************************************/

#include <stdio.h>
#include <string.h>

#if 0
struct { //anonymous struct type
   char title[50];
   int book_id;
} book1, book2, book3; //variable(s) declaration
#endif
#if 0
struct Book_t { //named struct type
   char title[50];
   int book_id;
} book1;
struct Book_t book2, book3;
#endif

#if 1
typedef struct {
   char title[50];
   int book_id;
} Book_t;
#endif


int main() {
   //struct Book_t book1; //variable declaration
   Book_t book1;
   strcpy( book1.title, "C Programming");
   book1.book_id = 6495407;

   printf( "Book title : %s\n", book1.title);
   printf( "Book book_id : %d\n", book1.book_id);
   return 0;
}
