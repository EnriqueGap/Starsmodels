#define NUCLEAR 1
#define CRUST 2
#define NC 3
typedef struct{
	double rho[5];
	double pre[5];
	double k[5];
	double gamma[5];
	double lambda[5];
	double a[5];
}crust;

crust sly4crust, *crustparam;

typedef struct{
	double rho[3];
	double pre[3];
	double k[3];
	double gamma[3];
	double lambda[3];
	double a[3];
	double rho0;
	double pre0;
}core;

core apr, bhf, fps, h4, kde0v, *coreparam,		//EOS=GPPOLYTROPIC
	kde0v1, mpa1, ms1, ms1b, qhc19,
	rs, sk255, sk272, ski2, ski3,
	ski4, ski5, ski6, skmp, skop,
	sly2, sly230a, sly4, sly9, wff1;
double k, n, Gamma;					//EOS=POLYTROPIC

int gpp;
