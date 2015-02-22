
#include <chbclib.h>
#include <chorebox.h>
#include <stdbool.h>


static bool st_meth_add ( void  *srf_aa, char *rg_a );




typedef struct st_privato {
  chorebox_str_list *qfront;
  chorebox_str_list **qback;
} st_privato;

// st_r_oba = type: chbclib_strq_obj
#define st_r_oba (*((chbclib_strq_obh)srf_aa))
// Private parts ...
#define st_r_pr ((st_privato *)(st_r_oba->prv))

static chbclib_strq_cl st_mainclass =
{
  st_meth_add // m_add
};


chbclib_strq_obj chbclib_strq_new ( int rg_a )
{
  chbclib_strq_obj lc_ret;
  bool lc_noyet;
  st_privato *lc_prv;
  
  
  // Now comes the part where we mallocate the memory for the main
  // object.
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
  lc_ret->eract = rg_a;
  
  
  
  
  // And we now will mallocate the private parts.
  lc_noyet = true;
  if ( rg_a == 1 )
  {
    lc_ret->prv = malloc(sizeof(st_privato));
    if ( (lc_ret->prv) == NULL )
    {
      free(lc_ret);
      return NULL;
    }
    lc_noyet = false;
  }
  if ( lc_noyet )
  {
    lc_ret->prv = chorebox_mlc(sizeof(st_privato));
  }
  
  
  // Now we will make the privates comprehensible - and set them up.
  lc_prv = (st_privato *)(lc_ret->prv);
  lc_prv->qfront = NULL;
  lc_prv->qback = &(lc_prv->qfront);
  
  
  
  // Now we assign the object to a class of matching type:
  lc_ret->cls = &st_mainclass;
  
  
  // Now the object is set up and ready to deploy.
  return lc_ret;
}


static bool st_meth_add ( void  *srf_aa, char *rg_a )
{
  bool lc_noyet;
  chorebox_str_list *lc_nuitm; // The new item added to the queue
  
  // Yes - it's a simple return-without-error if st_r_oba is NULL.
  // We can't consult st_r_oba->eract because it doesn't exist if
  // st_r_oba is NULL.
  if ( st_r_oba == NULL ) return false;
  
  
  // Now we mallocate the basic node of the new item.
  lc_noyet = true;
  if ( st_r_oba->eract == 1 )
  {
    lc_nuitm = (chorebox_str_list *)malloc(sizeof(chorebox_str_list));
    if ( lc_nuitm == NULL ) { return false; }
    lc_noyet = false;
  }
  if ( lc_noyet )
  {
    lc_nuitm = (chorebox_str_list *)chorebox_mlc(sizeof(chorebox_str_list));
    lc_noyet = false;
  }
  lc_nuitm->str = NULL;
  
  // If the provided string is null, we now attach it and are done.
  if ( rg_a == NULL )
  {
    (*(st_r_pr->qback))->nex = lc_nuitm;
    st_r_pr->qback = &(lc_nuitm->nex);
    return true;
  }
  
  // If we are still here, it is our task to copy the provided string
  // and include it in the node.
  lc_noyet = true;
  if ( st_r_oba->eract == 1 )
  {
    if ( !(chorebox_apend_string_rsl(&(lc_nuitm->str),rg_a) ) )
    {
      free(lc_nuitm);
      return false;
    }
    lc_noyet = false;
  }
  if ( lc_noyet )
  {
    chorebox_apend_string(&(lc_nuitm->str),rg_a);
    lc_noyet = false;
  }
  
  
  // If we have gotten this far, we should just connect the node, and
  // call the operation a success.
  (*(st_r_pr->qback))->nex = lc_nuitm;
  st_r_pr->qback = &(lc_nuitm->nex);
  return true;
}


