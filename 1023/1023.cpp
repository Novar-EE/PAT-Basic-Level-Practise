#include <iostream>
#include <vector>
#include <algorithm>



int main()
{
	int n[10] = {0};
	
	for (int i = 0; i < 10; i ++){
		scanf("%d", &n[i]); getchar();
	}
	
	for (int i = 1; i < 10; i ++){
		if (n[i]){
			printf("%d", i);
			n[i] --;
			break;
		}
	}
	for (int i = 0; i < 10; i ++){
		while (n[i]){
			printf("%d", i);
			n[i] --;
		}
	}
	printf("\n");
	
}
