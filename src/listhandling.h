/*########################
###
###		This Programm
###		falls under the
###		MIT Software
###		license. Check
###		COPYING for 
###		further
###		information.
###
########################*/

#ifndef LISTHANDLING_H
#define LISTHANDLING_H

void *create_element(void **dest, int size);
void delete_element(void **dest, void *e);
void delete_all_elements(void **dest, void (callback)(void **, void *));

typedef struct {
	void *ptr;
	int refs;
} Reference;

typedef struct {
	Reference *ptrs;
	int count;
} RefArray;

extern void *_FREEREF;
#define FREEREF &_FREEREF
#define REF(p) (global.refs.ptrs[(int)(p)].ptr)
int add_ref(void *ptr);
void del_ref(void *ptr);
void free_ref(int i);
#endif