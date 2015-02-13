#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


std::string week[7] = {
	"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

int main()
{
	char day, hour;
	int minute = 0;
	
	std::string str[4];
	for (int i = 0; i < 4; i ++){
		std::cin >> str[i];
	}
	
	int i = 0;
	while(true){
		if ((str[0][i] >= 'A' && str[0][i] <= 'G') && (str[1][i] >= 'A' && str[1][i] <= 'G')){
			if (str[0][i] == str[1][i]){
				day = str[0][i]; i ++; break;
			}
		}
		i ++;
		if (i > str[0].length() || i > str[1].length()) break;
	}
	while(true){
		if (((str[0][i] >= 'A' && str[0][i] <= 'N') || (str[0][i] >= '0' && str[0][i] <= '9')) && \
			((str[1][i] >= 'A' && str[1][i] <= 'N') || (str[0][i] >= '0' && str[0][i] <= '9'))){
			if (str[0][i] == str[1][i]){
				hour = str[0][i]; break;
			}
		}
		i ++;
		if (i > str[0].length() || i > str[1].length()) break;
	}	
	
	i = 0;
	while(true){
//		if (((str[2][i] >= 'a' && str[2][i] <= 'z')) && \
//			((str[3][i] >= 'a' && str[3][i] <= 'z'))){
		if (((str[2][i] >= 'a' && str[2][i] <= 'z') || (str[2][i] >= 'A' && str[2][i] <= 'X')) && \
			((str[3][i] >= 'a' && str[3][i] <= 'z') || (str[2][i] >= 'A' && str[2][i] <= 'Z'))){
			if (str[2][i] == str[3][i]){
				minute = i; break;
			}
		}
		i ++;
		if (i > str[2].length() || i > str[3].length()) break;
	}
	
	std::cout << week[day - 'A'] << " ";
	
	if (hour >= '0' && hour <= '9'){
		std::cout << "0" << hour - '0';
	}
	else if (hour >= 'A' && hour <= 'N'){
		std::cout << hour - 'A' + 10;
	}
	std::cout << ":";
	if (minute < 10)
		std::cout << "0";
	std::cout << minute << std::endl;

	
	
}
