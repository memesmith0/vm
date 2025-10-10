//gcc -O3 -march=native -flto vm.c#license:john morris beck gpl2 @ gnu.org
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define w p[b]
#define x p[a]
#define y i[a]
#define z i[b]
#define k(x,y) case x:y;break;
int main(){int a=0,b,c,i[16]={1},f[512],*t=f;void* p[16]={&t};while(16-(t[a++]=getchar()));while(1){a=t[1];b=t[2];c=*t;switch(c){k(0,y-=z)k(1,y<=z)k(3,w=x)k(4,z=y)k(5,w=*(void**)x)k(6,*(void**)w=x)k(7,x=(void*)((char*)(x+(int)y)))k(8,y?w=malloc(y):free(x);y=(w==NULL))k(9,fread(x,1,z,stdin))k(10,fwrite(x,1,z,stdout);fflush(stdout))k(11,exit(0))}t+=3;}}
