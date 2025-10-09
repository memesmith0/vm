//vm.c john morris beck the license to use this code is gpl2
//test io gcc vm.c -o vm && echo "io_oo_xj" | ./vm
//create -1                    : -n1-n1
//create 0                     : -01
//add 1 and 1                  : -2n-2n
//create the number 32         : -an-an-an-b1-ba-c1-cb-cb-d1
//                             : -dc-e1-ed-ed-f1-fe-g1-gf-gf
//mov a to b                   : -h1-hg-hg-hg-xh-zh-znbxb
//echo "-n1-n1-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-on-onoo_.__" | ./vm #prints &
#include <stdio.h>
#include <stdlib.h>
#define k(x,y)case x:y;break;
#define g r->p
#define a r[(g+1)->n]
#define b r[(g+2)->n]
int main(){typedef struct M{int n;struct M *p;}m;int i=256*32;m r[i],*t=&r[256];while(i--){r[i-1].p=&r[1];r[i].n=1;}g=t;while('\n'!=((t++)->n=getchar()));
    while(g->n){switch(g->n){
      k('-',a.n-=b.n)
	k('<',a.n=a.n<b.n)
	k('i',a.n=getchar())
	k('o',putchar(a.n))
	k('.',fflush(stdout))
	k('b',a.p->p=b.p->p;a.p->n=b.p->n)
	k('j',a.p+=a.n)
	k('m',a.n?b.p=malloc(sizeof(m)*a.n):free(b.p);a.n=b.p==NULL)
    default: return 0;}
    g+=3;
  }
}
