
#ifndef LOCAL_INC__CHBC2C_IN__H
#define LOCAL_INC__CHBC2C_IN__H

#include <chorebox.h>
#include <chbclib.h>

chbclib_argpro_ptr mn_command_options ( void );
// This function is called by main(). It creates the
// argument-line processing object and sets up all
// the options and other such stuff it will need.
// This function will not return with failure - as
// it will sooner end the program with error than
// do so. It's sole return value is the object it
// creates.


#endif

