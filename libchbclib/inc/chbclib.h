
#ifndef L__CHBCLIB__H
#define L__CHBCLIB__H

#include <stdio.h>
#include <stdbool.h>

typedef struct chbclib_mscs {
  
  char *typ;
  // This char-pointer is *not* a string-reference, but a pointer to
  // a character-location who's content-value is insignificant, but
  // who's address is all-important. This character flagships a given
  // structure-type --- so that the address of that character will in
  // effect be the unique identifier of said structure-type.
  
  void *loc;
  // This char-pointer points to the location of the data variable
  // herein referenced.
  
  struct chbclib_mscs *nex;
  // This structure implements a linked-list.
  
} chbclib_mscs;
typedef chbclib_mscs *chbclib_mscp;

typedef struct chbclib_argpro_cls {
  bool (* m_cmline) ( void *rgo_a, char **rg_a, size_t rg_b );
  // This method is the one by which the command-line can be processed
  // by this object -- once it has been equipped with all the necessary
  // options and other significances.
} chbclib_argpro_cls;

typedef struct chbclib_argpro_obj {
  chbclib_argpro_cls *cls;
  chbclib_mscp msc;
} chbclib_argpro_obj;
typedef chbclib_argpro_obj *chbclib_argpro_ptr;
typedef chbclib_argpro_ptr *chbclib_argpro_hnd;


bool chbclib_flushout ( chbclib_mscp rg_a, FILE *rg_b );
// This function searches rg_a for a char-queue object, and upon
// finding it, it empties said char-queue into the standard C-type
// FILE-stream specified in rg_b.
//   If it does not find the char-queue object, then it returns
// 'true', becsause that means that there are no chars waiting
// to be emptied, and therefore that this function's mission is
// already accomplished before it is ever invoked.
//   There are only two ways that this function can return
// 'false'. One is if the char-queue object is of an implementation
// that is not only capable of failure, but capable of returning
// to the calling program in the event of said failure. The other
// is if the FILE stream given in 'rg_b' is NULL (that being the
// only way this function can fail if the char-quere object is of
// the default class-implementation).
//   It should be warned that this function does print operations
// to the specified FILE-stream, but it's description does not
// call for it to call fflush() on it - so the calling program
// may still need to do that separately.


#endif


