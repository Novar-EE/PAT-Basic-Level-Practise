#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

int A[110] = {0};
int B[110] = {0};
int res[110] = {0};
int tmp[110] = {0};

bool check(int A[], int B[], int N)
{
	for (int i = 0; i < N; i ++){
		if (A[i] != B[i])
			return(false);
	}
	return(true);
}


void array_copy_A2B(int A[], int B[], int size)
{
	for (int i = 0; i < size; i ++){
		B[i] = A[i];
	}

}


void print_A(int A[], int N)
{	
	for (int i = 0; i < N; i ++){
		if (i == 0) printf("%d", A[i]);
		else printf(" %d", A[i]);
	}
	printf("\n");
	
}

void sub_insert_sort(int N, int i)
{
	int tmp = A[i];
	for (int j = 0; j < i; j ++){
		if (tmp < A[j]){
			for (int k = i; k >= j; k --){
				A[k] = A[k - 1];
			}
			A[j] = tmp;
			break;
		}				
	}
}


void merge(int *A, int *B, int *res, int size_A, int size_B)
{
	int index = 0;
	int i = 0, j = 0;
	while (i < size_A && j < size_B){
		if (A[i] <= B[j]){
			res[index ++] = A[i ++];
		}
		else{
			res[index ++] = B[j ++];	
		}
	}	
	while (i < size_A){
		res[index ++] = A[i ++];
	}
	while (j < size_B){
		res[index ++] = B[j ++];
	}
}

void sub_merge_sort(int A[], int res[], int size, int N)
{
	int A_beg, B_beg;
	int A_size = size, B_size = size;
	
	for (A_beg = 0; A_beg < N - size; A_beg = A_beg + 2 * size){
		B_beg = A_beg + size;
		if (B_beg + size > N){
			B_size = N - B_beg;
		}
		// void merge(int *A, int *B, int *res, int size_A, int size_B)
		merge(A + A_beg, A + B_beg, res + A_beg, A_size, B_size);
		//print_A(res, N);
	}
	array_copy_A2B(res, A, N);
}



int main()
{
	int N;
	bool flag = false;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i ++)
		scanf("%d", &A[i]);
	for (int i = 0; i < N; i ++)
		scanf("%d", &B[i]);


	array_copy_A2B(A, tmp, N);
	
	for (int size = 1; size < N; size *= 2){		
		sub_merge_sort(A, res, size, N);
		if (flag){
			printf("Merge Sort\n"); print_A(A, N);
			//break;
			return(0);
		}					
		//print_A(A, N);
		if (check(A, B, N)){
			flag = true;
		}		
	}
	
	
	array_copy_A2B(tmp, A, N);	flag = false;
	for (int i = 0; i < N; i ++){
		sub_insert_sort(N, i);
		//print_A(N);
		if (flag){
			printf("Insertion Sort\n"); print_A(A, N);
			//break;
			return(0);
		}
		
		if (check(A, B, N)){
			flag = true;
		}		
	}
		
}
