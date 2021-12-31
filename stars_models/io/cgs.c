//10Km = 1x10⁶cm = CONV

#include "main.h"
//cgs mass density [g/cm³] to geometrized density [L⁻²] units: [10Km]^-2
double densityConversion (double input, int i)
{
double output;

if (i==GEO){					//cgs to geometrized
output=(input*G/(C*C))*(CONV*CONV);		// [rho*G/c²]
}

if (i==CGS){					//geometrized to cgs
output=input*C*C/(G*CONV*CONV);		// [rho]*[c²/G]
}

return output;
}

//cgs pressure [g/cm*s²] to geometrized pressure [L⁻²] units: [10Km]^-2
double presssureConversion (double input, int i)
{
double output;

if (i==GEO){					//cgs to geometrized
output=(input*G/(C*C*C*C))*(CONV*CONV);	// [P*G/c⁴]
}

if (i==CGS){					//geometrized to cgs
output=input*C*C*C*C/(G*CONV*CONV);		// [P]*[c⁴/G]
}

return output;
}

//cgs energy density [g/cm*s²] to geometrized energy density [L⁻²] units: [10Km]^-2
double energyConversion (double input, int i)
{
double output;

if (i==GEO){					//cgs to geometrized
output=(input*G/(C*C*C*C))*(CONV*CONV);	// [E*G/c⁴]
}

if (i==CGS){					//geometrized to cgs
output=input*C*C*C*C/(G*CONV*CONV);		// [E]*[c⁴/G]
}

return output;
}
