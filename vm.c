//vm.c john morris beck the license to use this code is gpl2 found at gnu.org
//compile with:gcc -std=c99 -O3 -march=native -flto vm.c -o vm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define x p[a]
#define y i[a]
#define z i[b]
#define v void*
#define k(x,y) case x:y;break;
int main(){int r=3,a,b,c,i[16],f[512],*t=f;v p[16];*i=1;*p=(v)p;p[1]=&t;while(11-(t[r++]=getchar()));while(r){t+=3;a=t[1];b=t[2];c=*t;switch(c){k(0,y-=z)k(1,y=y<z)k(2,x=(v)((char*)(x+(int)y)))k(3,*(int*)p[b]=(int)*(int*)x)k(4,*(v*)p[b]=*(v*)x)k(5,y?p[b]=malloc(y):free(x);y=(p[b]==NULL))k(6,fread(x,1,z,stdin))k(7,fwrite(x,1,z,stdout);fflush(stdout))k(8,r=0)}}}
