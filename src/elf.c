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

#include <stdlib.h>

#include "uefi.h"
#include "exe/elf.h"

/**
 *	Checks the bit count of the natural registers of the process.
 *	ie, ARM returns 1 and x86-64 returns 2, AArch64 returns 2, etc. etc.
 *	Use this for that one field in e_ident that needs it.
 *
 *	@return size of bits.
 */
uint8_t check_bit_size(void)
{
	if (sizeof(uintn_t) > 4)
	{
		return 2;
	}
	return 1;
}

uint8_t get_wanted_arch(void)
{
#if defined(__x86_64)
	return 62;	//ELF ID for x86-64
#elif defined(__i386__)
	return 3;	//ELF ID for x86
#endif
//TODO: check ARM32 and AARCH64

}

int CheckElfFile(ElfHeader* hdr)
{
	uint8_t h0, h1, h2, h3;
	h0 = hdr->e_ident[0];
	h1 = hdr->e_ident[1];
	h2 = hdr->e_ident[2];
	h3 = hdr->e_ident[3];

	if ( (h0 != 0x7F) || (h1 != 'E') || (h2 != 'L') || (h3 != 'F'))
	{
		return -1;
		//This isn't an ELF file!
	}

	uint8_t procarc = hdr->e_ident[7];
	if (procarc != get_wanted_arch())
	{
		return -2;
		//Wrong architecture!
		//Wishlist: emulator as raw EFI application and continue to run ELF kernel __ANYWAY__ on a virtual machine.
	}
	
	//TODO: rest of checks...
	return 0;
}
