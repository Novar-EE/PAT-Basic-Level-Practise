#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

long long A[100010] = {0};

int main()
{
	int N;
	long long p;
	scanf("%d %lld\n", &N, &p);
	for (int i = 0; i < N; i ++){
		scanf("%lld", &A[i]); getchar();
	}	
	
	int len = 0;
	int m = 0;
	int M_index = 0;
	
	std::sort(A, A + N);
	
	for (int i = 0; i < N; i ++){
		m = A[i];
		double mp = 1.0 * m * p;
		M_index = N - 1;
		
		if (N > 1000){
			while (A[M_index] > m && A[M_index] > mp){
				M_index = M_index - 100;
			}
			//M_index = M_index + 100;
		}		
		while (A[M_index] > m && A[M_index] > mp){
			M_index = M_index - 1;
		}
		
		int tmp_len = M_index - i + 1;
		if (len < tmp_len){
			len = tmp_len;
		}
	}
	
	printf("%d\n", len);
	
	
//	for (int i = 0; i < N; i ++){
//		printf("%d ", A[i]);
//	}

}
