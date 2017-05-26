#include <stdlib.h>

struct Pixel;
struct GuiOption;
struct Pointer;

int width;
int height;

struct Pixel* screen;

int Init(void);
void Terminate(void);
int CreateGui(void);

