#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 提交时把MAX改打... 
#define MAX 10000

int main()
{
	short array[MAX] = {0};
	int M = 0, N = 0;
	std::vector<int> vec_res;
	
	scanf("%d %d", &M, &N);
	
	for (int i = 2; i <= MAX; i ++){
		if (array[i] == 0){
			vec_res.push_back(i);
			int tmp = i;
			while(tmp <= MAX){
				array[tmp] = 1;
				tmp = tmp + i;
			}
		}	
	}

	int cnt = 0;
	for (int i = M - 1; i <= N - 1; i ++){
		cnt ++;
		std::cout << vec_res[i];
		if (i == N - 1 || cnt % 10 == 0) std::cout << std::endl;
		else std::cout << " ";
		
	}

	
}

