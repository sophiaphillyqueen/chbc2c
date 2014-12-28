
#include "chbc2c.h"

int main ( int argc, char **argv, char **env )
{
  chbclib_argpro_ptr lc_procopt;
  
  
  // Let us register the command-line environment to the "libchorebox" library.
  chorebox_command_line(argc,argv,env);
  
  // Let us make sure 
  
  // Let us set up the command-line options
  lc_procopt = mn_command_options();
  
  // And then we process the command-line according
  // to the options specified.
  lc_procopt->cls->m_cmline(&lc_procopt,argv,argc);
  
  // Well. If we got this far, the run has obviously
  // been successful. However, before we call it quits,
  // we need to channel any yet-unchanneled output to
  // Standard Output.
  chbclib_flushout(lc_procopt->msc,stdout);
  fflush(stdout);
  
  return 0;
}

