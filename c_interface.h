#ifndef C_INTERFACE_H_4056319C_FCCB_11EA_9958_90B11C0C0FF8
#define C_INTERFACE_H_4056319C_FCCB_11EA_9958_90B11C0C0FF8

#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif

#define ValidObj(o)                                 \
    do {                                            \
        if((o).obj == NULL) {                       \
            printf(stderr, "%s: NULL\n", __func__); \
            abort();                                \
        }                                           \
    } while(0)

/* A wrapper for a C++ Cube object pointer */
typedef struct {
    void* obj;
} cube_t;

cube_t Cube_Create(int side);
int Cube_Side(const cube_t c);
int Cube_Volume(const cube_t c);
void Cube_Destroy(const cube_t c);

#ifdef __cplusplus
}
#endif

#endif
