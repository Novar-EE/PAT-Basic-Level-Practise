#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

#define TODAY_YY 2014
#define TODAY_MM 9
#define TODAY_DD 6

class Person
{
public:
	Person(std::string name, std::string birthday);
	void print_person();
	bool operator<(const Person &rhd) const;
	
public:
	std::string name;
	std::string birthday;
	int YY, MM, DD;
	bool person_flag;

private:
	bool check_date();
	
	
};

Person::Person(std::string name, std::string birthday)
{
	this->name = name;
	this->YY = 0;
	this->MM = 0;
	this->DD = 0;
	this->person_flag= true;
	
	std::string::iterator iter = birthday.begin();
	for (; *iter != '/'; iter ++)
		this->YY = *iter - '0' + 10 * this->YY;
	for (iter ++; *iter != '/'; iter ++)
		this->MM = *iter - '0' + 10 * this->MM;
	for (iter ++; iter != birthday.end(); iter ++)
		this->DD = *iter - '0' + 10 * this->DD;
		
	this->person_flag = this->check_date();
	
}

bool Person::check_date()
{
	bool flag = true;
	if (this->YY > TODAY_YY)
		flag = false;
	else if (this->YY == TODAY_YY){
		if (this->MM > TODAY_MM)
			flag = false;
		else if (this->MM == TODAY_MM){
			if (this->DD > TODAY_DD)
				flag = false;
		}
	}
	
	int age = TODAY_YY - this->YY;
	if (age > 200)
		flag = false;
	else if (age == 200){
		if (this->MM < TODAY_MM)
			flag = false;
		else if (this->MM == TODAY_MM){
			if (this->DD < TODAY_DD)
				flag = false;
		}
	}
	
	return(flag);
}

void Person::print_person()
{
	std::cout << this->name << " ";
	printf("%d %d %d ", this->YY, this->MM, this->DD);
	std::cout << this->person_flag << std::endl;
}

bool Person::operator<(const Person &rhd) const
{
	if (this->YY == rhd.YY){
		if (this->MM == rhd.MM){
			return(this->DD < rhd.DD);
		}	
		return(this->MM < rhd.MM);
	}
	return(this->YY < rhd.YY);
}


int main()
{
	int N;
	std::cin >> N;
	std::vector<Person> vec;
	
	for (int i = 0; i < N; i ++){
		std::string tmp_name, tmp_birthday;
		std::cin >> tmp_name >> tmp_birthday;
	
		Person tmp(tmp_name, tmp_birthday);
		//tmp.print_person();
		if (tmp.person_flag)
			vec.push_back(tmp);
	}
	
	std::vector<Person>::size_type person_num = vec.size();	
	
	// segment error: forget the 0 size 
	if (person_num != 0){
		std::cout << person_num << " ";
		std::sort(vec.begin(), vec.end());	
		std::vector<Person>::iterator iter = vec.begin();		

		std::cout << iter->name << " ";
		iter = vec.end() - 1;
		std::cout << iter->name << std::endl;
	}
	else{
		std::cout << person_num << std::endl;
	}

		
	
}
