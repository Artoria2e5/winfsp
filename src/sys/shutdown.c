/**
 * @file sys/shutdown.c
 *
 * @copyright 2015-2016 Bill Zissimopoulos
 */

#include <sys/driver.h>

static NTSTATUS FspFsvolShutdown(
    PDEVICE_OBJECT DeviceObject, PIRP Irp, PIO_STACK_LOCATION IrpSp);
FSP_DRIVER_DISPATCH FspShutdown;
FSP_IOCMPL_DISPATCH FspFsvolShutdownComplete;

#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE, FspFsvolShutdown)
#pragma alloc_text(PAGE, FspFsvolShutdownComplete)
#pragma alloc_text(PAGE, FspShutdown)
#endif

static NTSTATUS FspFsvolShutdown(
    PDEVICE_OBJECT DeviceObject, PIRP Irp, PIO_STACK_LOCATION IrpSp)
{
    PAGED_CODE();

    return STATUS_INVALID_DEVICE_REQUEST;
}

NTSTATUS FspFsvolShutdownComplete(
    PIRP Irp, const FSP_FSCTL_TRANSACT_RSP *Response)
{
    FSP_ENTER_IOC(PAGED_CODE());

    FSP_LEAVE_IOC("%s", "");
}

NTSTATUS FspShutdown(
    PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
    FSP_ENTER_MJ(PAGED_CODE());

    switch (FspDeviceExtension(DeviceObject)->Kind)
    {
    case FspFsvolDeviceExtensionKind:
        FSP_RETURN(Result = FspFsvolShutdown(DeviceObject, Irp, IrpSp));
    default:
        FSP_RETURN(Result = STATUS_INVALID_DEVICE_REQUEST);
    }

    FSP_LEAVE_MJ("%s", "");
}
