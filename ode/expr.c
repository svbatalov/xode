/* This file is part of the GNU plotutils package. */

/*
 *
 * Copyright (C) 1982-1994, Nicholas B. Tufillaro.  All rights reserved.
 *
 * GNU enhancements Copyright (C) 1996, 1997, 1998, 1999, 2005, Free 
 * Software Foundation, Inc.
 */

/*
 * expression tree evaluator and expression space management routines
 */

#include "sys-defines.h"
#include "ode.h"
#include "extern.h"

#define NSTACK 30
double stack[NSTACK];
static int nesting = 0;

double
eval (const struct expr *ep)
{
  double *sp;
  double tmp, tmp2;
  struct expr *ep1,
	e2  = {
	  .ex_oper  = O_NOOP,
 	  .ex_value = 0,
 	  .ex_sym   = NULL,
 	  .ex_next  = NULL },
	*ep2 = &e2; // aux. expr used for jumps: ep2->ex_next = <jump target>
  struct sym  *s, *s2, *s3;
  for (sp = &stack[NSTACK]; ep != NULL; ep = ep->ex_next) 
    {
	//FIXME
	// fprintf(stderr, "cmd=%d, stack[%d]: %g\n", ep->ex_oper, &stack[NSTACK]-sp, *sp);
#ifdef DEBUG
      if (sp > &stack[NSTACK])
	panic ("expression stack underflow");
#endif
      if (sp <= stack)
	panic ("stack overflow -- bump NSTACK and recompile");

      switch (ep->ex_oper) 
	{
	case O_CONST:
	  *--sp = ep->ex_value;
	  break;
	case O_IDENT:
	  // XODE
	  if (nesting == 0)
	 	  *--sp = ep->ex_sym->sy_value; // work if replace_bound_vars() used
	  else	// inside a function
		  *--sp = lookup(ep->ex_sym->sy_name)->sy_value;
	  break;
	case O_PLUS:
	  tmp = *sp++;
	  *sp += tmp;
	  break;
	case O_MINUS:
	  tmp = *sp++;
	  *sp -= tmp;
	  break;
	case O_MULT:
	  tmp = *sp++;
	  *sp *= tmp;
	  break;
	case O_DIV:
	  tmp = *sp++;
	  *sp /= tmp;
	  break;
	case O_POWER:
	  tmp = *sp++;
	  if ((tmp != (int)tmp) && (*sp < 0))
	    rterror("negative number to non-integer power");
	  *sp = pow(*sp,tmp);
	  break;
	case O_SQAR:
	  *sp *= *sp;
	  break;
	case O_CUBE:
	  *sp *= *sp * *sp;
	  break;
	case O_INV:
	  *sp = 1. / *sp;
	  break;
	case O_SQRT:
	  if (*sp < 0)
	    rterror("square root of a negative number");
	  *sp = sqrt(*sp);
	  break;
	case O_SIN:
	  *sp = sin(*sp);
	  break;
	case O_COS:
	  *sp = cos(*sp);
	  break;
	case O_TAN:
	  *sp = tan(*sp);
	  break;
	case O_ASIN:
	  *sp = asin(*sp);
	  break;
	case O_ACOS:
	  *sp = acos(*sp);
	  break;
	case O_ATAN:
	  *sp = atan(*sp);
	  break;
	case O_ABS:
	  if (*sp < 0)
	    *sp = -*sp;
	  break;
	case O_EXP:
	  *sp = exp(*sp);
	  break;
	case O_LOG:
	  if (*sp <= 0)
	    rterror("logarithm of non-positive number");
	  *sp = log(*sp);
	  break;
	case O_LOG10:
	  if (*sp <= 0)
	    rterror("logarithm of non-positive number");
	  *sp = log10(*sp);
	  break;
	case O_SINH:
	  *sp = sinh(*sp);
	  break;
	case O_COSH:
	  *sp = cosh(*sp);
	  break;
	case O_TANH:
	  *sp = tanh(*sp);
	  break;
	case O_ASINH:
	  *sp = asinh(*sp);
	  break;
	case O_ACOSH:
	  *sp = acosh(*sp);
	  break;
	case O_ATANH:
	  *sp = atanh(*sp);
	  break;
	case O_FLOOR:
	  *sp = floor(*sp);
	  break;
	case O_CEIL:
	  *sp = ceil(*sp);
	  break;
	case O_J0:
	  *sp = j0(*sp);
	  break;
	case O_J1:
	  *sp = j1(*sp);
	  break;
	case O_Y0:
	  *sp = y0(*sp);
	  break;
	case O_GAMMA:
	  *sp = f_gamma(*sp);
	  break;
	case O_LGAMMA:
	  *sp = F_LGAMMA(*sp);
	  break;
	case O_ERFC:
	  *sp = erfc(*sp);
	  break;
	case O_ERF:
	  *sp = erf(*sp);
	  break;
	case O_INVERF:
	  *sp = inverf(*sp);
	  break;
	case O_NORM:
	  *sp = norm(*sp);
	  break;
	case O_INVNORM:
	  *sp = invnorm(*sp);
	  break;
	case O_NEG:
	  *sp = -*sp;
	  break;
	case O_IGAMMA:
	  tmp = *sp++;
	  *sp = igamma(*sp, tmp);
	  break;
	case O_IBETA:
	  tmp2 = *sp++;
	  tmp = *sp++;
	  *sp = ibeta(*sp, tmp, tmp2);
	  break;
	// XODE
	case O_STARTFUN:
	  // save symtab
	  callstack = push(callstack, (void*) symtab);
	  
	  // pop <arglist>
	  for(s=ep->ex_sym; s; s=s->sy_link)
	  {
		  s2 = salloc();
		  strncpy(s2->sy_name, s->sy_name, NAMMAX);
		  s2->sy_value = *sp++;
		  s2->sy_flags |= SF_INIT;

		  /*
		  // point bound variables in function body to
		  // symtab entries.
		  // This is an optimization. See O_IDENT above.
		  for(ep1=ep->ex_next; ep1; ep1=ep1->ex_next)
			  if(ep1->ex_oper == O_IDENT &&
			     strncmp(ep1->ex_sym->sy_name, s2->sy_name, NAMMAX) == 0)
			  {
				  ep1->ex_sym = s2;
			  }
		   */

	  }
	  //replace_bound_vars(ep->ex_next); // optimization, see O_IDENT case in eval().
	  nesting++;
	  break;
	case O_ENDFUN:
	  s2  = (struct sym  *) pop(callstack);	// old symtab address
	  ep2->ex_next = (struct expr *) pop(callstack); // restore "return address". NOTE: JUMP!
	  ep = ep2;
	  // restore symtab:
	  // delete symbols local to the function
	  s = symtab;
	  symtab = s2;
	  while(1)
	  {
	  	if(s == s2) break;
		s3 = s->sy_link;
		sfree(s);
		s = s3;
	  }
	  nesting--;
	  break;
	case O_CALL:
	  if( ep->ex_sym->sy_expr == NULL)
		{
			char buf[100];
			snprintf(buf, 100, "Undefined function %s called\n",
				 ep->ex_sym->sy_name);
			panic(buf);
		}
	  // save return address
	  callstack = push(callstack, (struct expr *) ep->ex_next);
	  ep2->ex_next = ep->ex_sym->sy_expr;
	  ep = ep2;
	  break;
	default:
	  panicn ("bad op spec (%d) in eval()", (int)(ep->ex_oper));
	}
    }
  return *sp;
}

