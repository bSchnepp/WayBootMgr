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

#define CODE_NAME "\tAlpha Aligator"

unsigned char boot_option;	//We're only allowing up to 9, so 'unsigned' doesn't matter, but well, consistency. [- for prev page, = for next page, 0 for first page.]
unsigned long long int page_number;	//For the crazy guy who somehow gets 18363036738 operating systems on one computer.


// Entries...
struct System 
{
	CHAR8* name;
	CHAR8* file_name;
	CHAR8* kernel_options;

	BOOL use_unicode_pathnames;
	BOOL is_chainload;

	CHAR8* device;

	CHAR16* init_rd;
	CHAR16* kernel_location;
}System;

struct BootOption
{
	System* system;
	BootOption* next;	//Linked lists!
}BootOption;



struct BootOption options_root;

System* CreateSystem(CHAR8* name, CHAR8* file_name, CHAR8* kernel_options, BOOL use_unicode_pathnames, BOOL is_chainload, CHAR8* device, CHAR16* init_rd, CHAR16* kernel_location)
{
	//Create the relevant system and return it's address.
	struct System sys;
	sys.name = name;
	sys.file_name = file_name;
	sys.kernel_options = kernel_options;
	sys.use_unicode_pathnames = use_unicode_pathnames;
	sys.is_chainload = is_chainload;
	sys.device = device;
	sys.init_rd = init_rd;
	sys.kernel_location = kernel_location;
	
	return &sys;
}

uint64_t GetSystemCount()
{
	uint64_t count = 0;
	while (!options_root.next != NULL)
	{
		count++;
	}
	return count;
}


//TODO
EFI_MEMORY_DESCRIPTOR* memory_map;

UINT32 descriptor_version;

UINTN map_size = 0; 
UINTN map_key; 
UINTN descriptor_size;

void PrintMsg(char* msg)
{
	//Just to get annoying casts out of the way.
	Print((CHAR16*)msg);
	Print(L"\n");
}

EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable) 
{
	PrepareSystem(ImageHandle, SystemTable);
	PrintMsg("Starting up Waypoint...\nYou're currently using: ");
	PrintMsg(CODE_NAME);


	//Here's the meat of the bootloader.
	//We'll initialize the filesystems, load up a simple EFI gui, make the boot options available, when ENTER is pressed, we'll load the OS selected.
	//GetMemoryMap(
	ExitBootServices(ImageHandle, map_key);
	return EFI_SUCCESS;
}
