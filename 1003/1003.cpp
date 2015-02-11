#include <iostream>
#include <string>

bool PAT_test(std::string &str)
{
	bool flag = true;
	int A_num = 0, B_num = 0, C_num = 0;	
	if (str.length() < 3)
		return(false);	

	std::string::iterator iter = str.begin();
	
	int p_num = 0, a_num = 0, t_num = 0;
	for (; iter != str.end(); iter ++){
		if (*iter == 'P') p_num ++;
		else if (*iter == 'A') a_num ++;
		else if (*iter == 'T') t_num ++;
		else return(false);
	}
	if (p_num != 1 || t_num != 1)
		return(false);
		
	iter = str.begin();
		
	while(*(iter ++) != 'P'){
		A_num ++;
		if (iter == str.end())
			return(false);
	}
	while(*(iter ++) != 'T'){
		B_num ++;
		if (iter == str.end())
			return(false);
	}
	while(*(iter ++) == 'A'){
		C_num ++;
		if (iter == str.end())
			return(false);
	}
//	while(*(iter ++) == 'A') A_num ++;		
//	if (*(iter - 1) != 'P') return(false);	
//	while(*(iter ++) == 'A') B_num ++;	
//	if (*(iter - 1) != 'T') return(false);			
//	while(*(iter ++) == 'A') C_num ++;	
//		
//	if(A_num + B_num + C_num + 2 != str.length())
//		return(false);
		
//	std::cout << A_num << " " << B_num << " " << C_num << std::endl;

	if (A_num * B_num == C_num)
		return(true);
	else
		return(false);					
}


int main()
{
	int repeat_time;
	std::cin >> repeat_time;
	
	for (int i = 0; i < repeat_time; i ++){		
		std::string str;
		std::cin >> str;
		bool flag;
		flag = PAT_test(str);
		if (flag)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

}




