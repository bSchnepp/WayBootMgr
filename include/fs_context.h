#include "uefi.h"

//Let's just chuck out the FS stuff I already got in favor of this because it's new and shiny.

struct Kernel
{
	EFI_HANDLE handle;
	EFI_FILE_IO_INTERFACE* filesystem;
	EFI_FILE_HANDLE root;
	EFI_FILE_HANDLE kernel_file;	//Kernel we're pointing to.
}Kernel;
