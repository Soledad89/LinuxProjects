#if !defined(FP_T_H)
#define FP_T_H

/* CONS(a,b) should return ab, the concatenation of its arguments */
#if defined(STDC)
#define CONS(a,b) a##b
#else
#define CONS(a,b) a/**/b
#endif

#if defined(HAVE_MATH_H)
#include <math.h>
#endif

#if defined(HAVE_SUNMATH_H)
#include <sunmath.h>			/* needed for float and  long double library prototypes */
#endif

#if defined(HAVE_FP_T_DOUBLE)
#define FP(x) x
typedef double fp_t;
#endif

#undef acos
#undef acosh
#undef asin
#undef asinh
#undef atan
#undef atanh
#undef cbrt
#undef ceil
#undef copysign
#undef cos
#undef cosh
#undef erf
#undef erfc
#undef exp
#undef expm1
#undef fabs
#undef floor
#undef fmod
#undef hypot
#undef ilogb
#undef j0
#undef j1
#undef jn
#undef ldexp
#undef lgamma
#undef log
#undef log1p
#undef log10
#undef pow
#undef remainder
#undef rint
#undef scalb
#undef significand
#undef sin
#undef sinh
#undef sqrt
#undef tan
#undef tanh
#undef trunc
#undef y0
#undef y1
#undef yn

#if defined(HAVE_FP_T_QUADRUPLE)
#define FP(x) CONS(x,L)			/* macro to add L suffix for long-double constants */
typedef long double fp_t;

/* This prototype is needed: some systems lack it, even if it is in the native library */
EXTERN long double			(strtold) ARGS((const char * /* restrict */ nptr,
							char ** /* restrict */ endptr));


#define acos(x)				(acosl)((fp_t)(x))
#define acosh(x)			(acoshl)((fp_t)(x))
#define asin(x)				(asinl)((fp_t)(x))
#define asinh(x)			(asinhl)((fp_t)(x))
#define atan(x)				(atanl)((fp_t)(x))
#define atanh(x)			(atanhl)((fp_t)(x))
#define cbrt(x)				(cbrtl)((fp_t)(x))
#define ceil(x)				(ceill)((fp_t)(x))
#define copysign(x,y)			(copysignl)((fp_t)(x), (fp_t)(y))
#define cos(x)				(cosl)((fp_t)(x))
#define cosh(x)				(coshl)((fp_t)(x))
#define erf(x)				(erfl)((fp_t)(x))
#define erfc(x)				(erfcl)((fp_t)(x))
#define exp(x)				(expl)((fp_t)(x))
#define expm1(x)			(expm1l)((fp_t)(x))
#define fabs(x)				(fabsl)((fp_t)(x))
#define floor(x)			(floorl)((fp_t)(x))
#define fmod(x,y)			(fmodl)((fp_t)(x), (fp_t)(y))
#define hypot(x,y)			(hypotl)((fp_t)(x), (fp_t)(y))
#define ilogb(x)			(ilogbl)((fp_t)(x))
#define j0(x)				(j0l)((fp_t)(x))
#define j1(x)				(j1l)((fp_t)(x))
#define jn(n,x)				(jnl)((int)(n), (fp_t)(x))
#define ldexp(x,y)			(ldexpl)((fp_t)(x), (int)(y))
#define lgamma(x)			(lgammal)((fp_t)(x))
#define log(x)				(logl)((fp_t)(x))
#define log1p(x)			(log1pl)((fp_t)(x))
#define log10(x)			(log10l)((fp_t)(x))
#define pow(x,y)			(powl)((fp_t)(x), (fp_t)(y))
#define remainder(x,y)			(remainderl)((fp_t)(x), (fp_t)(y))
#define rint(x)				(rintl)((fp_t)(x))
#define scalb(x,y)			(scalbl)((fp_t)(x), (fp_t)(y))
#define significand(x)			(significandl)((fp_t)(x))
#define sin(x)				(sinl)((fp_t)(x))
#define sinh(x)				(sinhl)((fp_t)(x))
#define sqrt(x)				(sqrtl)((fp_t)(x))
#define tan(x)				(tanl)((fp_t)(x))
#define tanh(x)				(tanhl)((fp_t)(x))
#define trunc(x)			(truncl)((fp_t)(x))
#define y0(x)				(y0l)((fp_t)(x))
#define y1(x)				(y1l)((fp_t)(x))
#define yn(n,x)				(ynl)((int)(n), (fp_t)(x))

#if defined(__linux__) && defined(__i386__)
/* GNU/Linux on Intel x86 has a few functions that simply print an
   not-implemented-yet error message and return, so fall back to the
   double-precision versions on that system. */
#undef erf
#undef erfc
#undef j0
#undef j1
#undef jn
#undef lgamma
#undef y0
#undef y1
#undef yn

