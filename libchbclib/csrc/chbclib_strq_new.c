
#include <chbclib.h>
#include <chorebox.h>
#include <stdbool.h>

static void st_init ( void );
static void st_meth_add ( void  *srf_aa, char *rg_a );

static chbclib_strq_cl st_mainclass;
static bool st_inited = false;


chbclib_strq_obj chbclib_strq_new ( int rg_a )
{
  chbclib_strq_obj lc_ret;
  bool lc_noyet;
  
  // Before we do anything else, we must be sure that the class has
  // been set up. (Really --- I got to look up how to let C do this
  // for me --- but in the mean time ...)
  st_init();
  
  lc_noyet = true;
  if ( rg_a == 0 )
  {
    lc_ret = (chbclib_strq_obj)chorebox_mlc(sizeof(chbclib_strq_obst));
    lc_noyet = false;
  }
  if ( rg_a == 1 )
  {
    lc_ret = (chbclib_strq_obj)malloc(sizeof(chbclib_strq_obst));
    if ( lc_ret == NULL ) { return lc_ret; }
    lc_noyet = false;
  }
  
  // For now - we will let the fals-exception act like zero:
  if ( lc_noyet )
  {
    lc_ret = (chbclib_strq_obj)chorebox_mlc(sizeof(chbclib_strq_obst));
  }
  
  
  // Now we assign the object to a class of matching type:
  lc_ret->cls = &st_mainclass;
  
  
  // Now the object is set up and ready to deploy.
  return lc_ret;
}


static void st_init ( void )
{
  if ( st_inited ) { return; }
  
  st_mainclass.m_add = st_meth_add;
  
  st_inited = true;
}

static void st_meth_add ( void  *srf_aa, char *rg_a )
{
}


