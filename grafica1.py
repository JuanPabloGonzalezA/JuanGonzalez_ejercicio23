import numpy as np
import matplotlib.pyplot as plt

datos=np.loadtxt('datos.txt')
snaps=np.arange(5)

for t in snaps:
	x=datos[datos[:,0]==t,1]
	u=datos[datos[:,0]==t,2]
	tiempo=t
	plt.plot(x,u,label='snap = '+str(t))
plt.xlabel(r'$x$')
plt.ylabel(r'$u(x,t)$')
plt.legend()
plt.savefig('grafica1.png')
