//vm.c gpl2 john morris beckp
//test io gcc vm.c -o vm && echo "io_oo_xj" | ./vm
//create -1                    : -n1-n1
//create 0                     : -01
//add 1 and 1                  : -2n-2n
//create the number 32         : -an-an-an-b1-ba-c1-cb-cb-d1
//                             : -dc-e1-ed-ed-f1-fe-g1-gf-gf
//mov a to b                   : -h1-hg-hg-hg-xh-zh-znbxb
#include <stdio.h>
#include <stdlib.h>
#define k(x,y)case x:y;break;
#define  g r->p
#define a r[(g+1)->n]
#define b r[(g+2)->n]
int main(){
  int i=8192;typedef struct M{int n;struct M *p;}m; //dynamic datastructure
  m r[8192],*t=&r[256];
  while(i--){r[i].p=&r[1];r[i].n=1;} //sanitize memory
  g=t;
  i=8192-256;while('x'!=((t++)->n=getchar())); //fetch instructions until x


  
  while(g->n){
    switch(g->n){
      k('-',a.n-=b.n) //sub
	k('<',a.n=a.n<b.n) //lessthan
	k('i',a.n=getchar()) //input
	k('o',putchar(a.n))  //output
	k('b',a.p->p=b.p->p;a.p->n=b.p->n) //be
	k('j',a.p+=a.n) //jump
	k('a',a.p=malloc(sizeof(m)*a.n)) //malloc
	k('f',free(a.p))} //free
    g+=3;
  }
}
