# WayBootMgr

WayBootMgr is the (U)EFI-compliant bootloader for Waypoint.
It is __separate__ from Waypoint so that it can be used for other operating systems or otherwise reused.
(Also to legally-speaking, protect Waypoint.)

WayBootMgr currently can only load kernels also located in the ESP. (until FS drivers can be made.)
___

WayBootMgr's first few builds should export as 'BOOTX64.EFI' and be placed in an ESP. Later on, I'll write some scripts to have it moved out and be it's own entry in the system's default boot manager.
___

TODOS:

	- ABSOLUTELY EVERYTHING.
	
	- Keep GNU-EFI as a dependency, but anything that's not BSD licensed will NOT be used. Inject source & rebuild if necessary into the library. (Keep GPL away from WayBootMgr.)
	
	- Support ext2 at all.
	
	- Support multiboot 1 and/or 2.
	
	- Support running ELF executables as kernels, ala GNU GRUB.
	
	- Get it to boot a hypothetical Feral kernel (get that Hello World K8 kernel out of the ground!!!)
	
	- Indeed be a boot manager plus boot loader. Come up with a logo for the Feral kernel (Waypoint's kernel) and use that. Also be able to load Linux or something.
___

I'm trying to rush this, so we can get to kernel programming (the fun part!)
As such, expect code quality to be fairly OK to outright bad.
We'll just refactor and clean up later.

Cureently compiles, but on test hardware (N3700 @ 1.60Ghz), fails to boot.
Probably doing something painfully obviously wrong, looking into it.
___

## License
WayBootMgr (it's own sources) is distributed under the terms of the MIT license. See 'LICENSE.TXT' for details.
WayBootMgr requires external software however, which is distributed under the terms of the BSD 3-clause license.
See 'LICENSE_THIRDPARTY.txt' for details on that code. That file should be distributed with binary releases, for legal reasons.
