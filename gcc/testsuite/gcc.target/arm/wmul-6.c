/* { dg-do compile } */
/* { dg-options "-O2 -march=armv7-a" } */

long long
foo (long long a, unsigned char *b, signed char *c)
{
  return a + (long long)*b * (long long)*c;
}

/* { dg-final { scan-assembler "smlal" } } */
