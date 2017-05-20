/*
 Copyright (c) 2017 Brian Schnepp

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

// This should be a very early prototype for the filesystem magic we'll do in Waypoint proper.
// System calls should be emulated here and all that. (Sans the prefixes, OWaysys is going to be basically syscalls minus the prefixes anyway.)
// Again, nothing serious in here really, just enough to eventually boot a Canine kernel on an New Technology File System partition (or ideally ext2/3/4).
// We actually will prefer a custom filesystem, maybe something like F2FS or BTRFS or XFS but more "Waypointy". [ie, more than just *NIX permissions.]


struct Fs_File
{
	char* name;
	struct Fs_File* parent;
	unsigned long long int children_num;
	struct Fs_File** children;

	unsigned long long int offset_from_root;
	unsigned long long int file_size;
}Fs_File;


struct Filesystem
{
	struct  Fs_File* root;
	char* identifier;
	char* drive_letter;
	int partition;
}Filesystem;

struct Fs_File* current_file;

void ChangeDirectory(struct Fs_File* newcwd);
struct Fs_File GetCurrentDirectory();

//__
char* GetFileName(struct Fs_File* file);
char* SetFileName(struct Fs_File* file);

long long int GetFileNameLength(struct Fs_File* file);
unsigned long long int GetNumberOfChildren(struct Fs_File* file);

struct Fs_File* GetParent(struct Fs_File* file);
struct Fs_File* GetChild(struct Fs_File* file, int num);
struct Fs_File** GetChildren(struct Fs_File* file);

//__
void CreateFile(struct Fs_File* parent, char* name);
void DeleteFile(struct Fs_File* file);