struct expr *
ealloc (void)
{
  struct expr *ep;
  
  ep = (struct expr *)xmalloc (sizeof(struct expr));
  ep->ex_next = NULL;
  ep->ex_sym = NULL;
  ep->ex_oper = O_NOOP;		/* default */
  return ep;
}

void
efree (struct expr *ep)
{
  if (ep == NULL || ep == &exprzero || ep == &exprone )
    return;
  efree (ep->ex_next);
	  free ((void *)ep);
}

// XODE: recursively make a copy of expression list
struct expr*
ecopy (struct expr *ep)
{
  if (ep == NULL || ep == &exprzero || ep == &exprone )
    return ep;
  struct expr *e = ealloc();
  memcpy((void *)e, (void *)ep, sizeof(struct expr));
  e->ex_next = ecopy(ep->ex_next);
  return e;
}


/*
 * Replace symbols in `ep' by symbols with the same name found in symtab.
 */
void
replace_bound_vars(struct expr *ep)
{
	struct expr *e;
	struct sym  *s;
	for(e=ep; e; e=e->ex_next)
		if(e->ex_oper == O_IDENT)
		{
			s = lookup(e->ex_sym->sy_name);
			e->ex_sym = s;
		}
}
void prsymtab()
{
	struct sym * sp;
	printf("symbol table:\n");
	for(sp = symtab; sp; sp=sp->sy_link)
		printf("(%p)\t%s = %g\t%d\n", sp, sp->sy_name, sp->sy_value, sp->sy_flags);
}
