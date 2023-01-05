

#include<stdio.h>
#include<math.h>
double f(double x)
{
      return(exp(-x)-x);
}
main()
{
      double fx[100],a,b,error;
      double fa,fb,xr,fxr;
      int n,i;
      printf("Masukkan batas bawah a = ");
      scanf("%lf",&a);
      printf("Masukkan batas atas b = ");
      scanf("%lf",&b);
      printf("Input toleransi error=");
      scanf("%lf",&error);
      printf("Input iterasi maksimum=");
      scanf("%d",&n);
             fa=f(a);
             fb=f(b);
             if(fa*fb>0)
                    printf("Akar tidak ditemukan dalam range %g - %g...\n", a, b);
             else{
                    i=0;
                    while (i<=n){
                           xr=(a+b)/2;
                           fx[i]=f(xr);
                           fxr=f(xr);
                           printf("%d a=%7lf b=%7lf xr=%7lf fa=%7lf fb=%7lf fxr=%7lf\n",i,a,b,xr,fa,fb,fxr);
                                  if(fx[i]*fa<0){
                                        b=xr;
                                         fb = f(xr);
                                  }
                                  else{
                                         a=xr;
                                         fa = f(xr);
                                  }
                           i++;
                           if(fabs(b-a)<=error || i>(n-1)) break;
                    }
                    printf("Akarnya adalah %g\n",xr);
                    printf("Nilai error = %g\n",fabs(fxr));
             }

}