
#ifndef L__CHBCLIB__H
#define L__CHBCLIB__H

#include <stdbool.h>

typedef struct chbclib_strq_cl {
  bool (*m_add) ( void  *srf_aa, char *rg_a );
  // Adds a new string to the queue. Failure to do so is a
  // fatal-error to the program if the objects 'erat' value
  // is 0. Other wise, the boolean return value will let
  // the calling program know whether or not the operation
  // was a success.
} chbclib_strq_cl;

typedef struct chbclib_strq_obst {
  chbclib_strq_cl *cls;
  void *prv;
  int eract;
} chbclib_strq_obst;
typedef chbclib_strq_obst *chbclib_strq_obj;
typedef chbclib_strq_obj *chbclib_strq_obh;

chbclib_strq_obj chbclib_strq_new ( int rg_a );
// Creator function for the default implementation
// of "chbclib_strq" objects. Failure to create an
// object is a fatal-error for the program.
// The only argument (<rg_a>) has a value of 1 if
// it is to return NULL upon failure, and 0 if it
// is to throw a fatal-error to the program upon
// failure.

#endif


