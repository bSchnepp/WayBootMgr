/*
Copyright (c) 2017 Brian Schnepp

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// For clarity, I erroneously refer to UEFI as "EFI", and don't bother correcting it.

#include "uefi.h"
#include "fs/common.h"	//TODO: Replace with each filesystem's things or something.

#include <stdlib.h>	//Our stdlib.

#define CODE_NAME "\tAlpha Aligator"

unsigned char boot_option;	//We're only allowing up to 9, so 'unsigned' doesn't matter, but well, consistency. [- for prev page, = for next page, 0 for first page.]
unsigned long long int page_number;	//For the crazy guy who somehow gets 18363036738 operating systems on one computer.

#define BOOL CHAR8	//Quick hack to get it to compile and still work as intended. Replace properly later.

// Struct definitions.
struct System 
{
	CHAR8* name;
	CHAR8* file_name;
	CHAR8* kernel_options;

	BOOL use_unicode_pathnames;
	BOOL is_chainload;
	BOOL is_multiboot;

	CHAR8* device;

	CHAR16* init_rd;
	CHAR16* kernel_location;
}System;

struct BootOption
{
	struct System* system;
	struct BootOption* next;	//Linked lists!
}BootOption;

struct System* CreateSystem(CHAR8* name, CHAR8* file_name, CHAR8* kernel_options, BOOL use_unicode_pathnames, BOOL is_chainload, CHAR8* device, CHAR16* init_rd, CHAR16* kernel_location, BOOL is_multiboot)
{	
	struct System* sys = (struct System*)malloc(sizeof(struct System*));
	sys->name = name;
	sys->file_name = file_name;	//if ELF, we append .elf, if aout, we append .aout, etc.
	sys->kernel_options = kernel_options;
	sys->use_unicode_pathnames = use_unicode_pathnames;
	sys->is_chainload = is_chainload;
	sys->is_multiboot = is_multiboot;
	sys->device = device;
	sys->init_rd = init_rd;
	sys->kernel_location = kernel_location;
	return sys;
}


// Global variables
struct BootOption options_root;
int64_t countdown;	//Not sure why you'd want something more than like 256 at the worst, but okkaaayyy... We'll only actually display a number when it's under 120.

EFI_MEMORY_DESCRIPTOR* memory_map;

UINT32 descriptor_version;

UINTN map_size = 0; 
UINTN map_key; 
UINTN descriptor_size;



//Functions
uint64_t GetSystemCount()
{
	uint64_t count = 0;
	while (options_root.next != NULL)
	{
		count++;
	}
	return count;
}

void ExecuteKernel(struct BootOption* options)
{
	//Load and run the kernel.
	//Paths are separated with a '/', __always__.

}

void TemporaryHackToBootFeralKernel(void)
{
	//Quick hack to just get it overwidth and boot the Waypoint kernel.
	//This WILL be removed later in favor of PROPERLY doing it.
	//I just want to actually work on a kernel.
	//This just assumes all things are good and there's no problems with the kernel or anything of that sort.

	EFI_GUID proto_loaded_image = EFI_LOADED_IMAGE_PROTOCOL_GUID;
	EFI_GUID proto_file_system = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;

	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* boot_volume;
}

void PrintMsg(char* msg)
{
	//Just to get annoying casts out of the way.
	Print((CHAR16*)msg);
	Print(L"\n");
}

EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable) 
{
	PrepareSystem(ImageHandle, SystemTable);
	PrintMsg("Starting up WayBootMgr...\nYou're currently using: ");
	PrintMsg(CODE_NAME);


	//Here's the meat of the bootloader.
	//We'll initialize the filesystems, load up a simple EFI gui, make the boot options available, when ENTER is pressed, we'll load the OS selected.
	TemporaryHackToBootFeralKernel();

	EFI_STATUS stat;
	EFI_INPUT_KEY key;

	while ((stat = ReadKeyStroke(key)) == EFI_NOT_READY);

	ExitBootServices(ImageHandle, map_key);	
	return EFI_SUCCESS;
}


