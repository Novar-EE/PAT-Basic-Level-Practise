#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

int main()
{
	std::string str;
	std::cin >> str;
	int res[10] = {0};
	
	for (std::string::iterator iter = str.begin(); iter != str.end(); iter ++){
		res[*iter - '0'] ++;
	}
	for (int i = 0; i < 10; i ++){
		if(res[i] != 0)
			printf("%d:%d\n", i, res[i]);
	}
	
}
