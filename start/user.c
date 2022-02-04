#include"main.h"
void userParameters()
{
    /*****************************************************************************
    *******************************EOS PARAMETERS*********************************
    ******************************************************************************/
    //Polytropic EOS parameters K is in geometrized units
    //Set TRUE to make account the parameters
    k=1, n=1, Gamma= 1 + 1/n;

    //Generealized Piecewise Polytropic parameters
    //Perform the integration using EOS for the core & crust
    gpp=NC;                             
    //Perform the integration using EOS for the crust only
    //gpp=CRUST
    //Perform the integracion using EOS for the core only
    //gpp=CORE
    
    coreparam=&bhf;                     //EOS to use in the Core
    crustparam=&sly4crust;              //EOS to use in the crust


    /*****************************************************************************
    ********************SINGLE STAR PROFILE PARAMETERS****************************
    ******************************************************************************/
    //Mesh parameters
    xi=0, xf=3;                         //Initial and Final Points
    num=40000, tpaso=(xf-xi)/num;       //Number of points and step

    //Initial mass density in CGS units
    rhoc =0.42;
    //You can use convertDensity to enter mass density in CGS units and rhoc will be in cgs units
    //rhoc=convertDensity(SMTH,CGS);

    /*****************************************************************************
    ********************GROUP OF STARS PROFILES PARAMETERS************************
    ******************************************************************************/
    //Lower limit in mass density
    rhoi=0.01;
    //Upper limit in mass density
    rhof=0.9;
    //Mass density mesh parameters
    nDensity=1000, stepDensity=(rhof-rhoi)/nDensity;
}
