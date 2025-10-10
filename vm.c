//gcc -O3 -march=native -flto vm.c#license:john morris beck gpl2 @ gnu.org
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define x p[a]
#define y i[a]
#define z i[b]
#define k(x,y) case x:y;break;
int main(){int r=3,a,b,c,i[16]={1},f[512],*t=f;void* p[16];p[1]=&t;while(16-(t[r++]=getchar()));while(r){t+=3;a=t[1];b=t[2];c=*t;switch(c){k(0,y-=z)k(1,y<=z)k(3,p[b]=a)k(4,x=(void*)((char*)(x+(int)y)))k(5,memcpy(p[b],x,y))k(6,y?p[b]=malloc(y):free(x);y=(p[b]==NULL))k(7,fread(x,1,z,stdin))k(8,fwrite(x,1,z,stdout);fflush(stdout))k(9,r=0)}}}
