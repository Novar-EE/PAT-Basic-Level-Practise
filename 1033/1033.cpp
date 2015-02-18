#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

char c_err_str[300];
char c_str[100010];

int err_C[300] = {0};

int main()
{
		
//	std::cin >> err_key >> str;
	// ÊäÈëÓĞ¿Õ¸ñ..... 
	gets(c_err_str);
	gets(c_str);
	std::string err_key(c_err_str);
	std::string str(c_str);
	
	for (std::string::iterator iter = err_key.begin(); iter != err_key.end(); iter ++){
		if (*iter >= '0' && *iter <= '9')
			err_C[*iter - '0'] = 1;
		else if (*iter >= 'A' && *iter <= 'Z')
			err_C[*iter - 'A' + 'a'] = 1;
		else
			err_C[*iter] = 1;
		
	}
	for (std::string::iterator iter = str.begin(); iter != str.end(); iter ++){
		if (*iter >= 'A' && *iter <= 'Z' && err_C['+'] == 1){
			continue;
		}
		else if (*iter >= 'A' && *iter <= 'Z' && err_C[*iter - 'A' + 'a'] == 1){
			continue;
		}
//		else if (*iter >= 'a' && *iter <= 'z' && err_C[*iter - 'a' + 10] == 1){
//			continue;
//		}
		else if (*iter >= '0' && *iter <= '9' && err_C[*iter - '0'] == 1){
			continue;
		}
		else if (err_C[*iter] == 1){
			continue;
		}
		std::cout << *iter;
		
	}
	std::cout << std::endl;

}
