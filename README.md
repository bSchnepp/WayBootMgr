# WayBootMgr

WayBootMgr is the (U)EFI-compliant bootloader for Waypoint.
It is __separate__ from Waypoint so that it can be used for other operating systems or otherwise reused.
(Also to legally-speaking, protect Waypoint.)

WayBootMgr will first target supporting the ext2 file system (as this will also be Waypoint's "native" filesystem until CNFS is finished)
EXT2 right now is the priority, plus, we'll be writing FS drivers from absolutely nothing. Much to do!
___

WayBootMgr's first few builds should export as 'BOOTX64.EFI' and be placed in an ESP. Later on, I'll write some scripts to have it moved out and be it's own entry in the system's default boot manager.
___

TODOS:

	- ABSOLUTELY EVERYTHING.
	
	- Keep GNU-EFI as a dependency, but anything that's not BSD licensed will NOT be used. Inject source & rebuild if necessary into the library. (Keep GPL away from WayBootMgr.)
	
	- Support ext2 at all.
	
	- Support multiboot 1 and 2.
	
	- Support running ELF executables as kernels, ala GNU GRUB.
	
	- Get it to boot a hypothetical Canine kernel (get that Hello World K8 kernel out of the ground!!!)
	
	- Indeed be a boot manager plus boot loader, and have the FOX logo for Canine/Waypoint show up or something. Or whatever the logo ends up being.

___

## License
WayBootMgr (it's own sources) is distributed under the terms of the MIT license. See 'LICENSE.TXT' for details.
WayBootMgr requires external software however, which is distributed under the terms of the BSD 3-clause license.
See 'LICENSE_THIRDPARTY.txt' for details on that code. That file should be also redistributed with binary releases, for legal reasons.
