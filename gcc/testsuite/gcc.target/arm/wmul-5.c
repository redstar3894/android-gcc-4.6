/* { dg-do compile } */
/* { dg-options "-O2 -march=armv7-a" } */

long long
foo (long long a, char *b, char *c)
{
  return a + *b * *c;
}

/* { dg-final { scan-assembler "umlal" } } */
