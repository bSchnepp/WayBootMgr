#include "stdlib.h"

void* malloc(UINTN size)
{
	void* ptr;

	EFI_STATUS status = Allocate_Pool(EfiLoaderData, size, &ptr);
	if (status != EFI_SUCCESS)
	{
		ptr = ((void*)0);
	}

	return ptr;
}

void free(void* pointer)
{
	Free_Pool(pointer);	//EFI does it for us.
}
