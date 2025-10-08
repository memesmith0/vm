//vm.c gpl2 john morris beck
#include <stdio.h>
#include <stdlib.h>
#define k(x,y)case x:y;break;
#define a r[(t+1)->n]
#define b r[(t+2)->n]
typedef struct M{int n;struct M *p;}m; //dynamic datastructure
m r[8192],*i,*t=&r[0];
int main(){
  
  for(int i=8192;i--;){r[i].p=&r[1];r[i].n=0;} //sanitize memory
  
  t=&r[256];i=t;r['0'].n=0;r['1'].n=1;r['~'].p=r;r['>'].p=&r['<'];
  
  while('x'!=((i++)->n=getchar())); //fetch instructions from stdin until 'x'
  
  while(t->n){
    switch(t->n){
      k('-',a.n-=b.n) //sub
	k('<',a.n=a.n<b.n) //lessthan
	k('i',a.n=getchar()) //input
	k('o',putchar(a.n))  //output
	k('r',a.p=b.p->p;a.n=b.p->n) //read
	k('w',b.p->n=a.n;b.p->p=a.p) //write
	k('j',a.p+=a.n) //jump
	k('m',a.p=malloc(sizeof(m)*a.n)) //malloc
	k('f',free(a.p))} //free
    t+=3;
  }
}
//mov 0 to  b: w0>w<b
//mov 1 to  a: w1>w<a
//mov 1 to  c: w1>w<c
//negate    c: -bcwb>w<c
//add 1 to  a: -ac_

//test io
//io_oo_xj
