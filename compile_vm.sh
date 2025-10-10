#!/bin/sh
#license:john morris beck gpl2 @ gnu.org
compile_vm(){ cat << 'EOF' > /dev/shm/vm.c && gcc -std=c99 -O3 -march=native -flto /dev/shm/vm.c -o "$1vm"
//license:john morris beck gpl2 @ gnu.org
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){int x=0,y=16,z=0,i[16],f[512],*t=f;void* p[16];while(y--){i[y]=1;p[y]=&t;}for(;x<512;t[x++]=getchar());while(1){x=t[1];y=t[2];z=*t;switch(z){case 0:i[x]-=i[y];break;case 1:i[x]=i[x]<i[y];break;case 3:p[y]=p[x];break;case 4:i[y]=i[x];break;case 5:p[y]=*(void**)p[x];break;case 6:*(void**)p[y]=p[x];break;case 7:p[y]=(void*)((char*)(p[y]+(int)i[x]));break;case 8:i[x]?p[y]=malloc(i[x]):free(p[y]);i[x]=(p[y]==NULL);break;case 9:fread(p[y],1,i[y],stdin);break;case 10:fwrite(p[y],1,i[y],stdout);fflush(stdout);break;case 11:exit(0);}t+=3;}}
EOF
  } ; compile_vm "$1";
