#include <stdio.h>
#include <stdlib.h>

#define N 3  // jumlah variabel dalam sistem
#define M 3  // jumlah persamaan dalam sistem

// Fungsi untuk mencetak matriks
void print_matrix(double mat[M][N+1]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N+1; j++) {
      printf("%f ", mat[i][j]);
    }
    printf("\n");
  }
}

int main() {
    double mat[M][N+1];
    double tampung;

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N+1; j++){
            if (j==N){
                printf("Masukan nilai y-%d : ",i+1);
                scanf("%lf", &mat[i][j]);
            }else{
                printf("Masukan nilai X-%d,%d : ",i+1,j+1);
                scanf("%lf", &mat[i][j]);
            }          
        }
    }
    
    // double mat[M][N+1] = {
    //     {4, 3, -1, 12},
    //     {-2, -4, 5, -13},
    //     {1, 2, 6, -2}
    // };

    printf("Matriks anda :\n");
    print_matrix(mat);
    printf("\n");

    // Mencari solusi sistem persamaan linear menggunakan metode Gauss-Jordan
    for (int i = 0; i < M; i++) {
        // Pembagian baris untuk membuat pivotnya 1
        double pivot = mat[i][i];
        for (int j = 0; j < N+1; j++) {
            mat[i][j] /= pivot;
        }
            
        // Menggunakan baris pivot untuk mengubah baris lainnya menjadi 0
        for (int k = 0; k < M; k++) {
            if (k == i) continue;  // Skip baris pivot
            double ratio = mat[k][i];
            for (int j = 0; j < N+1; j++) {
                mat[k][j] -= ratio * mat[i][j];
            }
        }
    }
    // Mencetak solusi sistem
    printf("Solusi sistem adalah:\n");
    for (int i = 0; i < M; i++) {
        printf("x%d = %lf\n", i+1, mat[i][N]);
    }
    return 0;
}