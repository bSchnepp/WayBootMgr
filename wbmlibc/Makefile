##Change this as necessary.
GNU_EFI_LOC = $$HOME/gnu-efi

LD = ld.lld
CC = clang

INCLUDE_LOCAL = ../include
CPU_ARCH = x86_64

INC = $(GNU_EFI_LOC)/inc
INC_ARCH = $(INC)/$(CPU_ARCH)

CFLAGS = -I$(INCLUDE_LOCAL) -I$(INC) -I$(INC_ARCH) -fPIC -fshort-wchar -mno-red-zone -Wall -Wextra -DEFI_FUNCTION_WRAPPER -fno-stack-protector 
LDFLAGS = -nostdlib -znocombreloc -T $(EFI_LDS) $(EFILIB) -L $(LIB) $(EFI_CRT) 

ARTIFACTS = libc.ob
TARGET = libc.so

SOURCE_FILES = stdlib.o

all: $(TARGET)
	mv $(TARGET) ../src/stdlib.so

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -shared

%.so: $(SOURCE_FILES)
	##$(CC) $(SOURCE_FILES) -o libc.ob
	mv $(SOURCE_FILES) $(TARGET)	##brilliant.

clean:
	#rm *.o *.rawelf *.ob	//OK if calling from parent directory.

##TODO: Do this properly without weird hacks and mess and all.
