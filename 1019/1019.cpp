#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>


void get_N(int N, int *A, int *B)
{
	int n[4];
	n[0] = (N / 1000) % 10;
	n[1] = (N / 100) % 10;
	n[2] = (N / 10) % 10;
	n[3] = (N) % 10;
	
	std::sort(n, n + 4);
	
	*A = n[3] * 1000 + n[2] * 100 + n[1] * 10 + n[0];
	*B = n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3];	
	
}

void print_N(int N)
{
	if (N < 1000){
		printf("0");
		if (N < 100){
			printf("0");
			if (N < 10)
				printf("0");
		}
	}
	printf("%d", N);
}


int main()
{
	int N, new_N;
	int A, B;

	scanf("%d", &N);
	
	if (N == 6174){
		printf("7641 - 1467 = 6174\n");
	}
	
	while (N != 0 && N != 6174){
		get_N(N, &A, &B);
		N = A - B;
		
		print_N(A);
		printf(" - ");
		print_N(B);
		printf(" = ");
		print_N(N);
		printf("\n");
		//printf("%4d - %4d = %4d\n", A, B, N);
		//N = new_N;
	}
	//printf("%d\n", int_reverse(N));
	 
}
