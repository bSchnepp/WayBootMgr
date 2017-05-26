#ifndef _ELF_H_
#define _ELF_H_


#include "../uefi.h"

//Define the various bits and pieces we care about for ELF executables...
//(read: the one time we break 'don't ever use unnecessary #define statements')
#define E_IDENTC 16


typedef uint64_t UINT64;
typedef uint32_t UINT32;
typedef uint16_t UINT16;
typedef uint8_t  UINT8;

typedef uintn_t  UINTN;

//Implement support for ELF as Waypoint's kernel is ELF because [insert a reason here], but also because it was easier for clang. Not doing PE or anything like that.
//(also because I really don't care about supporting gcc at all. If GCC compile the kernel, great! If not, meh? Let someone else patch for GCC, I'm not.)

struct ElfHeader
{
	uint8_t e_ident[E_IDENTC];

	uint16_t e_type;
	uint16_t e_machine;

	uint32_t e_version;

	uintn_t e_entry;
	uintn_t e_phoff;
	uintn_t e_shoff;

	uint32_t e_flags;

	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
}ElfHeader;

struct ElfProgramHeader
{
	uint32_t p_type;
	uint32_t p_flags;
	
	uintn_t  p_offset;
	uintn_t  p_vaddr;
	uintn_t  p_paddr;
	uintn_t  p_filesz;
	uintn_t  p_memsz;
	uintn_t  p_align;
}ElfProgramHeader;

struct ElfSectionHeader
{
	uint32_t sh_name;
	uint32_t sh_type;
	uintn_t  sh_flags;
	uintn_t  sh_addr;
	uintn_t  sh_offset;
	uintn_t  sh_size;
	uint32_t sh_link;
	uint32_t sh_info;
	uintn_t  sh_addralign;
	uintn_t  sh_entsize;
}ElfSectionHeader;

enum ElfType
{
	ET_NONE = 0,
	ET_REL = 1,
	ET_EXEC = 2
};


#endif
