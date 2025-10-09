//vm.c john morris beck the license to use this code is gpl2 found at gnu.org
//compile with:gcc -std=c99 -O3 -march=native -flto vm.c -o vm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define x p[a]
#define y i[a]
#define z i[b]
#define k(x,y) case x:y;break;
int a,b,c,i[256],f[8192];void* p[256];int main(){int *t=f,r=3;*i=1;*p=(void*)p;while(r){t+=3;a=*(t+1);b=*(t+2);c=*t;switch(c){k(0,y=y-z)k(1,y=y<z)k(2,t=(int*)x)k(3,x=(void*)((char*)x+(int)y))k(4,z=y;p[b]=x)k(5,p[b]=malloc(y);y=(p[b]==NULL))k(6,free(x))k(7,fread(x,1,z,stdin))k(8,fwrite(x,1,z,stdout))k(9,fflush(stdout))k(10,r=0)k(11,f[r++]=getc(stdin))}}}

