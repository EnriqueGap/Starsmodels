#include"main.h"

int main(){
//Creates de .dat files with specific headers, in this files all the info about the star will be saved
//Includes date and time of the simulation
createFile();
//check the parameters related to the initial conditions and mesh
//Calls checkDensity() & initial() to initialize the values
checkParameters();
/*Perform the integration of a single or multiple stars. Calls the rk, bisection methods and the save
solutions array when neccesary*/
integration();
}