#define erf(x)				((fp_t)((erf)((double)(x))))
#define erfc(x)				((fp_t)((erfc)((double)(x))))
#define j0(x)				((fp_t)((j0)((double)(x))))
#define j1(x)				((fp_t)((j1)((double)(x))))
#define jn(n,x)				((fp_t)((jn)((n), (double)(x))))
#define lgamma(x)			((fp_t)((lgamma)((double)(x))))
#define y0(x)				((fp_t)((y0)((double)(x))))
#define y1(x)				((fp_t)((y1)((double)(x))))
#define yn(n,x)				((fp_t)((yn)((n), (double)(x))))
#endif /* defined(__linux__) && defined(__i386__) */

#if defined(__linux__) && defined(__PPC__)
/* GNU/Linux on PowerPC has one missing quadruple-precision function,
   so fall back to the double-precision version on that system. */
#undef sqrt

#define sqrt(x)				((fp_t)((sqrt)((double)(x))))
#endif /* defined(__linux__) && defined(__PPC__) */

#if defined(__sgi)
/* SGI IRIX 6.x has a few functions that are not available in quadruple
   precision, so fall back to the double-precision versions on that
   system. */
#undef acosh
#undef asinh
#undef atanh
#undef ilogb

#define acosh(x)			((fp_t)((acosh)((double)(x))))
#define asinh(x)			((fp_t)((asinh)((double)(x))))
#define atanh(x)			((fp_t)((atanh)((double)(x))))
#define ilogb(x)			((fp_t)((ilogb)((double)(x))))
#endif /* defined(__sgi) */

#endif /* defined(HAVE_FP_T_QUADRUPLE) */

#if defined(HAVE_FP_T_SINGLE)
#define FP(x) CONS(x,F)			/* macro to add F suffix for float constants */
typedef float fp_t;

#define acos(x)				(acosf)((float)(x))
#define acosh(x)			(acoshf)((float)(x))
#define asin(x)				(asinf)((float)(x))
#define asinh(x)			(asinhf)((float)(x))
#define atan(x)				(atanf)((float)(x))
#define atanh(x)			(atanhf)((float)(x))
#define cbrt(x)				(cbrtf)((float)(x))
#define ceil(x)				(ceilf)((float)(x))
#define copysign(x,y)			(copysignf)((float)(x), (float)(y))
#define cos(x)				(cosf)((float)(x))
#define cosh(x)				(coshf)((float)(x))
#define erf(x)				(erff)((float)(x))
#define erfc(x)				(erfcf)((float)(x))
#define exp(x)				(expf)((float)(x))
#define expm1(x)			(expm1f)((float)(x))
#define fabs(x)				(fabsf)((float)(x))
#define floor(x)			(floorf)((float)(x))
#define fmod(x,y)			(fmodf)((float)(x), (float)(y))
#define hypot(x,y)			(hypotf)((float)(x), (float)(y))
#define ilogb(x)			(ilogbf)((float)(x))
#define j0(x)				(j0f)((float)(x))
#define j1(x)				(j1f)((float)(x))
#define jn(n,x)				(jnf)((n), (float)(x))
#define ldexp(x,y)			(ldexpf)((float)(x), (int)(y))
#define lgamma(x)			(lgammaf)((float)(x))
#define log(x)				(logf)((float)(x))
#define log1p(x)			(log1pf)((fp_t)(x))
#define log10(x)			(log10f)((float)(x))
#define pow(x,y)			(powf)((float)(x), (float)(y))
#define remainder(x,y)			(remainderf)((float)(x), (float)(y))
#define rint(x)				(rintf)((float)(x))
#define scalb(x,y)			(scalbf)((float)(x), (float)(y))
#define significand(x)			(significandf)((float)(x))
#define sin(x)				(sinf)((float)(x))
#define sinh(x)				(sinhf)((float)(x))
#define sqrt(x)				(sqrtf)((float)(x))
#define tan(x)				(tanf)((float)(x))
#define tanh(x)				(tanhf)((float)(x))
#define trunc(x)			(truncf)((float)(x))
#define y0(x)				(y0f)((float)(x))
#define y1(x)				(y1f)((float)(x))
#define yn(n,x)				(ynf)((n), (float)(x))

#if defined(__APPLE__)
/* Apple Darwin (MacOS X) documents the single-precision functions in
   the manual pages, but then does not supply any of them in -lm!  Revert
   to the double-precision functions. */

#undef acos
#undef acosh
#undef asin
#undef asinh
#undef atan
#undef atanh
#undef cbrt
#undef ceil
#undef copysign
#undef cos
#undef cosh
#undef erf
#undef erfc
#undef exp
#undef expm1
#undef fabs
#undef floor
#undef fmod
#undef hypot
#undef ilogb
#undef j0
#undef j1
#undef jn
#undef ldexp
#undef lgamma
#undef log
#undef log10
#undef pow
#undef remainder
#undef rint
#undef scalb
#undef significand
#undef sin
#undef sinh
#undef sqrt
#undef tan
#undef tanh
#undef trunc
#undef y0
#undef y1
#undef yn

