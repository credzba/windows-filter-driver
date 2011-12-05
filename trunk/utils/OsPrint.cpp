#include "OsPrint.h"

#include <fltKernel.h>
#include <ntddk.h>
#include <suppress.h>

#define NTSTRSAFE_LIB
#include <ntstrsafe.h>


ULONG __cdecl 
DbgPrintExToDbgPrint(ULONG ComponentId,
                     ULONG Level,
                     PCH Format,
                     ...
                     ) {
    ULONG   ret;
    va_list args;

    va_start ( args , Format ) ;
    ret = DbgPrint( Format, args );
    va_end ( args ) ;

    return  ret;
}


DBG_PRINT_EX_PTR OsPrintEx=0;

void OsPrintInitialize()
{
    ULONG MajorVer;

    PsGetVersion(&MajorVer, NULL, NULL, NULL);

    if (MajorVer > 5)
    {
        DECLARE_CONST_UNICODE_STRING(ds, L"DbgPrintEx");
        OsPrintEx = (DBG_PRINT_EX_PTR)(ULONG_PTR)MmGetSystemRoutineAddress((PUNICODE_STRING)&ds);
    }
    else
    {
        OsPrintEx = DbgPrintExToDbgPrint;
    }
}


