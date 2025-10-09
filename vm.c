//vm.c john morris beck the license to use this code is gpl2 found at gnu.org
//compile with:gcc -std=c99 -O3 -march=native -flto vm.c -o vm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define d r[a]
#define e g[a]
#define f g[b]
#define k(x,y)case x:y;break;
int i=256,g[256],z[8192],a,b,c;void* r[256];int main(){int *h=z,x=1;while(i--){g[i]=1;r[i]=&r[1];}i=getc(stdin);while('\n'-(z[i++]=getc(stdin)));while(x){a=*(h+1);b=*(h+2);c=*h;switch(c){k(0,e=e-f)k(1,e=e<f)k(2,h=(int*)d)k(3,d=(void*)((char*)d+(int)e))k(4,f=e;r[b]=d)k(5,r[b]=malloc(e);e=(r[b]==NULL))k(6,free(d))k(7,fread(d, 1, f, stdin))k(8,fwrite(d, 1, f, stdout))k(9,fflush(stdout))k(10,x=0)}h+=3;}}
