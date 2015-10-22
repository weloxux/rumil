#include <stdlib.h>
#include <signal.h>
#include <curses.h>
#include "rumil.h"

int main () {
  int active = TRUE;
  
  // TEMPORARY CODE: assume we don't open a file, but create a new one
  
  
  (void) signal(SIGINT, quit); // Accept termination requests, and handle them nicely
  
  (void) initscr();
  keypad(stdscr, TRUE);  // enable keyboard mapping
  (void) nonl();
  (void) cbreak(); 
  (void) echo();
  
  while (active == TRUE) { // Main program starts here
    char c = getch();
    
    
    
    if (c == KEY_ESC) {
      active = FALSE;
    }
  }
    

  quit(0);
}

struct action {
  char type[5]; // TODO: Determine whether 5-character names are long enough
  char *content;
};

static void quit(int sig) { // Gracefully quit
  endwin();
  
  printf("Thanks for using Rumil");
  exit(sig);
}
