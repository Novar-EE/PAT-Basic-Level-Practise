#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>

int main()
{
	std::string A, B;
	//std::string DA_str, DB_str;
	char DA, DB;
	
	std::cin >> A >> DA;
	std::cin >> B >> DB;


			
	std::string tmp_DA = "", tmp_DB = "";
	
	for (std::string::iterator iter = A.begin(); iter != A.end(); iter ++){
		if (*iter == DA)
			tmp_DA += DA;
	}
	for (std::string::iterator iter = B.begin(); iter != B.end(); iter ++){
		if (*iter == DB)
			tmp_DB += DB;
	}
	
	//std::cout << tmp_DA << tmp_DB;
	
	int DA_int, DB_int;
	if (tmp_DA != ""){
		std::stringstream ss;
		ss << tmp_DA; ss >> DA_int;
	}
	else{
		DA_int = 0;
	}
	if (tmp_DB != ""){
		std::stringstream ss;
		ss << tmp_DB; ss >> DB_int;
	}
	else{
		DB_int = 0;
	}
	//std::stringstream ss_A, ss_B;
	//ss_A << tmp_DA; ss_A >> DA_int;
	//ss_B << tmp_DB; ss_B >> DB_int;
	std::cout << DA_int + DB_int << std::endl;
	
}
