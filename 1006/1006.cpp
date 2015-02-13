#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

int main()
{
	int N;
	std::cin >> N;
	
	int a = N / 100;
	int b = (N % 100) / 10;
	int c = N % 10;
	
	std::string res;
	
	for (int i = 0; i < a; i ++){
		res = res + "B";
	}
	for (int i = 0; i < b; i ++){
		res = res + "S";
	}
	for (int i = 1; i <= c; i ++){
		std::stringstream ss;
		std::string tmp;
		ss << i;
		ss >> tmp;		
		res = res + tmp;
	}
	
	std::cout << res << std::endl;
	
}
