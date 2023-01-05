#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

// Menginisialisasi konstanta yang akan di pakai
// konstanta max berguna sebagai variabel untuk inisialisasi matriks
#define max 10

int main(){

    // inisialisasi beberapa variabel yang akan digunakan
    float mat[max][max], x[max], ratio;
    int i, j, k, n;

    // menerima inputan dari user untuk ukuran matriks
    printf("Masukan dimensi matriks : ");
    scanf("%d", &n);

    // fungsi pengulangan untuk memasukan inputan user ke dalam matriks mat
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n + 1; j++){
            printf("Masukan nilai X-%d,%d : ", i, j);
            scanf("%f", &mat[i][j]);
        }
    }

    // baris 29 samapai 35 merupakan pengulangan untuk mencetak matriks yang sudah diinput
    printf("\nMatriks anda : \n");
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n + 1; j++){
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }

    // perhitungan spl dengan metode gauss
    for (i = 1; i <= n - 1; i++){
        
        // eksepsi error jika nilai pada posisi diagonal matriks bernilai nol
        if (mat[i][i] == 0.0){
            printf("Terjadi error!");
            exit(0);
        }
        for (j = i + 1; j <= n; j++){

            ratio = mat[j][i] / mat[i][i];

            for (k = 1; k <= n + 1; k++){
                mat[j][k] = mat[j][k] - ratio * mat[i][k];
            }
        }
    }
    // melakukan substitusi
    x[n] = mat[n][n + 1] / mat[n][n];

    for (i = n - 1; i >= 1; i--){
        x[i] = mat[i][n + 1];
        for (j = i + 1; j <= n; j++){
            x[i] = x[i] - mat[i][j] * x[j];
        }
        x[i] = x[i] / mat[i][i];
    }



    // menampilkan hasil akhir dari perhitungan
    printf("\nHasil akhir:\n");
    for (i = 1; i <= n; i++){
        printf("x%d = %0.3f\n", i, x[i]);
    }
    getch();
    return (0);
}