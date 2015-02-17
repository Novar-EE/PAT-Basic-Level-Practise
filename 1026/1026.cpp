#include <stdio.h>
#include <string>
#include <iostream>

#define MY_CLK_TCK 100

int main()
{
	long long C1, C2;
	double D;
	scanf("%lld %lld", &C1, &C2);
	D = 1.0 * (C2 - C1) / MY_CLK_TCK;
	
	long long int_D = int(D);
	double frac_D = D * 1.0 - int_D;
	
	long long real_D;
	if (frac_D >= 0.5)
		real_D = int_D + 1;
	else
		real_D = int_D;
	
	int HH, MM, SS;
	SS = real_D % 60;
	MM = (real_D / 60) % 60;
	HH = (real_D / 60 / 60) % 60;
	printf("%02d:%02d:%02d\n", HH, MM, SS);
	
	
	
}
