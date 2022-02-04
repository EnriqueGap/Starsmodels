#define PI acos(-1)

//cgs units (centimeter, gram, second)
#define G 6.67384E-8			//Gravitational constant cm³g^-1s^-2
#define C 2.99792458E10		//Speed of light cms^-1
#define SM 1.9884E33			//Solar Mass g
#define KM 1E5				//Kilometer cm
#define CONV 1E6			//Conversion 10km=1x10⁶cm

#define ERR 1E-10			//convergence of bisection method
#define RES 0.799274894		//reescale factor of metric function time coordinate
#define N 7				//dimension of array
//Other parameters related to the integrations methods are local variables

//Physics parameters
//Parameters related to equations of state can be initializated in start/user.c
double rhoc, rho;				//central density and energy

double x, 					//radius variable
	y[N], yaux[N],	 			//Solution array
	xi, xf, tpaso, num;			//mesh parameters

double rhoi, rhof, stepDensity, nDensity;	//mesh of densities for integration of multiple stars (EJECUTION=FPROFILE)
