#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

int A[40] = {0};

int main()
{
	std::string std_str, err_str;
	std::cin >> std_str >> err_str;
	
	std::string::iterator std_iter = std_str.begin();
	std::string::iterator err_iter = err_str.begin();
	
	std::vector<char> err_vec;
	
	while(!(err_iter == err_str.end() && std_iter == std_str.end())){
		if (*std_iter == *err_iter){
			std_iter ++;
			err_iter ++;
			continue;
		}
		else{
			err_vec.push_back(*std_iter);
			std_iter ++;
		}
	}
	
	for (std::vector<char>::iterator iter = err_vec.begin(); iter != err_vec.end(); iter ++){
		int index;
		if (*iter >= '0' && *iter <= '9'){
			index = *iter - '0';
			if (A[index] == 0)
				printf("%c", *iter);
			A[index] ++;
		}
		else if (*iter >= 'a' && *iter <= 'z'){
			index = *iter - 'a' + 10;
			if (A[index] == 0)
				printf("%c", *iter - 'a' + 'A');
			A[index] ++;
		}
		else if (*iter >= 'A' && *iter <= 'Z'){
			index = *iter - 'A' + 10;
			if (A[index] == 0)
				printf("%c", *iter);
			A[index] ++;
		}
		else if (*iter == '_'){
			index = 37;
			if (A[index] == 0)
				printf("%c", *iter);
			A[index] ++;			
		}
	}
	printf("\n");


}
