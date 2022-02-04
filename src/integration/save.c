/* If P is positive then y has valid values and its must to be saved.
Later in the bisection method this values will be neccesary
*/
#include"main.h"
void saveSolution(double *x,double y[],double yaux[],double tpaso)
{
    double aux=*x+tpaso;
    /*The runge kutta methods calculate the values of pressure, masses and
    time metric function, to get the right values of densities and radial
    metric function we need to calculate this with the ecuation of state */
    eos(aux,y,RHO);
    for (int i=0; i<N; i++) yaux[i]=y[i];
    *x=aux;
}
