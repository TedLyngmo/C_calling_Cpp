#ifndef LINKED_LIST_H_691A0D52_189F_11EB_BE34_90B11C0C0FF8
#define LINKED_LIST_H_691A0D52_189F_11EB_BE34_90B11C0C0FF8

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Wrappers for a C++ object pointers */
typedef struct { void* obj; } forward_list_int;
typedef struct { void* obj; } forward_list_int_iterator;

forward_list_int ForwardList_int_Create();
void ForwardList_int_Destroy(const forward_list_int);

void ForwardList_int_PushFront(forward_list_int, int);

/* iterator support */
forward_list_int_iterator ForwardList_int_Begin(forward_list_int);
forward_list_int_iterator ForwardList_int_End(forward_list_int);

void ForwardList_int_Iterator_Inc(forward_list_int_iterator*);

bool ForwardList_int_Iterator_Eq(forward_list_int_iterator, forward_list_int_iterator);
bool ForwardList_int_Iterator_Neq(forward_list_int_iterator, forward_list_int_iterator);

int ForwardList_int_Iterator_GetValue(forward_list_int_iterator);
void ForwardList_int_Iterator_Destroy(forward_list_int_iterator);

#ifdef __cplusplus
}
#endif

#endif
