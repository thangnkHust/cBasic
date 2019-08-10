#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define num 0.01

// tinh e^x theo bieu thuc taylor

double E(double x, double invalidNum){

	double sum = 1;
	int n = 1;
	double y = x;
	double gt = 1;
	while( fabs(y/gt) >= invalidNum){
		sum += (double)y/gt;
		y *= x;
		n++;
		gt *= n;
	}
	return sum;

}


int main(int argc, char * argv[]){

	double x, invalidNum;
	double kq;

  if (argc < 2 || argc >3)
		{
			printf("nhap sai arguments \n");
			printf("nhap dung la: ./ex21 \"x(so mu)\"  or ./ex21 \"x(so mu)\" \"invalidNumer(sai so)\" \n");
			return 0;
		}else{
			if (argc == 2)
			{
				x = atof(argv[1]);
				invalidNum = num;
				// kq = E(x, invalidNum);
				if (x > 0)
				{
					kq = E(x, invalidNum);
				}else{
					kq = 1/E(-x, invalidNum);
				}
			}
			if (argc == 3)
			{
				x = atof(argv[1]);
				invalidNum = atof(argv[2]);
				// kq = E(x, invalidNum);
				if (x > 0)
				{
					kq = E(x, invalidNum);
				}else{
					kq = 1/E(-x, invalidNum);
				}
			}
		}

	printf("e^%g = %g \n",x, kq );

}
