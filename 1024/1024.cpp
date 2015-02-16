#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

int main()
{
	std::string str = "", res = "";
	std::string mid = "";
	std::cin >> str;
	
	if (str[0] == '-')
		res += str[0];
	
	std::string::iterator iter = str.begin() + 3;
	while(*iter != 'E'){
		mid += *iter;
		iter ++;
	}
	// *iter = 'E'
	
	iter ++; // *iter = '+' or '-'
	char exp_flag = *iter;
	
	int exp = 0;
	iter ++;
	while (iter != str.end()){
		exp = *iter - '0' + 10 * exp;
		iter ++;
	}
	
	if (exp == 0){		
		res += str[1] + ('.' + mid);
	}
	else {
		if (exp_flag == '+'){
			std::string tail = "";		
			
			if (exp > mid.length()){
				while (exp -- > mid.length()){
					tail += '0';
				}
			}
			else if (exp < mid.length()){
				std::string mid_a(mid.begin(), mid.begin() + exp);
				std::string mid_b(mid.begin() + exp, mid.end());
				std::string new_mid = mid_a + '.' + mid_b;
				mid = new_mid;			
			}
			
			
			res += str[1] + mid + tail;		
		}
		else if (exp_flag == '-'){
			
			std::string head = "";
			while (exp -- > 1){
				head += '0';
			}
			res += "0." + head + str[1] + mid;
		}	
	}	
	std::cout << res << std::endl;;
}
