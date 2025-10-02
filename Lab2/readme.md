Lab 2

  In this lab, we will
  - learn how to use CMake to control the build process of your project.
  - learn how to use preprocessor directives (#if) to leave out parts of your code
  - create a library manager application, which has multiple functions and uses struct data types
  - add file operations to your project (you will learn how to use POSIX API for file operations)
  
  2.0
   
- Lab2/ - directory contains four example source files (.c), which all have main()-function. That is a problem you need to solve somehow. If you build only one file at a time, that is not an issue, but if try to compile those all into your project, you will get a compile error. 

First, let's take Cmake into use.

1. Go to terminal and install cmake and some related tools:

`sudo apt install cmake`

`sudo apt install ninja-build`

2. Next, in VSCode, install Cmake Tools by going to extensions on the left side (**Ctrl-Shift-X**)

3. Surf in the project directory (in this case Lab2) and press **Ctrl-Shift-P** and select **Cmake Quick Start**

- Give your project some name, select C as the project language. This information will be written to CmakeLists.txt and a few initial source files.
- Select **CTest** as an additional option
- Select **Executable** as the project type 

This successfully creates the CMakeLists.txt file, which tells the CMake tools how to build your project.

4. Continue with the CMake quick start to create a CMakePreset.json-file. 

Select **Add a New Preset** and **Create from Compilers**.

The extension automatically scans for kits on your computer and creates a list of compilers found on your system.

Select the compiler you want to use. In our case it will be gcc*something*.    

You can now try to build and run your project. By default, it is compiling main.c (see CMakeLists.txt)

-------- TO BE CONTINUED ---------------



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

In order to use scanf(), you need to reserve memory for the string you are inputting - this happens via malloc()-function. Have a look at this:

https://stackoverflow.com/questions/3295884/malloc-and-scanf



2.2

Create an array "Library", which contains N books.
Write the "action"-functions so that the program actually works

2.3

Add file operations, so that when your program is executed, it will ask the library file name as an argument, and updates the file based on the actions you do. You can decide the file format. When you exit program execution, write the changes to the file - or alternatively you can write each change to a file when the program is running.