#define acos(x)				((fp_t)((acos)((double)(x))))
#define acosh(x)			((fp_t)((acosh)((double)(x))))
#define asin(x)				((fp_t)((asin)((double)(x))))
#define asinh(x)			((fp_t)((asinh)((double)(x))))
#define atan(x)				((fp_t)((atan)((double)(x))))
#define atanh(x)			((fp_t)((atanh)((double)(x))))
#define cbrt(x)				((fp_t)((cbrt)((double)(x))))
#define ceil(x)				((fp_t)((ceil)((double)(x))))
#define copysign(x,y)			((fp_t)((copysign)((double)(x), (double)(y))))
#define cos(x)				((fp_t)((cos)((double)(x))))
#define cosh(x)				((fp_t)((cosh)((double)(x))))
#define erf(x)				((fp_t)((erf)((double)(x))))
#define erfc(x)				((fp_t)((erfc)((double)(x))))
#define exp(x)				((fp_t)((exp)((double)(x))))
#define expm1(x)			((fp_t)((expm1)((double)(x))))
#define fabs(x)				((fp_t)((fabs)((double)(x))))
#define floor(x)			((fp_t)((floor)((double)(x))))
#define fmod(x,y)			((fp_t)((fmod)((double)(x), (double)(y))))
#define hypot(x,y)			((fp_t)((hypot)((double)(x), (double)(y))))
#define ilogb(x)			((fp_t)((ilogb)((double)(x))))
#define j0(x)				((fp_t)((j0)((double)(x))))
#define j1(x)				((fp_t)((j1)((double)(x))))
#define jn(n,x)				((fp_t)((jn)((n), (double)(x))))
#define ldexp(x,y)			((fp_t)((ldexp)((double)(x), (int)(y))))
#define lgamma(x)			((fp_t)((lgamma)((double)(x))))
#define log(x)				((fp_t)((log)((double)(x))))
#define log1p(x)			((fp_t)((log1p)((double)(x))))
#define log10(x)			((fp_t)((log10)((double)(x))))
#define pow(x,y)			((fp_t)((pow)((double)(x), (double)(y))))
#define remainder(x,y)			((fp_t)((remainder)((double)(x), (double)(y))))
#define rint(x)				((fp_t)((rint)((double)(x))))
#define scalb(x,y)			((fp_t)((scalb)((double)(x), (double)(y))))
#define significand(x)			((fp_t)((significand)((double)(x))))
#define sin(x)				((fp_t)((sin)((double)(x))))
#define sinh(x)				((fp_t)((sinh)((double)(x))))
#define sqrt(x)				((fp_t)((sqrt)((double)(x))))
#define tan(x)				((fp_t)((tan)((double)(x))))
#define tanh(x)				((fp_t)((tanh)((double)(x))))
#define trunc(x)			((fp_t)((trunc)((double)(x))))
#define y0(x)				((fp_t)((y0)((double)(x))))
#define y1(x)				((fp_t)((y1)((double)(x))))
#define yn(n,x)				((fp_t)((yn)((n), (double)(x))))
#endif /* defined(__APPLE__) */

#if defined(__sgi)
/* SGI IRIX 6.x has a few functions that are not available in single
   precision, so fall back to the double-precision versions on that
   system. */
#undef acosh
#undef asinh
#undef atanh
#undef cbrt
#undef copysign
#undef erfc
#undef erf
#undef ilogb
#undef j0
#undef j1
#undef jn
#undef lgamma
#undef remainder
#undef rint
#undef scalb
#undef y0
#undef y1
#undef yn

#define acosh(x)			((fp_t)((acosh)((double)(x))))
#define asinh(x)			((fp_t)((asinh)((double)(x))))
#define atanh(x)			((fp_t)((atanh)((double)(x))))
#define cbrt(x)				((fp_t)((cbrt)((double)(x))))
#define copysign(x,y)			((fp_t)((copysign)((double)(x), (double)(y))))
#define erfc(x)				((fp_t)((erfc)((double)(x))))
#define erf(x)				((fp_t)((erf)((double)(x))))
#define ilogb(x)			((fp_t)((ilogb)((double)(x))))
#define j0(x)				((fp_t)((j0)((double)(x))))
#define j1(x)				((fp_t)((j1)((double)(x))))
#define jn(n,x)				((fp_t)((jn)((n), (double)(x))))
#define lgamma(x)			((fp_t)((lgamma)((double)(x))))
#define remainder(x,y)			((fp_t)((remainder)((double)(x), (double)(y))))
#define rint(x)				((fp_t)((rint)((double)(x))))
#define scalb(x,y)			((fp_t)((scalb)((double)(x), (double)(y))))
#define y0(x)				((fp_t)((y0)((double)(x))))
#define y1(x)				((fp_t)((y1)((double)(x))))
#define yn(n,x)				((fp_t)((yn)((n), (double)(x))))
#endif /* defined(__sgi) */

#endif /* defined(HAVE_FP_T_SINGLE) */

#endif /* !defined(FP_T_H) */