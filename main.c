#include "cube.h"

#include <stdio.h>

void show(const cube_t c) {
    printf("Side  : %d\n", Cube_Side(c));
    printf("Volume: %d\n", Cube_Volume(c));
}

int main() {
    cube_t c = Cube_Create(5);

    show(c);

    Cube_Destroy(c);

    printf("Done.\n");
}
