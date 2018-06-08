#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void) {

	double a1, a2, b1, b2, c1, c2;
	double ab1, ab2, ac1, ac2, bc1, bc2;
	double d1, d2, e1, e2, f1, f2;
	double velbc, velab, velac;
	double eps = 1;
	char zavorka;

	printf("Bod A:\n");
	if(scanf(" [ %lf , %lf %c", &a1, &a2, &zavorka) != 3 || zavorka != ']'){
		printf("Nespravny vstup.\n");
		return 0;
	}
	printf("Bod B:\n");
	if(scanf(" [ %lf , %lf %c", &b1, &b2, &zavorka) != 3 || zavorka != ']'){
		printf("Nespravny vstup.\n");
		return 0;
	}
	printf("Bod C:\n");
	if(scanf(" [ %lf , %lf %c", &c1, &c2, &zavorka) != 3 || zavorka != ']'){
		printf("Nespravny vstup.\n");
		return 0;
	}

	ab1 = b1 - a1;
	ab2 = b2 - a2;
	ac1 = c1 - a1;
	ac2 = c2 - a2;
	bc1 = c1 - b1;
	bc2 = c2 - b2;

	d1 = b1 + c1 - a1;
	d2 = b2 + c2 - a2;

	e1 = a1 + c1 - b1;
	e2 = a2 + c2 - b2;

	f1 = a1 + b1 - c1;
	f2 = a2 + b2 - c2;

	velab = (ab1*ab1)+(ab2*ab2);
	velac = (ac1*ac1)+(ac2*ac2);
	velbc = (bc1*bc1)+(bc2*bc2);

	//if ((velab+velbc+velac)*DBL_EPSILON <= 1)
		eps = velab+velbc+velac;

	if(fabs(ab1)+fabs(ab2) == 0 || fabs(ac1)+fabs(ac2) == 0 || fabs(bc1)+fabs(bc2) == 0){
			printf("Rovnobezniky nelze sestrojit.\n");
			return 0;
	}

	if(ab1/ab2 <= ac1/ac2 + DBL_EPSILON*1000000 && ab1/ab2 >= ac1/ac2 - DBL_EPSILON*1000000){
			printf("Rovnobezniky nelze sestrojit.\n");
			return 0;
	}

	if(velbc <= velab + velac + DBL_EPSILON*eps && velbc >= velab + velac - DBL_EPSILON*eps){
		if (velab <= velac + DBL_EPSILON*eps && velab >= velac - DBL_EPSILON*eps)
			printf("A': [%.8g,%.8g], ctverec\n", d1, d2);
		else
			printf("A': [%.8g,%.8g], obdelnik\n", d1, d2);
	}
	else if (velab <= velac + DBL_EPSILON*eps && velab >= velac - DBL_EPSILON*eps)
		printf("A': [%.8g,%.8g], kosoctverec\n", d1, d2);
	else
		printf("A': [%.8g,%.8g], rovnobeznik\n", d1, d2);

		if(velac <= velab + velbc + DBL_EPSILON*eps && velac >= velab + velbc - DBL_EPSILON*eps){
			if (velab <= velbc + DBL_EPSILON*eps && velab >= velbc - DBL_EPSILON*eps)
				printf("B': [%.8g,%.8g], ctverec\n", e1, e2);
			else
				printf("B': [%.8g,%.8g], obdelnik\n", e1, e2);
		}
		else if (velab <= velbc + DBL_EPSILON*eps && velab >= velbc - DBL_EPSILON*eps)
			printf("B': [%.8g,%.8g], kosoctverec\n", e1, e2);
		else
			printf("B': [%.8g,%.8g], rovnobeznik\n", e1, e2);

			if(velab <= velac + velbc + DBL_EPSILON*eps && velab >= velac + velbc - DBL_EPSILON*eps){
				if (velac <= velbc + DBL_EPSILON*eps && velac >= velbc - DBL_EPSILON*eps)
					printf("C': [%.8g,%.8g], ctverec\n", f1, f2);
				else
					printf("C': [%.8g,%.8g], obdelnik\n", f1, f2);
			}
			else if (velac <= velbc + DBL_EPSILON*eps && velac >= velbc - DBL_EPSILON*eps)
				printf("C': [%.8g,%.8g], kosoctverec\n", f1, f2);
			else
				printf("C': [%.8g,%.8g], rovnobeznik\n", f1, f2);

	return 0;

}
