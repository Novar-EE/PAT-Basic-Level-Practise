#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

long long gcd(long long a, long long b);

class Frac
{
public:
	long long a;
	long long b;
	long long I;
	int flag;
	bool flag_Inf;
	double ab;

public:
	Frac(std::string str);
	void print_ab();
	Frac operator+=(Frac &lhd);
	Frac operator-=(Frac &lhd);
	Frac operator*=(Frac &lhd);
	Frac operator/=(Frac &lhd);
	

private:
	void frac_simplify();
	void print_sub_ab();

};

Frac::Frac(std::string str)
{
	std::string::iterator iter = str.begin();
	this->a = 0; this->b = 0; 
	this->flag = 1; this->flag_Inf = false;
	
	if (*iter == '-'){
		this->flag = -1;
		iter ++;
	}
	for (; *iter != '/'; iter ++){
		this->a = this->a * 10 + *iter - '0';
	}
	for (iter ++; iter != str.end(); iter ++){
		this->b = this->b * 10 + *iter - '0';
	}
	
	this->frac_simplify();		
	
}

void Frac::frac_simplify()
{
	long long ab_gcd = gcd(this->a, this->b);
	this->a = this->a / ab_gcd;
	this->b = this->b / ab_gcd;
	this->ab = 1.0 * this->flag * (this->a) / (this->b);
	
	this->I = this->a / this->b;
	this->a = this->a % this->b;
}

void Frac::print_ab()
{
	if (this->flag_Inf)
		printf("Inf"); 	
	else if (this->I == 0 && this->a == 0)
		printf("0");
	else if (this->flag == -1){
		printf("(-");
		this->print_sub_ab();
		printf(")");
	}
	else
		print_sub_ab();
}

void Frac::print_sub_ab()
{
	if (this->I != 0){
		printf("%d", this->I);
		if (this->a != 0)
			printf(" ");
	}
		
	if (this->a == 0) return;
	
	printf("%d", this->a);
	if (this->b != 1)
		printf("/%d", this->b);	
	
}

long long gcd(long long a, long long b)
{
	if (a < b){
		long long tmp = a;
		a = b; b = tmp;
	} 
	if (b == 0) 
		return(1);
		
	while (a % b != 0){
		long long tmp = a % b;
		a = b; b = tmp;
	}
	return(b);
}

Frac Frac::operator+=(Frac &lhd)
{
	long long a1, a2;
	a1 = (this->a + this->I * this->b) * this->flag * lhd.b;
	a2 = (lhd.a + lhd.I * lhd.b) * lhd.flag * this->b;
	this->b = this->b * lhd.b;
	
	this->a = a1 + a2;
	if (this->a >= 0)
		this->flag = 1;
	else{
		this->flag = -1;
		this->a = -1 * this->a;
	}	
	this->frac_simplify();
	
}

Frac Frac::operator-=(Frac &lhd)
{
	long long a1, a2;
	a1 = (this->a + this->I * this->b) * this->flag * lhd.b;
	a2 = (lhd.a + lhd.I * lhd.b) * lhd.flag * this->b;
	this->b = this->b * lhd.b;
	
	this->a = a1 - a2;
	if (this->a >= 0)
		this->flag = 1;
	else{
		this->flag = -1;
		this->a = -1 * this->a;
	}	
	this->frac_simplify();
	
}

Frac Frac::operator*=(Frac &lhd)
{
	long long a1, a2;
	a1 = (this->a + this->I * this->b) * this->flag;
	a2 = (lhd.a + lhd.I * lhd.b) * lhd.flag;
	
	this->a = a1 * a2;
	this->b = this->b * lhd.b;	
	
	if (this->a >= 0)
		this->flag = 1;
	else{
		this->flag = -1;
		this->a = -1 * this->a;
	}	
	this->frac_simplify();
	
}

Frac Frac::operator/=(Frac &lhd)
{
	long long a1, a2;
	a1 = (this->a + this->I * this->b) * this->flag;
	a2 = (lhd.a + lhd.I * lhd.b) * lhd.flag;
	
	if (a2 == 0){
		this->flag_Inf = true;
	}
	else{
		this->a = a1 * lhd.b;
		this->b = this->b * a2;	
		
		if (this->a * this->b >= 0)
			this->flag = 1;
		else{
			this->flag = -1;
			if (this->a < 0)
				this->a = -1 * this->a;
			else
				this->b = -1 * this->b;
		}		
		this->frac_simplify();
	}
}


Frac operator+(Frac &rhd, Frac &lhd)
{
	Frac tmp = rhd;
	tmp += lhd;
	return(tmp);	
}

Frac operator-(Frac &rhd, Frac &lhd)
{
	Frac tmp = rhd;
	tmp -= lhd;
	return(tmp);	
}

Frac operator*(Frac &rhd, Frac &lhd)
{
	Frac tmp = rhd;
	tmp *= lhd;
	return(tmp);	
}

Frac operator/(Frac &rhd, Frac &lhd)
{
	Frac tmp = rhd;
	tmp /= lhd;
	return(tmp);	
}


int main()
{
	std::string str1, str2;
	std::cin >> str1 >> str2;
	
	Frac N1(str1);	
	Frac N2(str2);
	
	N1.print_ab(); std::cout << " + "; N2.print_ab(); std::cout << " = ";
	(N1 + N2).print_ab(); std::cout << std::endl;
	N1.print_ab(); std::cout << " - "; N2.print_ab(); std::cout << " = ";
	(N1 - N2).print_ab(); std::cout << std::endl;
	N1.print_ab(); std::cout << " * "; N2.print_ab(); std::cout << " = ";
	(N1 * N2).print_ab(); std::cout << std::endl;
	N1.print_ab(); std::cout << " / "; N2.print_ab(); std::cout << " = ";
	(N1 / N2).print_ab(); std::cout << std::endl;
	
}
