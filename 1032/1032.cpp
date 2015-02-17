#include <stdio.h>
#include <iostream>
#include <algorithm>

int A[100010] = {0};
int B[100010] = {0};

int main()
{
	int N;	
	scanf("%d", &N); getchar();
	int num = 0;
	
	for (int i = 0; i < N; i ++){		
		int tmp_id, tmp_score;	
		scanf("%d %d", &tmp_id, &tmp_score); getchar();
		A[tmp_id] += tmp_score;
		
		// 计算有效成绩的个数（编号是连续的） 
		if (B[tmp_id] == 0){
			num ++;
			B[tmp_id] = 1;
		}
	}
	
	int M = 0, M_index = 0;
	for (int i = 0; i <= num; i ++){
		if (A[i] > M){
			M = A[i];
			M_index = i;	
		}
	}
	
	printf("%d %d\n", M_index, M);
	
}
