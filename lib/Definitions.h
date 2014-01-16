/*----------------------------------------------------------------------*/
#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

	#ifndef UNICODE
		#define UNICODE
	#endif

	#ifndef _UNICODE
		#define _UNICODE
	#endif

	#ifdef _DEFINITIONS_H_

		#define _WIN32_WINNT	0x0400

		#pragma warning( push, 4 )

		#pragma conform( forScope, on )


		#pragma warning( disable : 4115 )

    #include <winsock2.h>

		#include <windows.h>

		#pragma warning( default : 4115 )

		#include <windowsx.h>

		#pragma warning( disable : 4201 )

			#include <commctrl.h>

		#pragma warning( default : 4201 )

		#include <shlobj.h>

		#include <mlang.h>


		#include <tlhelp32.h>

		#pragma warning( disable : 4244 )

		#pragma warning( disable : 4018 )

		#ifdef NDEBUG

			#pragma warning( disable : 4710 )

		#endif

	#elif _MSC_VER == 1400

		#define _WIN32_WINNT	0x0500

		#define _USE_32BIT_TIME_T

		#pragma warning( push, 4 )

		#pragma conform( forScope, on )

		#include <windows.h>

		#include <windowsx.h>

		#include <commctrl.h>

		#include <shlobj.h>

		#include <mlang.h>

		#include <winsock.h>

		#include <tlhelp32.h>

		// deprecated warning
		// #pragma warning( disable : 4996 )

		#pragma warning( disable : 4244 )

		#pragma warning( disable : 4018 )

	#else

		#error Compiler version not supported

	#endif

	#include <stdlib.h>
	#include <crtdbg.h>

	#include <limits.h>
	#include <stdio.h>
	#include <tchar.h>
	#include <direct.h>

	#define _USE_MATH_DEFINES
	#include <math.h>

	#include <time.h>
	#include <share.h>
	#include <float.h>

	#include <vector>
	#include <string>
	#include <algorithm>

	using namespace std;

	typedef basic_string<TCHAR, char_traits<TCHAR>, allocator<TCHAR> > tstring;

	#ifdef INT32
		#undef INT32
	#endif

	#ifdef UINT32
		#undef UINT32
	#endif

	#ifdef INT16
		#undef INT16
	#endif

	#ifdef UINT16
		#undef UINT16
	#endif

	#ifdef INT8
		#undef INT8
	#endif

	#ifdef UINT8
		#undef UINT8
	#endif

	#ifdef INT64
		#undef INT64
	#endif

	#ifdef UINT64
		#undef UINT64
	#endif

	#ifdef REAL32
		#undef REAL32
	#endif

	#ifdef REAL64
		#undef REAL64
	#endif

	#ifdef BOOL
		#undef BOOL
	#endif

	#ifdef TRUE
		#undef TRUE
	#endif

	#ifdef FALSE
		#undef FALSE
	#endif

	#if INT_MAX == 2147483647

		#define INT32	int
		#define UINT32	unsigned int

	#elif LONG_MAX == 2147483647

		#define INT32	long int
		#define UINT32	unsigned long int

	#else

		#error INT32, UINT32 types not supported

	#endif

	#if INT_MAX == 32767

		#define INT16	int
		#define UINT16	unsigned int

	#elif SHRT_MAX == 32767

		#define INT16	short int
		#define UINT16	unsigned short int

	#else

		#error INT16, UINT16 types not supported

	#endif

	#if CHAR_MAX == 127

		#define INT8	signed char
		#define UINT8	unsigned char

	#else

		#error INT8, UINT8 types not supported

	#endif

	//--------------------------

	#define INT64							__int64
	#define UINT64							unsigned __int64

	#define REAL32							float
	#define REAL64							double
	#define BOOL							int
	#define TRUE							1
	#define FALSE							0

	#define MAX_REAL32_VALUE				FLT_MAX
	#define MAX_REAL64_VALUE				DBL_MAX

	#define FOREVER							for ( ; ; )

	//--------------------------

	#undef MIN
	#define MIN								__min

	#undef MAX
	#define MAX								__max

	#undef ABS
	#define ABS( X )						(( X ) < 0 ? -( X ) : ( X ))

	//--------------------------

	#define BIN__N( X )						( X ) | X >> 3 | X >> 6 | X >> 9
	#define BIN__B( X )						( X ) & 0xF | ( X ) >> 12 & 0xF0

	#define BIN8( X )						( BIN__B( BIN__N( 0x##X )))

	#define BIN16( X1, X2 )					(( BIN8( X1 ) << 8 ) + BIN8( X2 ))

	#define BIN24( X1, X2, X3 )				(( BIN8( X1 ) << 16 ) + ( BIN8( X2 ) << 8 ) + BIN8( X3 ))

	#define BIN32( X1, X2, X3, X4 )			(( BIN8( X1 ) << 24 ) + ( BIN8( X2 ) << 16 ) + ( BIN8( X3 ) << 8 ) + BIN8( X4 ))

	//--------------------------

	#define MAKE64( X, Y )					(( UINT64 )(((( UINT64 )( X )) & 0x00000000FFFFFFFF ) |	\
												(((( UINT64 )( Y )) << 32 ) & 0xFFFFFFFF00000000 )))
	#define LO32( X )						(( UINT32 )(( X ) & 0xFFFFFFFF ))
	#define HI32( Y )						(( UINT32 )(((( UINT64 )( Y )) >> 32 ) & 0xFFFFFFFF ))

	#define CHANGE_ENDIAN_ORDER_16( X )		MAKEWORD( HIBYTE( X ), LOBYTE( X ))
	#define CHANGE_ENDIAN_ORDER_32( X )		MAKELONG( CHANGE_ENDIAN_ORDER_16( HIWORD( X )), CHANGE_ENDIAN_ORDER_16( LOWORD( X )))
	#define CHANGE_ENDIAN_ORDER_64( X )		MAKE64( CHANGE_ENDIAN_ORDER_32( HI32( X )), CHANGE_ENDIAN_ORDER_32( LO32( X )))

	//--------------------------

	#define TIME_DIFF( StartTime, EndTime )		(( EndTime >= StartTime ) ? ( EndTime - StartTime ) : ( 0xFFFFFFFF - ( StartTime - EndTime )))

	//--------------------------

	#define MINIMAL_REAL64				FLT_EPSILON

	#define REAL64_IS_EQUAL( X, Y )		\
		((((( REAL64 ) Y ) - MINIMAL_REAL64 ) < (( REAL64 ) X )) && ((( REAL64 ) X ) < ((( REAL64 ) Y ) + MINIMAL_REAL64 )))

	#define ROUND( X, Accuracy )		\
		( floor((( REAL64 ) X ) / (( REAL64 ) Accuracy ) + 0.5 ) * (( REAL64 ) Accuracy ))

	#define REAL64_IS_INTEGER( X )		\
		REAL64_IS_EQUAL( ROUND( X, MINIMAL_REAL64 ) - floor( ROUND( X, MINIMAL_REAL64 )), 0 )

	//--------------------------

	#ifdef NDEBUG

		#undef ASSERT

		#define ASSERT( Exp )			( Exp )

		#pragma warning( disable : 4702 )

		#ifndef FATAL
			#define FATAL				MessageBox( NULL, TEXT( "FATAL" ), TEXT( "Fatal" ), MB_OK )
		#endif

	#else

		#include <assert.h>

		#ifndef ASSERT
			#define ASSERT				assert
		#endif

		#ifndef FATAL
			#define FATAL				ASSERT( FALSE )
		#endif

	#endif



#endif
/*----------------------------------------------------------------------*/