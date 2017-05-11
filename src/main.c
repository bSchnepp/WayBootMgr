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
// For now, we do the lazy thing and just slap this EFI section on top of the Canine kernel and make it work that way.

#include <efi.h>
#include <efilib.h>
#include "fs/common.h"

#define CODE_NAME "\tAlpha Aligator"

void PrintMsg(char* msg)
{
	//Just to get annoying casts out of the way.
	Print((CHAR16*)msg);
	Print(L"\n");
}

EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
	InitializeLib(ImageHandle, SystemTable);	//Do some GNUEFI magic and load up the MSABI stuff that EFI wants.

	PrintMsg("Starting up Waypoint...\nYou're currently using: ");
	PrintMsg(CODE_NAME);


	ExitBootServices();
	return EFI_SUCCESS;
}
