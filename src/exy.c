#include <stdio.h>
#include "metadata.h"

void PrintUsage() {
  printf("Usage:\n");
  printf("  exy IMAGE_PATH\n");
}

int main(int argc, char** argv) {
  argc == 2 ? LoadAndPrintMetadata(argv[1]) : PrintUsage();

  return 0;
}