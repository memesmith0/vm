//vm.c john morris beck the license to use this code is gpl2 found at gnu.org
//compile with:gcc -std=c99 -O3 -march=native -flto vm.c -o vm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define x p[a]
#define y i[a]
#define z i[b]
#define k(x,y) case x:y;break;
int main(){int r=3,a,b,c,i[256],f[8192],*t=f;void* p[256];*i=1;*p=(void*)p;p[2]=&t;while(11-(t[r++]=getc(stdin)));
  while(r){t+=3;a=t[1];b=t[2];c=*t;switch(c){
      k(0,y-=z)
	k(1,y=y<z)
	k(2,x=(void*)((char*)(x+(int)y)))
	k(3,*(int*)p[b]=(int)*(int*)x)
	k(4,*(void**)p[b]=*(void**)x)
	k(5,p[b]=malloc(y);y=p[b]==NULL)
	k(6,free(x))
	k(7,fread(x,1,z,stdin))
	k(8,fwrite(x,1,z,stdout))
	k(9,fflush(stdout))
	k(10,r=0)}}}
