#include <stdio.h>
#include <iostream>
#include <algorithm>

int A[100010] = {0};

int main()
{
	int N;	
	scanf("%d", &N); getchar();
	int num = 0;
	int M = 0, M_index = 0;
	
	for (int i = 0; i < N; i ++){		
		int tmp_id, tmp_score;	
		scanf("%d %d", &tmp_id, &tmp_score); getchar();
		A[tmp_id] += tmp_score;
		
		if (A[tmp_id] > M){
			M = A[tmp_id];
			M_index = tmp_id;
		}
	}
	printf("%d %d\n", M_index, M);
	
}
