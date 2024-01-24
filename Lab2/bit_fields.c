/******************************************************************************

Bit fields in structs

Jarno Tuominen, TUAS

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

typedef struct {
  unsigned int d;
  unsigned int m;
  unsigned int y;
} date_t;

typedef struct {
  unsigned int d:5;
  unsigned int m:4;
  unsigned int  y:11; //max: 2047
} date_small_t;

typedef struct {
  bool a;
  bool b;
  bool c;
} flags_t;

typedef struct {
  bool a: 1;
  bool b: 1;
  bool c: 1;
} flags_bits_t;



int main()
{
  printf ("Size of date_t is %d bytes\n", sizeof (date_t));
  date_t dt = {31, 12, 2018};
  printf ("Date is %d/%d/%d\n", dt.d, dt.m, dt.y);

  printf ("Size of date_small_t is %d bytes\n", sizeof (date_small_t));
  date_small_t dt2 = {31, 12, 2018};
  printf ("Date is %d/%d/%d\n", dt2.d, dt2.m, dt2.y);
  
  printf ("Size of flags_t is %d bytes\n", sizeof (flags_t));
  printf ("Size of flags_bits_t is %d bytes\n", sizeof (flags_bits_t));
}
