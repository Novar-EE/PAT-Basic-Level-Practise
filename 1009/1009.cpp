#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stack>

int main()
{
	
	std::stack<std::string> stack_str;
	
	while(true){
		std::string str;
		std::cin >> str;
		stack_str.push(str);
		
		char c = getchar();
		if (c == '\n')
			break;		
	}
	
	while(!stack_str.empty()){
		if (stack_str.size() != 1)
			std::cout << stack_str.top() << " "; 
		else
			std::cout << stack_str.top() << std::endl; 
		stack_str.pop();
	}
	
}
