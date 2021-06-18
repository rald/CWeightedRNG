#include<stdio.h>
#include<string.h>

#include "wrand.h"

char *repeat(char *s,int n) {
	char *rv=calloc(strlen(s)*n+1,sizeof(*rv));
	for(int i=0;i<n;i++) {
		strcat(rv,s);
	}
	return rv;
}

int main(int argc,char **argv) {

    int i;
    char *d[]= {"Skin","Dust","Item","Rare Item",
                "Epic Item","Legendary Item"
               };

    double w[]= { 20.00, 30.00, 40.00, 6.00, 3.00, 1.00};

    int n=sizeof(w)/sizeof(*w);
    int *s=malloc(n*sizeof(*s));
    int ts=0;
    double p,tw=0,tp=0;

    WR_Data wrData;

	char *c=NULL;
	int cn=44;

    srand(time(NULL));

    wrData=WR_Init(w,n);

    for(i=0; i<n; i++) s[i]=0;

    for(i=0; i<1000; i++) {
        s[WR_NextIndex(wrData)]++;
    }

    printf("%3s: %-16s %7s %4s %7s\n","#","Item","Weight","N","Percent");

    c=repeat("-",cn);
    printf("%s\n",c);
    free(c);

    for(i=0; i<n; i++) {
        p=(double)s[i]/1000*100;
        ts+=s[i];
        tw+=w[i];
        tp+=p;
        printf("%3i: %-16s %6.2f%% %4i %6.2f%%\n",i,d[i],w[i],s[i],p);
    }

    c=repeat("-",cn);
    printf("%s\n",c);
    free(c);

    printf("%21s %6.2f%% %4i %6.2f%%\n","Total:",tw,ts,tp);

    return 0;
}
