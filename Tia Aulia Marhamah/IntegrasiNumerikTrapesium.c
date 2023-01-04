// Deklarsi library
#include<stdio.h>
#include<conio.h>
#include<math.h>

// Mendeklarasikan fungsi disini
#define f(x) 2*x+3
//x/(1+pow(x,2)) pow(pangkat)

int main(){
	// Mendeklarasikan variabel
	float a, b, integrasi=0.0, pias, k,s;
	int i, nInterval;
	
	// untuk menyimpan ke dalam variabel dan mengambil user
	printf("Masukan batas bawah integral : ");
	scanf("%f", &a);
	printf("Masukan batas atas integral : ");
	scanf("%f", &b);
	printf("Enter number of sub intervals: ");
	scanf("%d", &nInterval);

	/* KALKULASI */
	
	// untuk menghitung panjang satu pias
	pias = (b - a)/nInterval;

	// untuk menghitung nilai fungsi dari bagian awal dan akhir integral 
	integrasi = f(a) + f(b);
	
	// Pengulangan untuk menghitung setiap jumlah fungsi setiap pias
	for(i=1; i<= nInterval-1; i++){
		k = a + i*pias;
		//mencetak nilai integrasi setiap pengulangan 	
		printf("\n %.3f , %.3f", k, f(k)); // digunakan untuk mencetak hasil perhitingan jumlah integrasi dari fungsi awal dan akhir
		
		// terdapat variabel s untuk menampung jumlah fungsi dari perhitungan sebelumnya
		s = f(k);
		integrasi +=  2 * s;	
	}
	
	// untuk menghitung nilai akhir dari total integrasi tersebut
	integrasi = integrasi * pias/2;
    // untuk mencetak hasil akhir integrasi
	printf("\nNilai hampiran dari integrasi adalah : %.3f", integrasi);
	getch();
	return 0;
}