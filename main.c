#include "cube.h"
#include "linked_list.h"

#include <stdio.h>

void show(const cube_t c) {
    printf("Side  : %d\n", Cube_Side(c));
    printf("Volume: %d\n", Cube_Volume(c));
}

int main() {
    //Use the Cube:
    cube_t c = Cube_Create(5);

    show(c);

    Cube_Destroy(c);

    // use the ForwardList_int:
    forward_list_int fli = ForwardList_int_Create();

    ForwardList_int_PushFront(fli, 4);
    ForwardList_int_PushFront(fli, 3);
    ForwardList_int_PushFront(fli, 2);
    ForwardList_int_PushFront(fli, 1);

    forward_list_int_iterator it = ForwardList_int_Begin(fli),
                              end = ForwardList_int_End(fli);

    for(; ForwardList_int_Iterator_Neq(it, end); ForwardList_int_Iterator_Inc(&it)) {
        printf("%d\n", ForwardList_int_Iterator_GetValue(it));
    }

    ForwardList_int_Iterator_Destroy(it);
    ForwardList_int_Iterator_Destroy(end);

    ForwardList_int_Destroy(fli);

    printf("Done.\n");
}
