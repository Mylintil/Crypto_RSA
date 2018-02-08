#include <stdio.h>
#include <stdlib.h>
#include "PGCD.h"

/*int main(void){
	printf("%hd", PGCD(3,2));
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
