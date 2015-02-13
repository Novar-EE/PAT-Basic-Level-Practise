#include <iostream>
#include <algorithm>
#include <string>


int main()
{
	int N = 0;
	int n;
	
	int A1 = 0;
	int A2 = 0, A2_flag = 1;
	int A3 = 0;
	int A4_sum = 0, A4_num = 0;
	int A5 = 0;
	
	bool flag[5] = {false};
	
	std::cin >> N;
	for (int i = 0; i < N; i ++){
		
		std::cin >> n;
		char c = getchar();
		if (n % 5 == 0 && n % 2 == 0){
			A1 += n;
			flag[0] = true;
		}
		if (n % 5 == 1){
			
			A2 = A2 + A2_flag * n;
			A2_flag *= -1;
			flag[1] = true;
		}
		if (n % 5 == 2){
			A3 ++;
			flag[2] = true;
		}
		if (n % 5 == 3){
			A4_sum += n;
			A4_num ++;
			flag[3] = true;
		}
		if (n % 5 == 4){
			if (n > A5) A5 = n;
			flag[4] = true;
		}		
	}
	
	int res[5] = {A1, A2, A3, 0, A5};
	
	for (int i = 0; i < 5; i ++){
		if (flag[i]){
			if (i == 3){
				double tmp = 1.0 * A4_sum / A4_num;
				printf("%.1lf", tmp);
			}
			else{
				std::cout << res[i];
			}
		}
		else
			std::cout << "N";
			
		if (i == 4)
			std::cout << std::endl;
		else
			std::cout << " ";
	}
	
	
	
}

