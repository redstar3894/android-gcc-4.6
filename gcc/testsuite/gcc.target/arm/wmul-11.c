/* { dg-do compile } */
/* { dg-options "-O2 -march=armv7-a" } */

long long
foo (int *b)
{
  return 10 * (long long)*b;
}

/* { dg-final { scan-assembler "smull" } } */
