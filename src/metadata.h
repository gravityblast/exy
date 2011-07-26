#include "FreeImage.h"

FIBITMAP* BitmapFromImagePath(const char* path);
void PrintMetaData(FIBITMAP *bitmap);
void LoadAndPrintMetadata(const char* path);