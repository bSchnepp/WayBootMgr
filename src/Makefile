## Copyright (c) 2017 Brian Schnepp
##
## Permission is hereby granted, free of charge, to any person obtaining a copy
## of this software and associated documentation files (the "Software"), to deal
## in the Software without restriction, including without limitation the rights
## to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
## copies of the Software, and to permit persons to whom the Software is
## furnished to do so, subject to the following conditions:
##
## The above copyright notice and this permission notice shall be included in all
## copies or substantial portions of the Software.
##
## THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
## IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
## FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
## AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
## LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
## OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
## SOFTWARE.

TARGET = BOOTX64.efi
LD = ld.lld
CC = clang

CPU_ARCH = x86_64

##Change this as necessary.
GNU_EFI_LOC = $$HOME/gnu-efi

INC = $(GNU_EFI_LOC)/inc
LIB = $(GNU_EFI_LOC)/$(CPU_ARCH)
EFILIB = $(GNU_EFI_LOC)/$(CPU_ARCH)/gnuefi
EFI_CRT = $(EFILIB)/crt0-efi-$(CPU_ARCH).o
EFI_LDS = $(GNU_EFI_LOC)/gnuefi/elf_$(CPU_ARCH)_efi.lds
INCLUDE_LOCAL = ../include

CFLAGS = -I$(INC) -I$(INC)/$(CPU_ARCH) -I$(INCLUDE_LOCAL) -I$(INC)/protocol -fPIC -fshort-wchar -mno-red-zone -Wall -Wextra -DEFI_FUNCTION_WRAPPER -fno-stack-protector
LDFLAGS = -nostdlib -znocombreloc -T $(EFI_LDS) -shared -Bsymbolic -L $(EFILIB) -L $(LIB) $(EFI_CRT) 

ARTIFACTS = main.o

all: $(TARGET)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@	

BOOTX64.so: $(ARTIFACTS)
	$(LD) $(LDFLAGS) $(ARTIFACTS) -o $@ -lgnuefi

%.efi: %.so
	objcopy -j .text -j .sdata -j .data -j .dynamic -j .dynsym  -j .rel -j .rela -j .reloc --target=efi-app-$(CPU_ARCH) $^ $@

clean:
	rm *.o *.so
## I know I'm too lazy to do this the Makefile way.
