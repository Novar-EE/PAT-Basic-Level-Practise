#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	int A[200000] = {0};
	std::vector<int> vec_prim;
	int res = 0;
	
	if (N > 3){
		
		for (int i = 2; i <= N; i ++){
			int tmp = i;
			if (A[tmp] == 0)
				vec_prim.push_back(tmp);
			while(tmp <= N){
				tmp = tmp + i;
				A[tmp] = 1;
			}
		}	
		
		for (std::vector<int>::iterator iter = vec_prim.begin() + 1; iter != vec_prim.end(); iter ++){
			//std::cout << *iter << " ";
			if (*iter - *(iter - 1) == 2)
				res ++;
		}
	}
	
	std::cout << res << std::endl;

}


