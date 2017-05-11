#WayBootMgr
___

WayBootMgr is the (U)EFI-compliant bootloader for Waypoint.
It is __separate__ from Waypoint so that it can be used for other operating systems or otherwise reused.
(Also because GNU-EFI isn't 100% clear on it's license, the headers/code say it's BSD and the page says it's BSD but the documentation says GPL so... yeah! Assume the worst in that case.)

WayBootMgr will first target supporting the ext2 file system (as this will also be Waypoint's "native" filesystem until cnfs is finished)
Ideally, I would also like to support additional filesystems like NTFS, BTRFS, XFS, and EXT4, particularly the first and last ones. But Ext2 is the priority.
___

WayBootMgr's first few builds should export as 'BOOTX64.EFI' and be placed in an ESP. Later on, I'll write some scripts to have it moved out and be it's own entry in the system's default boot manager.
___

TODOS:
	- ABSOLUTELY EVERYTHING.
	- Switch to EDK2/Tianocore whenever I can learn it.
	- Support ext2 at all.
	- Support multiboot 1 and 2.
	- Support running ELF executables as kernels, ala GNU GRUB.
	- Get it to boot a hypothetical Canine kernel (get that Hello World K8 kernel out of the ground!!!)
