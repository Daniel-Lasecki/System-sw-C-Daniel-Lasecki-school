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

TBD 

2.2

TBD 

2.3

TBD 

2.4

TBD 
