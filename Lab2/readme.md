Lab 2

- Create a new project in VSCode, which has includes ALL of the 4 source (.c) files under Lab2/
- You will do this in project makefile (TBD, stay tuned)
- This will create a problem: Your project has several source files, which have main()-function - and will therefore produce an error.

- To overcome this: Wrap the unnecessary source code lines (i.e. the whole main-function) with preprocess #if . like this:

#if 0 // always false
main() {  // this will not be included 
    
}
#endif


#if 1 // always true
main() {  // this will  be included 
    
}
#endif


Lab 2 assignments: 

2.1

Create a struct (type defined) called "Book" that has the following fields:

    Name of the book. (char array, max 50 characters)
    ID of the book. (unsigned int, 16 bits)
    Is the book currently loaned (boolean).

Next, create a program, which has a command interpreter, which understands the following commands:
    add = add a new book
    del = delete a book
    list = list available books
    lall = list all books
    lone = list details of one book (search with with ID)
    loan = loan a book (with ID)
    return = return a book (with ID)
    exit = exits the program

Implement the command using an infinite while-loop and switch-case structure
Use scanf()-function to grab the command and based on the command make a function call to respective function handling the command.

2.2

Create an array "Library", which contains N books.
Write the "action"-functions so that the program actually works

2.3

Add file operations, so that when your program is executed, it will ask the library file name as an argument, and updates the file based on the actions you do. You can decide the file format. When you exit program execution, write the changes to the file - or alternatively you can write each change to a file when the program is running.

