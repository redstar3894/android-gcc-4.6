/* { dg-do compile } */
/* { dg-options "-O2 -march=armv7-a" } */

unsigned long long
foo (unsigned long long a, unsigned char *b, unsigned short *c)
{
  return a + *b * *c;
}

/* { dg-final { scan-assembler "umlal" } } */
