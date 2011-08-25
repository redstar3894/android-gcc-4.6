/* { dg-do compile } */
/* { dg-options "-O2 -march=armv7-a" } */

unsigned long long
foo (unsigned short a, unsigned short *b, unsigned short *c)
{
  return (unsigned)a + (unsigned long long)*b * (unsigned long long)*c;
}

/* { dg-final { scan-assembler "umlal" } } */
