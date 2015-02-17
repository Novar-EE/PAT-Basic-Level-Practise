#include <stdio.h>
#include <iostream>

int find_stroy(int N, int *num_tower)
{
	int res = 0;
	if (N == 1){
		res = 1;
		*num_tower = 1;
	}
	else{
		res = 1;
		int num = 1;
		int tmp = num;
		while (tmp <= N){
			res ++;
			num = tmp;
			tmp = num + 2 * (2 * res - 1);					
		}	
		res --;	
		*num_tower = num;
		
	}
	return(res);
}


int main()
{
	int N;
	char c;
	scanf("%d %c", &N, &c);
	
	int num_tower;
	int num = find_stroy(N, &num_tower);
	
	for (int i = 0; i < num; i ++){
		int num_blank = i;
		int num_c = 2 * (num - i) - 1;
		
		for (int j = 0; j < num_blank; j ++){
			printf(" ");
		}		
		for (int j = 0; j < num_c; j ++){
			printf("%c", c);
		}
		printf("\n");
	}
	
	for (int i = num - 2; i >= 0; i --){
		int num_blank = i;
		int num_c = 2 * (num - i) - 1;
		
		for (int j = 0; j < num_blank; j ++){
			printf(" ");
		}		
		for (int j = 0; j < num_c; j ++){
			printf("%c", c);
		}
		printf("\n");
	}
	
	printf("%d\n", N - num_tower);
	
	
//	std::cout << num << std::endl;
	

}
