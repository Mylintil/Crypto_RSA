#include <stdlib.h>
#include <stdio.h>

signed short algo_euclide (signed short a, signed short b);

signed short nbs_premier (signed short phi);

signed short pgcd (signed short a, signed short b);

void main(void){
	
	signed short p = 29;
	signed short q = 11;

	signed short n = 0, phi = 0, d = 0, e = 0;

	n = p*q;			//module de chiffrement
	phi = (p-1)*(q-1);		//indice d'euler 
	e = nbs_premier(phi);		//exposant de chiffrement
	d = algo_euclide(e,phi);	
	printf("p = %hd, q =  %hd\n",p,q);	
	printf("n = %hd, phi = %hd, e = %hd , d  = %hd\n",n,phi,e,d); 
	
}

signed short nbs_premier (signed short phi){
	
	signed short e = 0;
	while (pgcd(e,phi)!=1)
	{
		e++;
	}
	if(e>=phi){
		printf("Erreur. e>=phi !!");
	}
	
}

signed short pgcd (signed short a, signed short b){

	signed short c = 0;
	if(a<b){
		c=a;
		a=b;
		b=c%b;
	}
	while(a%b){
		c=a;
		a=b;
		b=c%b;
	}
	return b;
}

signed short algo_euclide (signed short a, signed short b){

	signed short r1=a, r2=b, u1=1, v1=0, u2=0, v2=1;
	signed short q=0, r3=0, u3=0, v3 = 0;


	while(r2 != 0){

		q = r1/r2;
		r3 = r1;
		u3 = u1;
		v3 = v1;
		r1 = r2;
		u1 = u2;
		v1 = v2;
		r2 = r3-q*r2;
		u2 = u3-q*u2;
		v2 = v3-q*v2;
	}
	
	return u1;
}





