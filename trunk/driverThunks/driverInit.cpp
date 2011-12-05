#include <fltKernel.h>
#include <ntddk.h>

#define NTSTRSAFE_LIB
#include <ntstrsafe.h>

#include <ntstatus.h>
#include <OsPrint.h>

//---------------------------------------------------------------------------
//      Global variables
//---------------------------------------------------------------------------


extern "C" void DriverUnload()
{
    OsPrint("Unload");
} // DriverUnload()


extern "C" NTSTATUS
DriverEntry (
    __in PDRIVER_OBJECT _DriverObject,
    __in PUNICODE_STRING _RegistryPath)
{
    OsPrintInitialize();

    OsPrint("Init\n");
    return STATUS_SUCCESS;

}


