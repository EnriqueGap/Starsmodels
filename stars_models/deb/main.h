#include <stdio.h>
#include <math.h>
#define PI acos(-1)
#define FINAL 1				//punto fina de la integración
#define N 4					/* número de ecuaciones en el sistema
			   			y dimensión del array */
FILE *data;
FILE *data2;

#define M 0
#define P 1
#define RHO 2
#define BAR 3

void runge4( double x, double y[], double step, double (*f)(double x, double y[], int i));
void runge3( double x, double y[], double step, double (*f)(double x, double y[], int i));
void runge2( double x, double y[], double step, double (*f)(double x, double y[], int i));
double  f(double x, double y[], int i);
double  g(double x, double y[], int i);
