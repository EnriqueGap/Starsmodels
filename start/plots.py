import matplotlib.pyplot as plt
from astropy.io import ascii
data=ascii.read('mass.dat',header_start=1)


cr=2*data['Energy']/data['Radius']
plt.figure(figsize=(12,9))
plt.plot(data['Radius'],data['Energy'],label=r'$m$')
#plt.plot(data['Density'],data['Rest mass'],label=r'$\alpha$')
#plt.plot(data['Density'],cr,label=r'$\alpha$')
#plt.xscale('log')
plt.xlabel(r'$\rho_{b}$')
plt.legend()
plt.grid()
plt.savefig('mass.png')

"""
pre=K*rho**gamma
ener=(pre/K)**(1/gamma) + pre/(gamma-1)

l0=sqrt(3/(4*pi))*K**(1/(2*(gamma-1)))
lam=pre/ener
cr=2*m/r
rl=r/l0
ml=m/l0
plt.plot(rl,ml, label='ml')
plt.legend()"""





