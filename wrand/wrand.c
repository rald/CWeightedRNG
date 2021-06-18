#include "wrand.h"

double drand() {
    return rand()/(RAND_MAX+1.0);
}

WR_Data WR_Init(double *w,int n) {
    WR_Data data;
    data.w=w;
    data.n=n;
    data.s=0;
    for(int i=0; i<data.n; i++) {
        data.s+=data.w[i];
    }
    return data;
}

int WR_NextIndex(WR_Data data) {
    double r=drand()*data.s;
    for(int i=0; i<data.n; i++) {
        if(r<data.w[i]) return i;
        r-=data.w[i];
    }
}
