import matplotlib.pyplot as plt
from astropy.io import ascii
import numpy as np
data=ascii.read('profile.dat',header_start=0)

k=1
n=1
gamma=1 + 1/n
rhob0=0.61

r0 = np.sqrt((n+1)*k/(4*np.pi)*pow(rhob0,(1-n)/n))
m0 = 4*np.pi*rhob0*pow(r0,3)

R=float(input("Radius: "))
M=float(input("Mass: "))

chi=R/r0
mu=M/m0

print("n\tGamma\tchi\tmu")
print(n, gamma, chi, mu)
plt.figure(figsize=(12,9))
#plt.plot(data['Radius'],data['Energy'],label=r'$m$')
#plt.plot(data['Radius'],data['Rest mass'],label=r'$m_{b}$')
#plt.plot(data['Radius'],data['Pressure'],label=r'$P$')
#plt.plot(data['Radius'],data['Energy density'],label=r'$\epsilon$')
plt.plot(data['Radius']/R,data['Barionic density']/rhob0,label=r'$\rho_{b}$')

plt.xlim(0,1)
plt.xlabel("r")
plt.legend()
plt.grid()
plt.title('Star profile')
plt.savefig('clprofile.png')
