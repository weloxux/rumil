#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rumil.h"

void newbuffer (int size, Buffer filebuffer) {
  filebuffer.size = size;
  filebuffer.content = (char *) malloc(size);
}

void rebuffer (int inc, Buffer filebuffer) {
  char * tempcontent = malloc(filebuffer.size + inc);
  strcpy(tempcontent, filebuffer.content);
  filebuffer.content = tempcontent;
  filebuffer.size += inc;
}
