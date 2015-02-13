#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	int case_num;
	std::cin >> case_num;
	
	for (int i = 0; i < case_num; i ++){
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		
		std::cout << "Case #" << i + 1 << ": ";
		
		bool f = a + b > c;
		if (a + b > c)
			std::cout << "true" << std::endl;
		else
			std::cout << "false" << std::endl;
	
	}
}

