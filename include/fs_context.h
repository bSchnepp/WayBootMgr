#ifndef _CONTXT_H_
#define _CONTXT_H_

#include "uefi.h"
#include "exe/elf.h"

//Let's just chuck out the FS stuff I already got in favor of this because it's new and shiny.
//We're just only going to support kernels which happen to be located in the ESP w/ their initrd.
//Unfortunate limitation for now.
//TODO: abstract away UEFI's file stuff so we can ignore the ESP on a running system unless needed.

//Waypoint needs an initrd system, because we'd like the kernel to not really care too much about the bootloader.
//As such, an A:/Waypoint/System/initram.wim file must exist. (if not specified by the bootloader)

//To keep compatibility with FAT, we have to limit all files to stay within 8.3: We're going to really hate this restriction, but will put up with it for now.
//TODO: Rename all files to ensure it can use FAT just fine.

struct Kernel
{
	EFI_HANDLE handle;
	EFI_FILE_IO_INTERFACE* filesystem;
	EFI_FILE_HANDLE root;
	EFI_FILE_HANDLE kernel_file;	//Kernel we're pointing to.
}Kernel;

struct ElfInfo 
{
	struct ElfHeader* hdr;
	struct ElfProgramHeader* phdr;
	//TODO
}ElfInfo;

#endif
