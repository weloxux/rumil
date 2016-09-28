#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcat
#include <signal.h>
#include <stdbool.h>
#include "rumil.h"

int main() {
  int active = true;
  char c;
  Buffer filebuffer;
  
  printf("creating buffer");
  newbuffer(1024, filebuffer);
  printf("created buffer");
  
  while (active == TRUE) {
    c = getchar(); // Get new character
    printf("In: %s; Buffer: %s", c, filebuffer);
    if (strlen(filebuffer.content) >= filebuffer.size) {
      rebuffer(1024, filebuffer); // Add 1024 bytes to buffer
    }
    strcat(filebuffer.content, &c); // Add new character
    active = !(c == KEY_ESC);  
  }
  
  printf("terminated without crashes");
  return 0;
}
