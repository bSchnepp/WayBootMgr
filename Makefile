all:
	cd wbmlibc/ && $(MAKE)
	cd src/ && $(MAKE)
	mv src/BOOTX64.efi build/BOOTX64.efi

clean:
	rm build/BOOTX64.efi
	cd wbmlibc/ && $(MAKE) clean
	cd src/ && $(MAKE) clean
