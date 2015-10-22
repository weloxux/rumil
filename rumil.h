#define TRUE 1
#define FALSE 0
#define KEY_ESC '\x1B'

// define types
typedef struct {
  int size;
  char * content;
} Buffer;
    
// rumil.c
static void quit (int sig);
struct action;

//fileops.c
void newbuffer (int size, Buffer filebuffer);
void rebuffer (int inc, Buffer filebuffer);