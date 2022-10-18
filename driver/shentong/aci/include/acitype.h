#pragma once

#ifndef ACITYPE_H
# define ACITYPE_H

#include <limits.h>

#ifndef TRUE
# define TRUE  1
# define FALSE 0
#endif

#ifndef lint 
typedef unsigned char ub1;
typedef signed char sb1;
#else 
#define ub1 unsigned char 
#define sb1 signed char 
#endif 

#define UB1MAXVAL ((ub1)UCHAR_MAX) 
#define UB1MINVAL ((ub1)        0) 
#define SB1MAXVAL ((sb1)SCHAR_MAX) 
#define SB1MINVAL ((sb1)SCHAR_MIN) 
#define MINUB1MAXVAL ((ub1)  255) 
#define MAXUB1MINVAL ((ub1)    0) 
#define MINSB1MAXVAL ((sb1)  127) 
#define MAXSB1MINVAL ((sb1) -127) 

#ifndef lint 
typedef unsigned short ub2;
typedef signed short sb2;
#else 
#define ub2  unsigned short 
#define sb2  signed short 
#endif

#define UB2MAXVAL ((ub2)USHRT_MAX) 
#define UB2MINVAL ((ub2)        0) 
#define SB2MAXVAL ((sb2) SHRT_MAX) 
#define SB2MINVAL ((sb2) SHRT_MIN) 
#define MINUB2MAXVAL ((ub2) 65535) 
#define MAXUB2MINVAL ((ub2)     0) 
#define MINSB2MAXVAL ((sb2) 32767) 
#define MAXSB2MINVAL ((sb2)-32767) 

#ifndef lint 
typedef unsigned int ub4;
typedef signed int sb4;
#else 
#define eb4 int 
#define ub4 unsigned int 
#define sb4 signed int 
#endif 

#define UB4MAXVAL ((ub4)UINT_MAX) 
#define UB4MINVAL ((ub4)        0) 
#define SB4MAXVAL ((sb4) INT_MAX) 
#define SB4MINVAL ((sb4) INT_MIN) 
#define MINUB4MAXVAL ((ub4) 4294967295) 
#define MAXUB4MINVAL ((ub4)          0) 
#define MINSB4MAXVAL ((sb4) 2147483647) 
#define MAXSB4MINVAL ((sb4)-2147483647) 

/* --- Signed/Unsigned eight-byte scalar (acisb8/aciub8) --- */

#define ORAXB8_DEFINED
#ifndef lint
#ifndef __GNUC__
typedef unsigned _int64 aciub8;
typedef signed _int64 acisb8;
#else
typedef unsigned long long aciub8;
typedef signed long long acisb8;
#endif
typedef aciub8 ub8;
typedef acisb8 sb8;
#else
# define ub8 aciub8
# define sb8 acisb8
# define aciub8 unsigned _int64
# define acisb8 signed _int64
#endif /* !lint */

#define ORAUB8MINVAL    ((aciub8)0)
#define ORAUB8MAXVAL    ((aciub8)18446744073709551615)
#define ORASB8MINVAL    ((acisb8)-9223372036854775808)
#define ORASB8MAXVAL    ((acisb8) 9223372036854775807)

#define MAXORAUB8MINVAL ((aciub8)0)
#define MINORAUB8MAXVAL ((aciub8)18446744073709551615)
#define MAXORASB8MINVAL ((acisb8)-9223372036854775807)
#define MINORASB8MAXVAL ((acisb8) 9223372036854775807)

#define UB1BITS          CHAR_BIT
#define UB1MASK          ((1 << ((uword)CHAR_BIT)) - 1)

#ifdef lint
# define acitext unsigned char
#else
typedef unsigned char acitext;
#endif

#ifndef lint 
typedef char eb1;
typedef short eb2;
typedef int eb4;
#else
# define         eb1      char
# define         eb2      short
# define         eb4      int
#endif

#define EB1MAXVAL      ((eb1)SCHAR_MAX) 
#define EB1MINVAL      ((eb1)        0) 
#define MINEB1MAXVAL   ((eb1)  127) 
#define MAXEB1MINVAL   ((eb1)    0) 
#define EB2MAXVAL      ((eb2) SHRT_MAX) 
#define EB2MINVAL      ((eb2)        0) 
#define MINEB2MAXVAL   ((eb2) 32767) 
#define MAXEB2MINVAL   ((eb2)     0) 
#define EB4MAXVAL      ((eb4) INT_MAX) 
#define EB4MINVAL      ((eb4)        0) 
#define MINEB4MAXVAL   ((eb4) 2147483647) 
#define MAXEB4MINVAL   ((eb4)          0) 

#ifndef lint 
typedef sb1 b1;
#else 
#define         b1 sb1 
#endif  
#define  B1MAXVAL  SB1MAXVAL 
#define  B1MINVAL  SB1MINVAL 

