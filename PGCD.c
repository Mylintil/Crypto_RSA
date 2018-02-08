#include <stdio.h>
#include <stdlib.h>
#include "PGCD.h"

/*int main(void){
	ulong A = 30000;
	ulong B = 20000;
	ulong *pA = &A;
	ulong *pB = &B;

	find_prime(pA,pB);

	printf("*pA : %lu, *pB : %lu\n", *pA, *pB);
	printf("%hd\n",is_prime(A,B));
	printf("A : %lu, B : %lu", A, B);
	return 0;
}*/
ulong PGCD(ulong a, ulong b){
	ulong c=0;
	if(a<b){
		c=a;
		a=b;
		b=c;
	}
	while(a%b!=0){
		c=a;
		a=b;
		b=c%b;
	}
	return b;
}

ushort is_prime(ulong a, ulong b){
	if(PGCD(a,b)==1){
		return 1;
	}
	else{
		return 0;
	}
}


void find_prime(ulong* a, ulong* b){
	while(!is_prime(*a, *b)){
		*a=*a-1;
	}
}
