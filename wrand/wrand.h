#ifndef WRAND_H
#define WRAND_H

#include<stdlib.h>
#include<time.h>

typedef struct WR_Data WR_Data;

struct WR_Data {
    double *w;
    int n;
    double s;
};

WR_Data WR_Init(double *w,int n);
int WR_NextIndex(WR_Data data);

double drand();

#endif
