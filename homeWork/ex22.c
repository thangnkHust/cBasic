#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void SDE(int a, int b, int c){
	double denta;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
			{
				printf("phuong trinh co vo so nghiem\n");
			}else
				printf("phuong trinh vo nghiem\n");
		}else{
			printf("phuong trinh co 1 nghiem duy nhat la x = %g\n", (double)(-c)/b );
		}
	}else{
		denta = b*b - 4*a*c;
		if (denta == 0)
		{
			printf("phuong trinh co nghiem kep x1 = x2 = %g\n", (double)(-b)/(2*a) );
		}
		if (denta > 0)
		{
			printf("phuong trinh co 2 nghiem rieng biet:\n \tx1 = %g\n\tx2 = %g\n", (double)(-b+sqrt(denta))/(2*a), (double)(-b-sqrt(denta))/(2*a) );
		}
		if (denta < 0 )
		{
			printf("phuong trinh vo nghiem\n");
		}
	}
}	

int main (int argc, char *argv[]){


	if (argc != 4)
	{
		printf("nhap sai arguments\n");
		printf("nhap dung la: ./ex22 \"a\" \"b\" \"c\" (a, b, c la he so cua phuong trinh bac 2 an x)\n");
	}else{
    int a , b, c;
    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);
    SDE(a, b, c);
  }
}
