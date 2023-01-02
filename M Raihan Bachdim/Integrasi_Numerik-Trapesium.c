#include<stdio.h>
#include<conio.h>
#include<math.h>

/* Define function here */
#define f(x) 2*x+3
//x/(1+pow(x,2))

int main(){
    float a, b, integrasi=0.0, pias, k,s;
    int i, nInterval;
    // clrscr();
    /* Input */
	printf("Masukan batas bawah integral : ");
	scanf("%f", &a);
	printf("Masukan batas atas integral : ");
	scanf("%f", &b);
	printf("Enter number of sub intervals: ");
	scanf("%d", &nInterval);

    /* Calculation */
    /* Finding step size */
    pias = (b - a)/nInterval;

    /* Finding integrasi Value */
    integrasi = f(a) + f(b);
    
    printf("\n %.3f", integrasi);
    for(i=1; i<= nInterval-1; i++){
        k = a + i*pias;
        printf("\n %.3f , %.3f", k, f(k));
        s = f(k);
        integrasi +=  2 * s;
        printf("\n %.3f", integrasi);
    }
    integrasi = integrasi * pias/2;
    printf("\nNilai hampiran dari integrasi adalah : %.3f", integrasi);
    getch();
    return 0;
}
