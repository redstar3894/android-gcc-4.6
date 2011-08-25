/* { dg-do compile } */
/* { dg-options "-O2 -march=armv7-a" } */

int
foo (int a, short b, short c)
{
     int bc = b * c;
        return a + (short)bc;
}

/* { dg-final { scan-assembler "mul" } } */
