#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>

class student_info
{
public:
// 用name[10]只得2分，用 name[115]就 满分了，说好的“姓名和学号均为不超过10个字符的字符串”呢。。。
 
	char name[15];
	char ID[15];
	int score;

	bool operator<(const student_info &rhs) const;

};


bool student_info::operator<(const student_info &rhs) const
{
	return(this->score < rhs.score);
}

bool compare(const student_info & arg1, const student_info & arg2)
{
	return(arg1.score < arg2.score);
}


int main()
{
	int student_num = 0;
	std::cin >> student_num;
	std::vector<student_info> vec_student;
	
	for (int i = 0; i < student_num; i ++){
		student_info tmp;
		scanf("%s %s %d", &tmp.name, &tmp.ID, &tmp.score);
		vec_student.push_back(tmp);
	}
	
	std::sort(vec_student.begin(), vec_student.end(), compare);
	
	student_info student_max = vec_student[student_num - 1];
	student_info student_min = vec_student[0];
	
	std::cout << student_max.name << " " << student_max.ID << std::endl;
	std::cout << student_min.name << " " << student_min.ID << std::endl;	

	
}

