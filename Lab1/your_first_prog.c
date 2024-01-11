/******************************************************************************

Your first C program to demonstrate usage of Ville and VSCode in action
SystemSW
Jarno Tuominen, TUAS 2024

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main ()
{
  int a, b, c, sum;
  bool over10 = false;
  double average;

  //Seed for random number generator comes from system time
  time_t t;
  srand((int) time(&t));

  a = rand () % 100;
  b = rand () % 100;
  c = rand () % 100;

  printf ("The numbers are a=%d, b=%d and c=%d\n", a, b, c);

  /*Write the program code lines which calculate and store:
  - the sum of variables a, b and c to variable sum
  - the average of the variables to variable average.

  Then test the average - if it is larger than 50,
  set the boolean variable "over10" to 'true'

  /**** Your code starts below this line *** */


  /**** Your code ends here ****/

  printf ("Sum is %d\n", sum);
  printf ("Average is %f, ", average);
  if (over10) {
      printf ("which is over 50.\n");
  } else {
      printf ("which is equal or less than 50.\n");
  }

  return 0;
}
