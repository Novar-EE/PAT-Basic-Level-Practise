#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>

int main()
{
	std::vector<int> vec_input;
	
	while(true){
		int tmp;
		char c;
		std::cin >> tmp; getchar();
		vec_input.push_back(tmp);
		std::cin >> tmp; c = getchar();
		vec_input.push_back(tmp);
		
		if (c == '\n' )
			break;
	}	
	
	if (vec_input.size() == 0){
		std::cout << "0 0" << std::endl;
		return(0);
	}
		
	std::vector<int> vec_res;
	for (std::vector<int>::iterator iter = vec_input.begin() + 1; iter < vec_input.end(); iter = iter + 2){
		int a = *(iter - 1);
		int b = *iter;
		if (b == 0){
			a = 0; b = 0;
		}
		else{		
			a = a * b; b = b - 1;
		}		
		vec_res.push_back(a);
		vec_res.push_back(b);		
	}	
	
	for (std::vector<int>::iterator iter = vec_res.begin(); iter != vec_res.end(); iter = iter + 2){
		if (*iter == 0 && *(iter + 1) == 0)
			continue;
		if (iter == vec_res.begin())
			printf("%d %d", *iter, *(iter + 1));
		else
			printf(" %d %d", *iter, *(iter + 1));
	}
	std::cout << std::endl;
}

