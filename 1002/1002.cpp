#include <iostream>
#include <string>
#include <sstream> 
#include <vector>
#include <stack>

std::string str_array[10] = 
{
	"ling", "yi", "er", "san", "si", 
	"wu", "liu", "qi", "ba", "jiu"
};

int main()
{
    std::string str;
    std::cin >> str;
    
    int sum = 0;
	
	for (std::string::iterator iter = str.begin(); iter != str.end(); iter ++){
    	std::stringstream stream_str;
    	stream_str << *iter;
    	int tmp;
    	stream_str >> tmp;
    	sum += tmp;
	}	
//	std::cout << sum << std::endl;

	std::stack<int> sum_v;
	while(sum != 0){
		int tmp;
		tmp = sum % 10;
		sum_v.push(tmp);
		sum = sum / 10;
	}
	while (true){
		std::cout << str_array[sum_v.top()];
		sum_v.pop();
		if (sum_v.empty())
			break;
		std::cout << " ";
	}
	std::cout << std::endl;
}

