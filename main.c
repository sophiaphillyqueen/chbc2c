
#include "chbc2c.h"

int main ( int argc, char **argv, char **env )
{
  int lc_indox;
  chbclib_strq_obj lc_que;
  
  // Let us register the command-line environment to the "libchorebox" library.
  chorebox_command_line(argc,argv,env);
  
  lc_que = chbclib_strq_new(0);
  
  // And let us shove all command-line arguments (not including the argument
  // name) into a string-queue.
  lc_indox = 1;
  while ( lc_indox < argc )
  {
    lc_que->cls->m_add(&lc_que,argv[lc_indox]);
    lc_indox++;
  }
  
  return mn_use_args(lc_que);
}

