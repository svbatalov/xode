#include "libcommon.h"
#include "ode.h"
#define STACKSIZE 30

void resize( struct pstack *s)
{
	s->maxsize = (s->maxsize==0)? STACKSIZE : s->maxsize*2;
	s->items   = xrealloc(s->items, s->maxsize*sizeof(void*));
}
void * newstack()
{
	struct pstack *s = xcalloc(1, sizeof(struct pstack));
	return s;
}

//inline
struct pstack * push(struct pstack *s, void* d)
{
	if(s==NULL) s = newstack();
	if(s->size == s->maxsize) resize(s);

	s->items[s->size++] = d;
	return s;
}

//inline
void * pop(struct pstack *s)
{
	if(s->size == 0) panic("pstack underflow");
	else return s->items[--s->size];
}

void * top(struct pstack *s)
{
	if(s->size == 0) return NULL;
	else return s->items[s->size-1];
}
