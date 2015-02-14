#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

int res[2][3] = {0};
int eq = 0;



int check(const char a, const char b)
{
	if (a == 'C'){
		if (b == 'C'){
			eq ++; return(0);
		}
		else if (b == 'J'){
			res[0][0] ++; return(0);
		}
		else if (b == 'B'){
			res[1][2] ++; return(0);	
		}
	}	
	else if (a == 'J'){
		if (b == 'C'){
			res[1][0] ++; return(0);
		}
		else if (b == 'J'){
			eq ++; return(0);
		}
		else if (b == 'B'){
			res[0][1] ++; return(0);	
		}
	}
	else if (a == 'B'){
		if (b == 'C'){
			res[0][2] ++;return(0);
		}
		else if (b == 'J'){
			res[1][1] ++; return(1);
		}
		else if (b == 'B'){
			eq ++; return(0);	
		}
	}
	
}

int main()
{
	int N;
	scanf("%d\n", &N);
	
	for (int i = 0; i < N; i ++){
		char a, b;
		scanf("%c %c", &a, &b);getchar();
		check(a, b);
	}
	
	int R[2] = {0};
	for (int i = 0; i < 2; i ++){
		for (int j = 0; j < 3; j ++){
			R[i] += res[i][j]; 
		}
	}
	printf("%d %d %d\n", R[0], eq, R[1]);
	printf("%d %d %d\n", R[1], eq, R[0]);
	
	for (int i = 0; i < 2; i ++){
		int M = 0;
		for (int j = 0; j < 3; j ++){
			if (res[i][j] > M)
				M = res[i][j];
		}		
		
		if (M == res[i][2])
			printf("B");
		else if (M == res[i][0])
			printf("C");
		else if (M == res[i][1])
			printf("J");
		if (i == 1)
			printf("\n");
		else	
			printf(" ");	
	}
	
/*	
	for (int i = 0; i < 2; i ++){
		for (int j = 0; j < 3; j ++){
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << eq << std::endl;
*/
}

