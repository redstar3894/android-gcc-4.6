/* { dg-do compile } */
/* { dg-options "-O2 -march=armv7-a" } */

struct bf
{
  int a : 3;
  int b : 15;
  int c : 3;
};

long long
foo (long long a, struct bf b, struct bf c)
{
  return a + b.b * c.b;
}

/* { dg-final { scan-assembler "smlalbb" } } */
