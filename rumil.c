#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <curses.h>
#include "rumil.h"

int main () {
  int active = TRUE;
  
  int bl = 1;
  char *filebuffer;
  
  // TEMPORARY CODE: assume we don't open a file, but create a new one
  filebuffer = newbuffer(bl);
  
  (void) signal(SIGINT, quit); // Accept termination requests, and handle them nicely
  
  (void) initscr();
  keypad(stdscr, TRUE);  // enable keyboard mapping
  (void) nonl();
  (void) cbreak(); 
  (void) echo();
  
  while (active == TRUE) { // Main program starts here
    char c = getch();
    filebuffer = rebuffer(filebuffer, bl, 1);
    strcat(filebuffer, c);
    
    
    if (c == KEY_ESC) {
      active = FALSE;
    }
  }
    

  quit(0, filebuffer);
}

struct action {
  char type[5]; // TODO: Determine whether 5-character names are long enough
  char *content;
};

static void quit (int sig, char * filebuffer) { // Gracefully quit
  endwin();
  
  printf(&filebuffer); // DEBUG CODE
  
  exit(sig);
}
