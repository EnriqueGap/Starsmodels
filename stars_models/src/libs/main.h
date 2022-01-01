#include <stdio.h>
#include <math.h>
#include "user.h"			//Physical and user variables library
#define N 7				//dimension of array

#define M 0				//energy
#define P 1				//pressure
#define ALPHA 2			//metric function of time coordinate
#define A 3				//metric function of radial coordinate
#define RHO 4				//energy density
#define RHOB 5				//mass density
#define MB 6				//mass (baryonic)

#define GEO 1
#define CGS 2

FILE *data;				//star output
FILE *datacgs;				//star output in cgs units

//Output and export of data
void saveSolution(double *x,double y[],double yaux[],double tpaso);
void printSolution(double x, double y[]);
void printCGS(double x, double y[]);

//Functions related to the ODE system and its physical variables
void checkDensity();
void eos(double x, double y[], int i);
double energy(double rhoc);
void ic(double x, double y[], double yaux[]);
double  f(double x, double y[], int i);
double  g(double x, double y[], int i);
double  h(double x, double y[], int i);

//Bisection method and Runge-Kutta methods
void bisection(double *x,double y[],double yaux[],double tpaso);
void runge4( double x, double y[], double step, double (*f)(double x, double y[], int i));
void runge2( double x, double y[], double step, double (*f)(double x, double y[], int i));
void runge3( double x, double y[], double step, double (*f)(double x, double y[], int i) );

//Mass and energy densities and pressure conversions CGS <-> Geometrized Units
double convertDensity (double input, int i);
double convertPressure (double input, int i);
double convertEnergy (double input, int i);

//Debug and tests functions/outputs
FILE *data2;
void printDeb(double x,double y[]);
