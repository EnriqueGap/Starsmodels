#include"main.h"

int main(){
//Creates de .dat files with specific headers, in this files all the info about the star will be saved
//Includes date and time of the simulation
createFile();
//check the parameters related to the initial conditions and mesh introduced by the user
//Check the EOS involved during the integration
checkParameters();
/*Perform the integration of a single or multiple stars. Check the initial parameters, Calls the rk, 
bisection methods and the save solutions array when neccesary*/
integration();
}
