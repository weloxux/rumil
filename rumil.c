#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcat
#include <signal.h>
#include <curses.h>
#include "rumil.h"

int main () {
  int active = TRUE;
  char c;
  Buffer filebuffer;
    
  // TEMPORARY CODE: assume we don't open a file, but create a new one
  newbuffer(1024, filebuffer);
  
  (void) signal(SIGINT, quit); // Accept termination requests, and handle them nicely
  
  (void) initscr();
  keypad(stdscr, TRUE);  // enable keyboard mapping
  (void) nonl();
  (void) cbreak(); 
  (void) echo();
  
  while (active == TRUE) { // Main program starts here
    //printf("%x\n", filebuffer);
    
    c = getchar(); // Get new character
    
    
    if (strlen(filebuffer.content) >= filebuffer.size) {
      rebuffer(1024, filebuffer); // Add 1024 bytes to buffer
    }
    
    strcat(filebuffer.content, &c); // Add new character
    
    active = !(c == KEY_ESC);
    
  }

  quit(0);    
}

struct action {
  char type[5]; // TODO: Determine whether 5-character names are long enough
  char *content;
};

static void quit (int sig) { // Gracefully quit
  endwin();
  
  exit(sig);
}
