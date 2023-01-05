# buat code untuk memasukkan inputan value
e = 2.718
z = str(input("Masukan Fungsi: "))
batasBawah = float(input("input Batas Bawah: "))
batasAtas = float(input("input Batas Atas: "))
sub_interval = int(input("input Banyak Partisi: "))

def f(n): 
    temp = eval(z)
    
    return temp

# metode simpson
def simpson13(x0,xn,n):
    h = (xn - x0) / n 
    
    for i in range(n+1): 
         
        k = x0 + i*h 
        if i == 0:
            integration = f(x0)
            
        elif i == n:
            integration = integration + f(xn)
            
        elif i%2 == 0:
            integration = integration + 2 * f(k)
            
        elif i%2 == 1:
            integration = integration + 4 * f(k)
        print (integration)
        
    integration = integration * h/3
    
    return integration
    

# hasil
result = simpson13(batasBawah, batasAtas, sub_interval)
print("Nilai integrasi metode simpson : %0.6f"%(result))
