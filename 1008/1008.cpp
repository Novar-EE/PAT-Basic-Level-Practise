#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

int main()
{
	int N, shift;
	scanf("%d %d", &N, &shift);

	// 移位数要比数组总位数小... 
	shift = shift % N;
	
	int *array = NULL;
	array = new int[N];
	
	int *tmp = NULL;
	tmp = new int[shift];
	//array = (int *)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i ++){
		scanf("%d", array + i); getchar();
	}
	
	for (int i = 0; i < shift; i ++){
		tmp[i] = array[N - shift + i];
	}
	for (int i = N - 1; i >= shift; i --){
		array[i] = array[i - shift];
	}
	for (int i = 0; i < shift; i ++){
		array[i] = tmp[i];
	}
	
	
	for (int i = 0; i < N; i ++){
		if (i != N - 1)
			std::cout << array[i] << " ";
		else
			std::cout << array[i] << std::endl;
	}
	 
 	delete [] array;
 	delete [] tmp;
}
