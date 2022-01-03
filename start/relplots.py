import matplotlib.pyplot as plt
from astropy.io import ascii

print("1 for metric and profile for a single relativistic star")
print("2 for metric and profile for a single classical star")
print("3 for profile for a single star in cgs units")

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
	plt.savefig('profileandmetric.png')
	
if(toplot==2):
	data=ascii.read('profile.dat',header_start=1)
	plt.figure(figsize=(12,9))
	plt.plot(data['Radius'],data['Energy'],label=r'$m$')
	plt.plot(data['Radius'],data['Rest mass'],label=r'$m_{b}$')
	plt.plot(data['Radius'],data['Pressure'],label=r'$P$')
	plt.plot(data['Radius'],data['Energy density'],label=r'$\epsilon$')
	plt.plot(data['Radius'],data['Barionic density'],label=r'$\rho_{b}$')
	plt.xlabel("r")
	plt.legend()
	plt.grid()
	plt.title('Star profile')
	plt.savefig('profile.png')
	




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
	
	plt.savefig('profilecgs.png')