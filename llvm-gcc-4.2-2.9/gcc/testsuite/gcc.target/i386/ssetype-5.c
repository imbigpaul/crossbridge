/* { dg-do compile { target i?86-*-* x86_64-*-* } } */
/* { dg-options "-O2 -msse2 -march=k8" } */
/* APPLE LOCAL fix-and-continue 6360409 */
/* { dg-options "-mno-fix-and-continue -O2 -msse2 -march=k8" { target *-*-darwin* } } */
/* { dg-final { scan-assembler "pand\[^\\n\]*magic" } } */
/* { dg-final { scan-assembler "pandn\[^\\n\]*magic" } } */
/* { dg-final { scan-assembler "pxor\[^\\n\]*magic" } } */
/* { dg-final { scan-assembler "por\[^\\n\]*magic" } } */
/* { dg-final { scan-assembler "movdqa" } } */
/* { dg-final { scan-assembler-not "movaps\[^\\n\]*magic" } } */

/* Verify that we generate proper instruction with memory operand.  */

#include <xmmintrin.h>
static __m128i magic_a, magic_b;
__m128i
t1(void)
{
return _mm_and_si128 (magic_a,magic_b);
}
__m128i
t2(void)
{
return _mm_andnot_si128 (magic_a,magic_b);
}
__m128i
t3(void)
{
return _mm_or_si128 (magic_a,magic_b);
}
__m128i
t4(void)
{
return _mm_xor_si128 (magic_a,magic_b);
}

