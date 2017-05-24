##auto-generated license header is probably unnecessary, if it isn't, well, license.txt in root directory then.

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
INCLUDE_LIBC = ../wbmlibc

CFLAGS = -I$(INC) -I$(INC)/$(CPU_ARCH) -I$(INCLUDE_LOCAL) -I$(INCLUDE_LIBC) -I$(INC)/protocol -fPIC -fshort-wchar -mno-red-zone -Wall -Wextra -DEFI_FUNCTION_WRAPPER -fno-stack-protector
LDFLAGS = -nostdlib -znocombreloc -T $(EFI_LDS) -shared -Bsymbolic -L $(EFILIB) -L $(LIB) $(EFI_CRT) 

ARTIFACTS = main.o gui.o

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@	

BOOTX64.so: $(ARTIFACTS)
	$(LD) $(LDFLAGS) $(ARTIFACTS) -o $@ -lgnuefi

%.efi: %.so
	objcopy -j .text -j .sdata -j .data -j .dynamic -j .dynsym  -j .rel -j .rela -j .reloc --target=efi-app-$(CPU_ARCH) $^ $@

clean:
	rm *.o *.so
## I know I'm too lazy to do this the Makefile way.
