#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

class moon_cake
{
public:
	double price;
	double total_price;
	double num;
	
	bool operator<(const moon_cake &rhd) const;

};

bool moon_cake::operator<(const moon_cake &rhd) const
{
	if (this->price == rhd.price)
		return(this->num < rhd.num);
	return(this->price < rhd.price);
}

bool cmp(moon_cake &arg1, moon_cake &arg2)
{
	if (arg1.price == arg2.price)
		return(arg1.num < arg2.num);
	return(arg1.price < arg2.price);
}

int main()
{
	int kind, N;
	scanf("%d %d", &kind, &N);
	std::vector<moon_cake> vec;

	for (int i = 0; i < kind; i ++){
		moon_cake tmp;
		scanf("%lf", &tmp.num); getchar();
		vec.push_back(tmp);
	}
	for (int i = 0; i < kind; i ++){
		scanf("%lf", &vec[i].total_price);
		vec[i].price = 1.0 * vec[i].total_price / vec[i].num;
	}
	
	std::sort(vec.begin(), vec.end());
	
	double num = 0;
	int i = kind - 1;
	double total_price = 0;
	while(i >=0){
		
		if (num + vec[i].num > N){
			total_price += (N - num) * vec[i].price;
			break;
		}
		num += vec[i].num;
		total_price += vec[i].total_price;
		i --;
		
	}
	printf("%.2lf\n", total_price);
	
	
//	for (int i = 0; i < kind; i ++){
//		printf("%lf %lf %lf\n", vec[i].num, vec[i].total_price, vec[i].price);
//	}
	
}

