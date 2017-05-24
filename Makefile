all:
	cd wbmlibc/ && $(MAKE)
	cd src/ && $(MAKE)
	mv src/BOOTX64.efi build/BOOTX64.efi

clean:
	cd wbmlibc/ && $(MAKE) clean && cd ../src/ && $(MAKE) clean
	rm build/BOOTX64.efi
