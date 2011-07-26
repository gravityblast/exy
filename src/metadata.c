#include "metadata.h"

FIBITMAP* BitmapFromImagePath(const char* path) {
  FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
  fif = FreeImage_GetFileType(path, 0);
  FIBITMAP *bitmap = FreeImage_Load(fif, path, 0);

  return bitmap;
}

void PrintMetaData(FIBITMAP *bitmap) {
  FITAG *tag = NULL;
  FIMETADATA *mdhandle = NULL;

  unsigned model;
  for (model = 0; model < 12; model++) {
    mdhandle = FreeImage_FindFirstMetadata((FREE_IMAGE_MDMODEL)model, bitmap, &tag);  
    if (mdhandle) {  
      do {
        const char *value = FreeImage_TagToString((FREE_IMAGE_MDMODEL)model, tag, NULL);
        printf("%s (%s):\n  %s\n", FreeImage_GetTagDescription(tag), FreeImage_GetTagKey(tag), value);
      } while(FreeImage_FindNextMetadata(mdhandle, &tag));
      printf("\n");
    }
    FreeImage_FindCloseMetadata(mdhandle);
  }
}

void LoadAndPrintMetadata(const char* path) {
#ifdef FREEIMAGE_LIB
  FreeImage_Initialise();
#endif

  FIBITMAP *bitmap = BitmapFromImagePath(path);
  if (bitmap) {
    PrintMetaData(bitmap);
  } else {
    printf("Error loading %s\n", path);
  } 
  
#ifdef FREEIMAGE_LIB
	FreeImage_DeInitialise();
#endif
}