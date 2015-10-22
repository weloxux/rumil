#define TRUE 1
#define FALSE 0
#define KEY_ESC '\x1B'

// rumil.c
static void quit (int sig);
struct action;

//fileops.c
char * newbuffer (int bl);
char * rebuffer (char *buff, int bl, int addlength);