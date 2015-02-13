#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>

bool cmp(int const &arg1, int const arg2)
{
	return(arg1 > arg2);
}


int main()
{
	int N = 0;
	scanf("%d", &N);

	// Êı×é¿ª1000¶Î´íÎó... 
	int prim_array[10000] = {0};
	
	std::vector<int> vec_array;
	for (int i = 0; i < N; i ++){
		int tmp;
		scanf("%d", &tmp); getchar();
		vec_array.push_back(tmp);
	}
	
	for (std::vector<int>::iterator iter = vec_array.begin(); iter != vec_array.end(); iter ++){
		int n = *iter;
		while(n != 1){
			prim_array[n] += 1;
			if (n % 2 == 0)
				n = n / 2;
			else 
				n = (3 * n + 1) / 2;	
		}
		//std::cout << *iter << " ";
	}
	
	std::vector<int> vec_res;
	for (std::vector<int>::iterator iter = vec_array.begin(); iter != vec_array.end(); iter ++){
		int index = *iter;
		if (prim_array[index] == 1){
			vec_res.push_back(index);
		}		
	}
	std::sort(vec_res.begin(), vec_res.end(), cmp);

	for (std::vector<int>::iterator iter = vec_res.begin(); iter != vec_res.end(); iter ++){
		if (iter != vec_res.end() - 1)
			std::cout << *iter << " ";
		else 
			std::cout << *iter << std::endl;
	}

/*	
	for (int i = vec_res.length() - 1; i >= 0; i --){
		if (i != 0)
			std::cout << vec_res[i] << " ";
		else 
			std::cout << vec_res[i] << std::endl;			
	}
*/	
	

}

