//gcc -std=c99 -O3 -march=native -flto vm.c -o vm#license:john morris beck gpl2 @ gnu.org
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define x p[a]
#define y i[a]
#define z i[b]
#define v void*
#define k(x,y) case x:y;break;
int main(){int r=3,a,b,c,i[16]={1},f[512],*t=f;v p[16];*p=(v)p;p[1]=&t;while(16-(t[r++]=getchar()));while(r){t+=3;a=t[1];b=t[2];c=*t;switch(c){k(0,y-=z)k(1,y=y<z)k(2,x=(v)((char*)(x+(int)y)))k(3,memcpy(p[b],x,y))k(4,y?p[b]=malloc(y):free(x);y=(p[b]==NULL))k(5,fread(x,1,z,stdin))k(6,fwrite(x,1,z,stdout);fflush(stdout))k(7,r=0)}}}
