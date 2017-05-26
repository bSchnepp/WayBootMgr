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

//Wrapper around all the UEFI functions, because EFI's ABI is just... weird.
//Remember we need to rewrite every file in gnu-efi/gnuefi/ that doesn't have a BSD header.
//We'll put them in somewhere or something.

// This is a giant header-only file so that we can play with EFI's boot services without the weird EFI ABI.
// Also so you can rip it out, play with it, etc.

#ifndef _UEFI_WAYBOOTMGR_H_
#define _UEFI_WAYBOOTMGR_H_


#include <efi.h>
#include <efilib.h>
 
#define BOOT_ON_ERROR_ANYWAY 1

#if 0
EFI_MEMORY_DESCRIPTOR* memory_map;

UINT32 descriptor_version;
UINTN map_size = 0; 
UINTN map_key; 
UINTN descriptor_size;
#endif

// We'll also put some useful things up here as well, to not bother doing boilerplate later on.

static EFI_SYSTEM_TABLE* system_table;

static inline void Wait(unsigned int seconds)
{
	uefi_call_wrapper(system_table->BootServices->Stall, 1, (seconds * 1000));
}

static inline void Reset(void)
{
	uefi_call_wrapper(ST->ConOut->Reset, 2, ST->ConOut, FALSE);
}

static inline void Panic(int error_code)
{
	//Complain about the error,
	//Halt the system,
	//And then let the user reboot themselves.
}

static inline void Reboot(void)
{
	//TODO
}

static inline EFI_STATUS HandleProtocol(EFI_HANDLE handle, EFI_GUID* protocol, VOID** interface)
{
	return uefi_call_wrapper(system_table->BootServices->HandleProtocol, 3, handle, protocol, interface);
}

static inline EFI_STATUS Exit(EFI_HANDLE image, EFI_STATUS status, UINTN size, CHAR16* reason)
{
	return uefi_call_wrapper(system_table->BootServices->Exit, 4, image, status, size, reason);
}

static inline void CheckError(EFI_STATUS actual, EFI_STATUS expected)
{
	if (BOOT_ON_ERROR_ANYWAY)
	{
		if (actual != expected)
		{
			Print(L"Something went wrong.\nWe'll try to boot your computer anyway.\n");
		}
	}
	else
	{
		Panic(1);
	}
} 

static inline EFI_STATUS GetMemoryMap(UINTN* map_size, EFI_MEMORY_DESCRIPTOR* memory_map, UINTN* map_key, UINTN* descriptor_size, UINT32* descriptor_version)
{
	return uefi_call_wrapper(system_table->BootServices->GetMemoryMap, 5, map_size, memory_map, map_key, descriptor_size, descriptor_version);
}


//These two functions are re-named because GNU-EFI has some with the same names with different arguments.
static inline EFI_STATUS Allocate_Pool(EFI_MEMORY_TYPE type, UINTN size, void** buffer)
{
	return uefi_call_wrapper(system_table->BootServices->AllocatePool, 3, type, size, buffer);
}

static inline EFI_STATUS Free_Pool(void* buffer)
{
	return uefi_call_wrapper(system_table->BootServices->FreePool, 1, buffer);
}

//TODO: implement the rest of the EFI API.

static inline void PrepareSystem(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable)
{
	InitializeLib(ImageHandle, SystemTable);	//Do some GNUEFI magic and load up the MSABI stuff that EFI wants.
	// From here, do the relevant function calls.
	system_table = SystemTable;
}

static inline void ExitBootServices(EFI_HANDLE image_handle, UINTN map_key)
{
	uefi_call_wrapper(system_table->BootServices->ExitBootServices, 2, image_handle, map_key);
}

#endif

