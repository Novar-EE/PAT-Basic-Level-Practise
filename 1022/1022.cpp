#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

int main()
{
	long long A, B;
	int D;
	scanf("%lld %lld %d", &A, &B, &D);
	
	long long sum = A + B;
	std::stack<long long> S;
	
	while(sum >= D){		
		S.push(sum % D);
		sum /= D;			
	}
	S.push(sum);
	
	while(!S.empty()){
		std::cout << S.top();
		S.pop();
	}
	std::cout << std::endl;
	
}
