#include <fltKernel.h>
#include <ntddk.h>

#define NTSTRSAFE_LIB
#include <ntstrsafe.h>

#include <ntstatus.h>

//---------------------------------------------------------------------------
//      Global variables
//---------------------------------------------------------------------------


extern "C" void DriverUnload()
{
    
} // DriverUnload()


extern "C" NTSTATUS
DriverEntry (
    __in PDRIVER_OBJECT _DriverObject,
    __in PUNICODE_STRING _RegistryPath)
{

    return STATUS_SUCCESS;

}


