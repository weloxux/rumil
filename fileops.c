#include <stdio.h>
#include <stdlib.h>
#include "rumil.h"

// Empty for now

char * newbuffer (int bl) {
  return (char *) malloc(bl);
}

char * rebuffer (char * filebuffer, int bl, int addlength) {
  return (char *) realloc(filebuffer, bl + addlength);
}