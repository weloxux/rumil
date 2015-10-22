#include <stdlib.h>
#include <signal.h>
#include <curses.h>
#include "rumil.h"

#define FALSE 0
#define TRUE 1

int main () { // Main program starts here
  int active = TRUE;
  char *file;
  char *filename;
  
  (void) signal(SIGINT, quit); // Accept termination requests, and handle them nicely
  
  (void) initscr();
  keypad(stdscr, TRUE);  // enable keyboard mapping
  (void) nonl();
  (void) cbreak(); 
  (void) echo();
  
  while (active == TRUE) {
    int c = getch(); // Get input
    
    active = FALSE;
  }
    

  quit(0);
}

static void quit(int sig) { // Gracefully quit
  endwin();
  
  exit(sig);
}
