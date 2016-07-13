#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>
#include "tally.h"

SEXP tally_(SEXP x_) {
  double *x = REAL(x_);
  int n = length(x_);
  
  SEXP out = PROTECT(allocVector(REALSXP, 1));
  REAL(out)[0] = tally(x, n);
  UNPROTECT(1);
  
  return out;
}

static R_CallMethodDef callMethods[] = {
  {"tally_", (DL_FUNC)&tally_, 1},
  {NULL, NULL, 0}
};

void R_init_tallyR(DllInfo *info) {
  R_registerRoutines(info, NULL, callMethods, NULL, NULL);
}
