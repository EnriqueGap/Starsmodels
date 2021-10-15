import matplotlib.pyplot as plt
from astropy.io import ascii
data=ascii.read('profile.dat',header_start=0)

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
plt.savefig('profile.png')
