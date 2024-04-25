#ifndef LV_H_INCLUDED
#define LV_H_INCLUDED

#endif // LV_H_INCLUDED
#include "ABB.h"

struct nodelv {
     vendedor vipd;
     struct nodelv *next;
} ;

typedef struct nodelv nodolv;

typedef struct {
    nodolv *acc;

} lista;

void initlv(lista *lv) {
    (*lv).acc = NULL;
}

