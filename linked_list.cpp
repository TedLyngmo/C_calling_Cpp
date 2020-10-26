#include "linked_list.hpp"
#include "linked_list.h"

#include <new>

// ----------------------------------------------------------------------------
// This is the C++ part of the library
// ----------------------------------------------------------------------------

// explicit instantiation
template class std::forward_list<int>;

// ----------------------------------------------------------------------------
// This is the C interface part of the library
// ----------------------------------------------------------------------------

extern "C" {

// ----------------------------------------------------------------------------
// Some helpers
// ----------------------------------------------------------------------------
using flint = std::forward_list<int>;
using flintiterator = std::forward_list<int>::iterator;

flint& get(forward_list_int o) {
    return *static_cast<flint*>(o.obj);
}

flintiterator& get_it(forward_list_int_iterator i) {
    return *static_cast<flintiterator*>(i.obj);
}
// ----------------------------------------------------------------------------

forward_list_int ForwardList_int_Create() {
    return {new(std::nothrow) flint};
}

void ForwardList_int_Destroy(const forward_list_int o) {
    delete static_cast<const flint*>(o.obj);
}

void ForwardList_int_PushFront(forward_list_int o, int value) {
    get(o).push_front(value);
}

forward_list_int_iterator ForwardList_int_Begin(forward_list_int o) {
    return {new(std::nothrow)flintiterator{get(o).begin()}};
}

forward_list_int_iterator ForwardList_int_End(forward_list_int o) {
    return {new(std::nothrow)flintiterator{get(o).end()}};
}

void ForwardList_int_Iterator_Inc(forward_list_int_iterator* i) {
    ++get_it(*i);
}

bool ForwardList_int_Iterator_Eq(forward_list_int_iterator a, forward_list_int_iterator b) {
    return get_it(a) == get_it(b);
}

bool ForwardList_int_Iterator_Neq(forward_list_int_iterator a, forward_list_int_iterator b) {
    return get_it(a) != get_it(b);
}


int ForwardList_int_Iterator_GetValue(forward_list_int_iterator i) {
    return *get_it(i);
}

void ForwardList_int_Iterator_Destroy(forward_list_int_iterator i) {
    delete static_cast<std::forward_list<int>::iterator*>(i.obj);
}

} // extern "C"
