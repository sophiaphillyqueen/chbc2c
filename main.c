
#include "chbc2c.h"

int main ( int argc, char **argv, char **env )
{
  // Let us register the command-line environment to the "libchorebox" library.
  chorebox_command_line(argc,argv,env);
}