#ifndef lint 
typedef sb2 b2;
#else 
#define         b2 sb2 
#endif  
#define  B2MAXVAL  SB2MAXVAL 
#define  B2MINVAL  SB2MINVAL 

#ifndef lint 
typedef sb4 b4;
#else 
#define         b4 sb4 
#endif  
# define  B4MAXVAL  SB4MAXVAL 
# define  B4MINVAL  SB4MINVAL 

#if !defined(LUSEMFC)
# ifdef lint
#  define text unsigned char
# else
typedef acitext text;
# endif
#endif

#ifdef lint
# define OraText unsigned char
# define oratext unsigned char
#else
typedef acitext OraText;
typedef acitext oratext;
#endif

#ifndef lint
typedef int eword;
typedef unsigned int uword;
typedef signed int sword;
#else
#define eword int
#define uword unsigned int
#define sword signed int
#endif 

#define  EWORDMAXVAL  ((eword) INT_MAX)
#define  EWORDMINVAL  ((eword)       0)
#define  UWORDMAXVAL  ((uword)UINT_MAX)
#define  UWORDMINVAL  ((uword)       0)
#define  SWORDMAXVAL  ((sword) INT_MAX)
#define  SWORDMINVAL  ((sword) INT_MIN)
#define  MINEWORDMAXVAL  ((eword)  2147483647)
#define  MAXEWORDMINVAL  ((eword)      0)
#define  MINUWORDMAXVAL  ((uword)  4294967295)
#define  MAXUWORDMINVAL  ((uword)           0)
#define  MINSWORDMAXVAL  ((sword)  2147483647)
#define  MAXSWORDMINVAL  ((sword) -2147483647)

#ifdef _WIN64

#ifndef lint
typedef unsigned _int64 ubig_aci;
typedef signed _int64 sbig_aci;
#else
#define ubig_aci unsigned _int64
#define sbig_aci signed _int64
#endif 

#define UBIG_ORAMAXVAL ((ubig_aci)_UI64_MAX)
#define UBIG_ORAMINVAL ((ubig_aci)        0)
#define SBIG_ORAMAXVAL ((sbig_aci) _I64_MAX)
#define SBIG_ORAMINVAL ((sbig_aci) _I64_MIN)
#define MINUBIG_ORAMAXVAL ((ubig_aci) 4294967295)
#define MAXUBIG_ORAMINVAL ((ubig_aci)          0)
#define MINSBIG_ORAMAXVAL ((sbig_aci) 2147483647)
#define MAXSBIG_ORAMINVAL ((sbig_aci)-2147483647)

#else

#ifndef lint
typedef unsigned long ubig_aci;
typedef signed long sbig_aci;
#else
#define ubig_aci unsigned long
#define sbig_aci signed long
#endif 

#define UBIG_ORAMAXVAL ((ubig_aci)ULONG_MAX)
#define UBIG_ORAMINVAL ((ubig_aci)        0)
#define SBIG_ORAMAXVAL ((sbig_aci) LONG_MAX)
#define SBIG_ORAMINVAL ((sbig_aci) LONG_MIN)
#define MINUBIG_ORAMAXVAL ((ubig_aci) 4294967295)
#define MAXUBIG_ORAMINVAL ((ubig_aci)          0)
#define MINSBIG_ORAMAXVAL ((sbig_aci) 2147483647)
#define MAXSBIG_ORAMINVAL ((sbig_aci)-2147483647)

#endif                                                             /* _WIN64 */

#define UBIGORABITS      (UB1BITS * sizeof(ubig_aci))

#undef CONST
#define CONST const

#define dvoid void

typedef void (*lgenfp_t)(void);

#ifndef ORASYS_TYPES
# include <sys/types.h>
# define ORASYS_TYPES
#endif 

#ifndef COMPILE_ACI_LIB
#ifndef boolean
# define boolean int
#endif 
#endif 

#ifdef sparc
#define SIZE_TMAXVAL SB4MAXVAL               
#else
#define SIZE_TMAXVAL UB4MAXVAL              
#endif 

#define MINSIZE_TMAXVAL (size_t)4294967295

#if !defined(MOTIF) && !defined(LISPL)  && !defined(__cplusplus) && !defined(LUSEMFC)
typedef acitext *string;
#endif 

#ifndef lint
typedef unsigned short utext;
#else
#define utext  unsigned short
#endif
/*****************************************************************************/
/*                         NUMBER/FLOAT/DECIMAL TYPE                         */
/*****************************************************************************/
#define ACI_NUMBER_SIZE 22
struct ACINumber
{
    ub1 ACINumberPart[ACI_NUMBER_SIZE];
};
typedef struct ACINumber ACINumber;
#endif 
