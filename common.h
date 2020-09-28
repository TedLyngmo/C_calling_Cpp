#ifndef COMMON_H_33C39FFA_01BC_11EB_AA30_90B11C0C0FF8
#define COMMON_H_33C39FFA_01BC_11EB_AA30_90B11C0C0FF8

#define ValidObj(o)                                 \
    do {                                            \
        if((o).obj == NULL) {                       \
            printf(stderr, "%s: NULL\n", __func__); \
            abort();                                \
        }                                           \
    } while(0)

#endif
