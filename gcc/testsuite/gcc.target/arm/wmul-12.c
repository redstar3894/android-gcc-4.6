/* { dg-do compile } */
/* { dg-options "-O2 -march=armv7-a" } */

long long
foo (int *b, int *c)
{
  int tmp = *b * *c;
  return 10 + (long long)tmp;
}

/* { dg-final { scan-assembler "smlal" } } */
