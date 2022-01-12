#include <stdio.h>
#include <math.h>
#include <time.h>
#include "user.h"			//Physics and user variables library

#define M 0				//energy
#define P 1				//pressure
#define ALPHA 2			//metric function of time coordinate
#define A 3				//metric function of radial coordinate
#define RHO 4				//energy density
#define RHOB 5				//mass density
#define MB 6				//mass (baryonic)

#define GEO 1				//Geometrized units [L]=10km
#define CGS 2				//CGS units

FILE *data;				//star output
FILE *datacgs;				//star output in cgs units

/*=======================================================================
==========================Main functions===============================
=======================================================================*/

/*Creates de .dat files with specific headers, in this files all the info about the star will be saved
Includes date and time of the simulation*/
void createFile();

/*check the parameters related to the initial conditions and mesh
Calls checkDensity() & initial() to initialize the values*/
void checkParameters();

/*Perform the integration of a single or multiple stars. Calls the rk, bisection methods and the save
solutions array when neccesary*/
void integration();

/*Closes the .dat files and export a file with information of the simulation parameters*/
//void exportInfo();	

/*=======================================================================
===========================Other functions===============================
=======================================================================*/
//Output and export of data
void saveSolution(double *x,double y[],double yaux[],double tpaso);
void printSolution(double x, double y[]);
void printCGS(double x, double y[]);

//Functions related to the ODE system and its physical variables and initial conditions
//Set the initial conditions
void checkDensity();
void initial();
double energy(double rhoc);
void ic(double x, double y[], double yaux[]);
//Related equation of state
void eos(double x, double y[], int i);
//ODE system
double  f(double x, double y[], int i);
double  g(double x, double y[], int i);
double  h(double x, double y[], int i);

//Bisection method and Runge-Kutta methods
void bisection(double *x,double y[],double yaux[],double tpaso);
void rk( double x, double y[], double step, double (*f)(double x, double y[], int i));

//Mass and energy densities and pressure conversions CGS <-> Geometrized Units
double convertDensity (double input, int i);
double convertPressure (double input, int i);
double convertEnergy (double input, int i);

//Debug and tests functions/outputs
FILE *info;
FILE *data2;
void printDeb(double x,double y[]);





	
	
	
