import numpy as np
import matplotlib.pyplot as plt

# deklrasi variable n untuk menampung banyak titik
n = int(input('Memasukan titik yang ingin dihitung: '))

# deklrasi variable x untuk menampung nilai pada x
x = np.zeros((n))
#deklrasi variable y untuk menampung nilai pada y
y = np.zeros((n))


# Masukan data x dan y dan deklarasi sistem perulangan
print('Masukan nilai x dan y: ')
for i in range(n):
    x[i] = float(input( 'x['+str(i)+']=')) # masukan x[i]
    y[i] = float(input( 'y['+str(i)+']=')) # masukan y[i]


xp = float(input('masukan input : '))
yp = 0 

# notasi algoritma Lagrange
for i in range(n): 
    p = 1
    for j in range(n):
        if i != j:
            p = p * (xp - x[j])/(x[i] - x[j])
    yp = yp + p * y[i]    
    
print('Pada x %.3f mempunyai f(x) atau y  %.3f' % (xp, yp))
plt.plot(x, y, marker = '*')
plt.plot(xp, yp, marker = 'o')
plt.show()
