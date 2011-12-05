#ifndef OSPRINT_H
#define OSPRINT_H

#include <fltKernel.h>

#define NTSTRSAFE_LIB
#include <ntstrsafe.h>

void OsPrintInitialize();

extern "C" {
typedef ULONG (__cdecl * DBG_PRINT_EX_PTR)(
    IN ULONG ComponentId,
    IN ULONG Level,
    IN PCH Format,
    ...
    );
}
extern DBG_PRINT_EX_PTR OsPrintEx;


inline void  OsPrint(char* _format, ...) {
    va_list args;

    va_start ( args , _format ) ;
    DbgPrintEx( DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, _format, args );
    va_end ( args ) ;
}

#define  DBG_BREAK(x)  OsPrint(x); __debugbreak();

void OsPrintInitialize();

#if DBG
#ifdef ASSERT 
#undef ASSERT
#endif
#define  ASSERT( _Condition ) {                 \
    if( ! ( _Condition )) {                                             \
    OsPrint( "%s[%zd] %s Assertion failed: %s\n", __FILE__, __LINE__, __FUNCTION__, #_Condition ); \
    __debugbreak(); } \
  }
#else 
#define ASSERT( _Condition )
#endif

#endif
