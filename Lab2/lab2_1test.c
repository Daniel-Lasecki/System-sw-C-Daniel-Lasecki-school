#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *toParseStr = malloc(10);
printf("Enter a string: ");
scanf("%9s", toParseStr);
printf("\n%s\n", toParsestr);
/* Edit, added: */ 
free(toParseStr);
return 0;