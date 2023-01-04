#include<stdio.h>  // Berfungsi untuk mendeklarasikan library
#include<conio.h>
#include<math.h>

// untuk mendeklarasikan fungsi
#define f(x) 2*x + 3
//x/(1+pow(x,2)) 

int main(){
	// Deklarasikan Variabel
	float a, b, integrasi=0.0, pias,x;
	int i, nInterval;
	
	// untuk menyimpan variabel dan menginput user
	printf("Masukan batas bawah integral : ");
	scanf("%f", &a);
	printf("Masukan batas atas integral : ");
	scanf("%f", &b);
	printf("Enter number of sub intervals: ");
	scanf("%d", &nInterval);

    /* KALKULASI */

	// berfungsi untuk menghitung panjang satu pias
	pias = (b - a)/nInterval;

	// berfungsi untuk mencari titik tengah dari pias pertama
	x =  a + pias / 2;

	// untuk menghitung fungsi x dari setiap titik tengah pias
	integrasi = f(x);
	for(i=1; i<= nInterval-1; i++){
		x += pias;
		integrasi += f(x);
	}

	// untuk menghitung total nilai hampiran dari integrasi
	integrasi = integrasi * pias;
    // untuk mencetak hasil akhir dari integrasi
	printf("\nNilai hampiran dari integrasi adalah : %.3f", integrasi);

	return 0;
}
