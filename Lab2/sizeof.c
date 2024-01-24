/******************************************************************************

Studying the storage sizes of variables and structs

Jarno Tuominen, TUAS

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>

int main()
{

    // http://www.catb.org/esr/structure-packing/

    //demonstrate struck packing here
    //{uint8, uint8, uint16} vs {uint8, uint16, uint8}

    typedef struct my_struct_t
    {
        uint8_t w;
        uint8_t x;
        //uint8_t y;
        uint16_t z;
        //uint8_t ww;
        //uint8_t www;
    } my_struct_t;

    //my_struct_t my_struct;// = { 15, 100, 1000, 55, 66, 77};
    my_struct_t my_struct = { 15, 100, 66};

    int my_var = 100;   //A ”normal” variable declaration
    int * my_ptr;       //Pointer declaration operator (points to integer type)
    my_ptr = &my_var;	// Address-of operator picks the address of my_var and assigns it to my_ptr

    uint8_t a = 55;
    uint16_t b = 66;
    
    
    
    
    printf("Address of my_var variable:\t%x\n",&my_var);
    printf("Address stored in my_ptr variable:\t%x\n",my_ptr);
    printf("Value of *my_ptr variable:\t%d\n\n",*my_ptr);
    
    //What is the address space of our machine?
    printf("Size of my_ptr variable:\t%d bits\n\n",sizeof(my_ptr)*8);

    *my_ptr = 144;    // Now we dereference, i.e. change the value of the register at address pointed by my_ptr
    printf("Value of *my_ptr variable:\t%d\n",*my_ptr);
    printf("Value of my_var:\t%d\n",my_var);

    printf("Size of integer:\t%d bits, %d bytes\n",sizeof(my_var)*8,sizeof(my_var));
    printf("Size of uint8_t\t%d bits, %d bytes\n",sizeof(a)*8,sizeof(a));
    printf("Size of uint16_t\t%d bits, %d bytes\n",sizeof(b)*8,sizeof(b));
    printf("Size of my_struct\t%d bits, %d bytes\n",sizeof(my_struct)*8,sizeof(my_struct));

    return 0;

}


