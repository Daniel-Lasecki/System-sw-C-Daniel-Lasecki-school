/******************************************************************************

Strings

Jarno Tuominen, TUAS

*******************************************************************************/
#include <stdio.h>

int main()
{
   
    char string1[5] = "Blaa";
    char string2[5] = {'B','l','a','a','\0'};
    char string3[4] = "Blaa";

    printf("%s\n",string1);
    printf("%s\n",string2);
    printf("%s\n",string3);

    return 0;
}
