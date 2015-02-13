#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

class student_info
{
public:
	int ID;
	int score_1;	// 德分 
	int score_2;	// 才分 
	int score_total;
};

bool cmp(const student_info &arg1, const student_info &arg2)
{
	if (arg1.score_total == arg2.score_total){
		if (arg1.score_1 == arg2.score_1)
			return(arg1.ID < arg2.ID);
		return(arg1.score_1 > arg2.score_1);
	}
	return(arg1.score_total > arg2.score_total);

/*
	if (arg1.score_total != arg2.score_total)
		return(arg1.score_total > arg2.score_total);		
	else if (arg1.score_1 != arg2.score_1)
		return(arg1.score_1 > arg2.score_1);
	else
		return(arg1.ID < arg2.ID);
*/
}

void print_vec(std::vector<student_info>::iterator iter_start, std::vector<student_info>::iterator iter_end)
{
	for (std::vector<student_info>::iterator iter = iter_start; iter != iter_end; iter ++){
		std::cout << iter->ID << " " << iter->score_1 << " " << iter->score_2 << std::endl;
	}
}



int main()
{
	int N, L, H;
	scanf("%d %d %d", &N, &L, &H);
//	std::vector<student_info> vec[4];
	student_info vec[4][100010];
	int vec_size[4] = {0};
	
	for (int i = 0; i < N; i ++){
		student_info tmp;
		scanf("%d %d %d", &tmp.ID, &tmp.score_1, &tmp.score_2);
		tmp.score_total = tmp.score_1 + tmp.score_2;
		if (tmp.score_1 >= L && tmp.score_2 >= L){
			if (tmp.score_1 >= H && tmp.score_2 >= H){
				//vec[0].push_back(tmp);
				vec[0][vec_size[0]] = tmp;
				vec_size[0] ++;
			}
			else if (tmp.score_1 >= H && tmp.score_2 < H){
				//vec[1].push_back(tmp);
				vec[1][vec_size[1]] = tmp;
				vec_size[1] ++;
			}
			else if (tmp.score_1 < H && tmp.score_2 < H && tmp.score_1 >= tmp.score_2){
				//vec[2].push_back(tmp);
				vec[2][vec_size[2]] = tmp;
				vec_size[2] ++;
			}
			else{
				//vec[3].push_back(tmp);
				vec[3][vec_size[3]] = tmp;
				vec_size[3] ++;
			}
		}		
	}
	
	int tot = 0;
	for (int i = 0; i < 4; i ++){
		tot += vec_size[i];
	}
	std::cout << tot << std::endl;
	
	for (int i = 0; i < 4; i ++){
		//std::cout << i << std::endl;
		std::sort(vec[i], vec[i] + vec_size[i], cmp);
		
		for (int j = 0; j < vec_size[i]; j ++){
			printf("%d %d %d\n", vec[i][j].ID, vec[i][j].score_1, vec[i][j].score_2);

		}
//		std::cout << vec[i][j].ID << " " << vec[i][j].score_1 << " " << vec[i][j].score_2 << std::endl;
//		print_vec(vec[i].begin(), vec[i].end());
	}


}
