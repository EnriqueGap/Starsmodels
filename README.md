# Starsmodels
C program that solves relativistic and non relativistic 1D equations of structure for stars.
To perform a simulation go to start folder. You can get information about the mass, energies, densities, pressure and metrics for a single star or a family of stars. initial.c has the information about mesh, initial densities and EOS parameters. Modify the Makefile to select between relativistic or classical stars, the integration method and the equation of state. There are two outputs, one in geometrized units and another one in _conventional_ units.
Integration module has runge-kutta 2, 3 and 4 methods and a bisection method to refine the star boundary data.
Also there is a .py script to get more information and plots of the simulation
