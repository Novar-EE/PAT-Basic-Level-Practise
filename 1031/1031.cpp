#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>

int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char ZM[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool check_str(std::string str)
{	
	int len = str.length();
	int sum = 0;
	for (std::string::iterator iter = str.begin(); iter != str.end() - 1; iter ++){
		sum = sum + (*iter - '0') * weight[iter - str.begin()];
	}	
	int Z = sum % 11;
	return(*(str.end() - 1) == ZM[Z]);

}


bool check_str(char* str, int len = 18)
{	
	int sum = 0;
	for (int i = 0; i < len - 2; i ++){
		sum = sum + (str[i] - '0') * weight[i];
	}	
	int Z = sum % 11;
	return(str[len - 1] == ZM[Z]);

}

int main()
{
	int N;
	std::string str;
	scanf("%d\n", &N);
	
	std::vector<std::string> vec;
	for (int i = 0; i < N; i ++){
		//scanf("%s", str); getchar();
		std::cin >> str;
		//std::cout << check_str(str) << std::endl;
		
		if (!check_str(str)){
			vec.push_back(str);
		}		
	}
	
	if (vec.size() == 0){
		std::cout << "All passed" << std::endl;
	}
	else{
		for (std::vector<std::string>::iterator iter = vec.begin(); iter != vec.end(); iter ++){
			std::cout << *iter << std::endl;
		}
	}
	
}

