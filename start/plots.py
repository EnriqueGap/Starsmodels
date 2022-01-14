import matplotlib.pyplot as plt
import numpy as np
import os
from astropy.io import ascii
print("We get de data!!!")
print(" Now, to see the stars please select between these options:")
print("1 to plot metric and profile for a single relativistic star")
print("2 to plot the profile for a single classical star")
print("3 to plot the profile for a single star in cgs units")
print("4 to plot stellar masses and radius in a range of densities")
print("5 to reproduce the values in Possion et all (classical polytropic star)")

toplot=float(input("Enter: "))


if(toplot==1):
	data=ascii.read('profile.dat',header_start=1)
	plt.figure(figsize=(12,9))
	plt.plot(data['Radius'],data['Energy'],label=r'$m$')
	plt.plot(data['Radius'],data['Radius metric'],label=r'$\alpha$')
	plt.plot(data['Radius'],data['Time metric'],label=r'$a$')
	plt.plot(data['Radius'],data['Rest mass'],label=r'$m_{b}$')
	plt.plot(data['Radius'],data['Pressure'],label=r'$P$')
	plt.plot(data['Radius'],data['Energy density'],label=r'$\epsilon$')
	plt.plot(data['Radius'],data['Barionic density'],label=r'$\rho_{b}$')
	plt.xlabel("r")
	plt.legend()
	plt.grid()
	plt.title('Metric and star profile')
	name='profileandmetric.png'
	plt.savefig(name)
	
if(toplot==2):
	data=ascii.read('profile.dat',header_start=1)
	plt.figure(figsize=(12,9))
	#plt.plot(data['Radius'],data['Energy'],label=r'$m$')
	#plt.plot(data['Radius'],data['Rest mass'],label=r'$m_{b}$')
	plt.plot(data['Radius'],data['Pressure'],label=r'$P$')
	plt.plot(data['Radius'],data['Energy density'],label=r'$\epsilon$')
	plt.plot(data['Radius'],data['Barionic density'],label=r'$\rho_{b}$')
	plt.xlabel("r")
	plt.legend()
	plt.grid()
	plt.title('Star profile')
	name='profile.png'
	plt.savefig(name)

if(toplot==3):
	data=ascii.read('profilecgs.dat',header_start=1)
	plt.subplots(figsize=(12,20),sharex=True)
	
	plt.subplot(5,1,1)
	#plt.xlabel('r (Km)')
	plt.ylabel('(Erg)')
	plt.grid()
	plt.title('Energy')
	plt.plot(data['Radius'],data['Energy'],label=r'$E$')

	plt.subplot(5,1,2)
	#plt.xlabel('r (Km)')
	plt.ylabel('(SM)')
	plt.grid()
	plt.title('Rest Mass')	
	plt.plot(data['Radius'],data['Rest mass'],label=r'$m_{b}$')

	plt.subplot(5,1,3)
	#plt.xlabel('r (Km)')
	plt.ylabel('(Bar)')
	plt.grid()
	plt.title('Pressure')
	plt.plot(data['Radius'],data['Pressure'],label=r'$P$')
	
	plt.subplot(5,1,4)
	#plt.xlabel('r (Km)')
	plt.ylabel(r'($erg/cm^3$)')
	plt.grid()
	plt.title('Energy density')
	plt.plot(data['Radius'],data['Energy density'],label=r'$\epsilon$')

	plt.subplot(5,1,5)
	plt.xlabel('r (Km)')
	plt.ylabel(r'($g/cm^3$)')
	plt.grid()
	plt.title('Barionic density')
	plt.plot(data['Radius'],data['Barionic density'],label=r'$\rho_{b}$')
	
	name='profilecgs.png'
	plt.savefig(name)
	
if(toplot==5):
	data=ascii.read('family.dat',header_start=1)
	k=float(input("K: "))
	n=float(input("n: "))
	gamma = 1 + 1/n
	
	r0 = np.sqrt((n+1)*k/(4*np.pi)*pow(data['Density'],(1-n)/n))
	m0 = 4*np.pi*data['Density']*pow(r0,3)
	chi=np.divide(data['Radius'], r0)
	mu=np.divide(data['Rest mass'], m0)
	np.savetxt('poisson.dat', np.c_[chi,mu])
	
if(toplot==4):
	data=ascii.read('family.dat',header_start=1)
	CR=2*data['Energy']/data['Radius']
	
	plt.subplots(figsize=(12,18))
	
	plt.subplot(3,1,1)
	plt.xscale("log")
	plt.xlabel(r'$\rho_{b}$')
	plt.ylabel(r'$M$')
	plt.grid()
	plt.title('Energy')
	plt.plot(data['Density'],data['Energy'],label=r'$E$')

	plt.subplot(3,1,2)
	plt.xscale("log")	
	plt.xlabel(r'$\rho_{b}$')
	plt.ylabel(r'$2M/R$')
	plt.grid()
	plt.title('Rest Mass')	
	plt.plot(data['Density'],CR,label=r'$m_{b}$')

	plt.subplot(3,1,3)	
	plt.xlabel(r'$r$')
	plt.ylabel(r'$M$')
	plt.grid()
	plt.title('Pressure')
	plt.plot(data['Radius'],data['Energy'],label=r'$P$')
	
	name='massradius.png'
	plt.savefig(name)
	np.savetxt('compactrad.dat', np.c_[data['Density'],CR])
	
os.system('eog '+name)
