# Starsmodels
C program that solves relativistic and non relativistic 1D equations of strcuture for stars.
The star_profile and stelar_mr are the main modules. The first one gives the informations of the mass, energies, densities, pressure and metrics for a selected central density. stelar_mr gives a family of stars in function of a central densities' mesh. Both modules has a python script to plot the solutions.
There are two outputs, one in geometrized units and another one in _conventional_ units.

Modify the makefile to select between nr.c (non relativistic strcuture) and tov.c (TOV equations)
Modify ec_do module to change the equation of state. 

integration module has runge-kutta 2, 3 and 4 methods and a bisection method to refine the star boundary data.

libs has the .h scripts. be careful if modified this.
