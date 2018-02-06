#include <stdio.h>
#include <stdlib.h>
#include <math.h>



unsigned long pgcd (unsigned long a, unsigned long b);
unsigned long algo_euclide (unsigned long a, unsigned long b);
unsigned long nbs_premier (unsigned long phi);

int main()
{
    unsigned long p = 1069;
	unsigned long q = 1153;

	unsigned long n = 0, phi = 0, d = 0, e = 0;

	n = p*q;			//module de chiffrement
	phi = (p-1)*(q-1);		//indice d'euler
	e = nbs_premier(phi);		//exposant de chiffrement

	d = algo_euclide(phi,e);

    printf("||  //  ====\n|| //  ||\n||//   ||\n||\\     ==== \n|| \\   || \n||  \\   ====\n\n");
	printf("Clé publique (%ld,%ld)\nClé Privée (%ld)\n\n\n\nDétail calculs : \n\n",n,e,d);
	printf("Nombre premiers de départ : p = %ld, q =  %ld\n",p,q);
	printf("Module de chiffrement : n = %ld\nIndice d'euler :  phi = %ld\nExposant de Chiffrement : d = %ld\n",n,phi,e);
	printf("PGCD de e et phi : %ld \n",pgcd(e,phi));


	return 0;
}

unsigned long nbs_premier (unsigned long phi){

	unsigned long e = 0;
	e = rand(); //donne un nombre aléatoire
	while(e>=phi)
	{
        e-=300;
	}

	while (pgcd(e,phi)!=1)
	{
        e++;
    }

	return e;
}


unsigned long pgcd (unsigned long a, unsigned long b){

	unsigned long c = 0;
	if(a<b){
		c=a;
		a=b;
		b=c%b;
	}
	while((a%b)!=0){
		c=a;
		a=b;
		b=c%b;
	}
	return b;
}

unsigned long algo_euclide (unsigned long a, unsigned long b){

	unsigned long r1=a, r2=b, u1=1, v1=0, u2=0, v2=1;
	unsigned long q = 0,r3=0, u3=0, v3 = 0;



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
