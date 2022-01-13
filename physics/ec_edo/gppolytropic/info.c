#include "main.h"
static void makeCrust();
static void makeNuclear();
static void makeNuclearwCrust();
static void completeCore(core *eos);
static void plot(core eos);

void checkEOS()
{
    printf("You selected the Generalized Piecewise Polytropic Equation as EOS.\n");
    printf("Please choose:\n");
    do{
        printf("Use only nuclear EOS enter 1.\n");
        printf("Use only crust EOS enter 2.\n");
        printf("Use nuclear and crust EOS enter 3.\n");
        scanf("%d",&gpp);
    }while(gpp!=1 && gpp!=2 && gpp!=3);

    if(gpp==1) makeNuclear();
    else if(gpp==2) makeCrust();
    else if(gpp==3) makeNuclearwCrust();
}

static void makeNuclear()
{

    apr.gamma[2]=3.310, apr.gamma[1]=3.452, apr.gamma[0]=3.169;
    apr.k[0]=pow(10,-33.210);
    completeCore(&apr);

    bhf.gamma[2]=2.618, bhf.gamma[1]=2.774, bhf.gamma[0]=3.284;
    bhf.k[0]=pow(10,-35.016);
    completeCore(&bhf);

    fps.gamma[2]=2.199, fps.gamma[1]=2.652, fps.gamma[0]=3.147;
    fps.k[0]=pow(10,-32.985);
    completeCore(&fps);

    h4.gamma[2]=1.562, h4.gamma[1]=2.333, h4.gamma[0]=2.514;
    h4.k[0]=pow(10,-23.310);
    completeCore(&h4);

    kde0v.gamma[2]=2.803, kde0v.gamma[1]=2.835, kde0v.gamma[0]=2.967;
    kde0v.k[0]=pow(10,-30.250);
    completeCore(&kde0v);

    //plot(apr);
}

static void completeCore(core *eos)
{
    eos->rho0=0;
    eos->rho[2]=convertDensity(rhoc,CGS), eos->rho[1]=pow(10,14.99), eos->rho[0]=pow(10,14.87);
    eos->a[0]=-1;
    eos->lambda[0]=0;

    for (int i=0; i<2; i++){
        eos->k[i+1]		=eos->k[i]*(eos->gamma[i]/eos->gamma[i+1])*pow(eos->rho[i],eos->gamma[i]-eos->gamma[i+1]);

        eos->lambda[i+1]	=eos->lambda[i] + (1 - (eos->gamma[i]/eos->gamma[i+1]))*eos->k[i]*pow(eos->rho[i],eos->gamma[i]);

        eos->a[i+1]		=eos->a[i] + eos->gamma[i]*eos->k[i]*pow(eos->rho[i],eos->gamma[i]-1)*(eos->gamma[i+1] - eos->gamma[i])/( (eos->gamma[i+1]-1)*(eos->gamma[i]-1) );
    }

    for (int i=0; i<3; i++) eos->pre[i]=eos->k[i]*pow(eos->rho[i],eos->gamma[i]) + eos->lambda[i];
}

static void makeCrust()
{
    sly4crust.rho[4]=5.317E11, sly4crust.rho[3]=3.350E11, sly4crust.rho[2]=1.826E8, sly4crust.rho[1]=6.285E5, sly4crust.rho[0]=0;

    sly4crust.k[4]=1.746E-8, sly4crust.k[3]=-7.957E29, sly4crust.k[2]=1.662E-6, sly4crust.k[1]=5.726E-8, sly4crust.k[0]=5.214E-9;

    sly4crust.gamma[4]=1.382, sly4crust.gamma[3]=-1.842, sly4crust.gamma[2]=1.269, sly4crust.gamma[1]=1.440, sly4crust.gamma[0]=1.611;

    sly4crust.lambda[4]=7.077E8, sly4crust.lambda[3]=1.193E9, sly4crust.lambda[2]=-6.025E3, sly4crust.lambda[1]=-1.354, sly4crust.lambda[0]=0;

    sly4crust.a[4]=8.208E-3, sly4crust.a[3]=1.035E-2, sly4crust.a[2]=-5.278E-4, sly4crust.a[1]=-1.861E-5, sly4crust.a[0]=0;

    for (int i=0; i<5; i++) sly4crust.pre[i]=sly4crust.k[i]*pow(sly4crust.rho[i],sly4crust.gamma[i]) + sly4crust.lambda[i];

}

static void makeNuclearwCrust()
{

apr.rho0=2.676E14;

bhf.rho0=1.912E14;

fps.rho0=2.491E14;

h4.rho0=3.547E14;

kde0v.rho0=2.730E14;

kde0v1.rho0=2.709E14;

mpa1.rho0=1.781E14;

ms1.rho0=2.748E14;

ms1b.rho0=2.390E14;

qhc19.rho0=1.313E14;

rs.rho0=1.771E14;

sk255.rho0=2.817E14;

sk272.rho0=1.903E14;

ski2.rho0=1.826E14;

ski3.rho0=1.865E14;

ski4.rho0=1.939E14;

ski5.rho0=1.761E14;

ski6.rho0=1.943E14;

skmp.rho0=1.739E14;

skop.rho0=1.379E14;

sly2.rho0=1.987E14;

sly230a.rho0=1.739E14;

sly4.rho0=1.975E14;

sly9.rho0=1.080E14;

wff1.rho0=2.817E14;

}

/*static void plot(core eos)
{
double paso=rhoc/100;
double aux,pre;
for (int i=0; i*paso<=rhoc; i++){

aux=denconv(i*paso,CGS);

if (aux>=eos.rho[2]){
pre=eos.k[2]*pow(aux,eos.gamma[2]) + eos.lambda[2];
}

else if (aux>=eos.rho[1]){
pre=eos.k[1]*pow(aux,eos.gamma[1]) + eos.lambda[1];
}

if (aux>=eos.rho[0]){
pre=eos.k[0]*pow(aux,eos.gamma[0]) + eos.lambda[0];
}

aux=denconv(aux,GEO);
pre=preconv(pre,GEO);
fprintf(data2, "%.8E\t%.8E\n",aux,pre);
}

}*/
