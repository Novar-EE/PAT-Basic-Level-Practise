#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

// 可能存在无效节点。。。。 

class Node
{
public:
	int addr;
	int value;
	int next_addr;

public:
	void print_node();
	void operator=(const Node &rhd);

};

void Node::print_node()
{
	if (next_addr != -1)
		printf("%05d %d %05d\n", this->addr, this->value, this->next_addr);
	else
		printf("%05d %d %d\n", this->addr, this->value, this->next_addr);	
}

void Node::operator=(const Node &rhd)
{
	this->addr = rhd.addr;
	this->value = rhd.value;
	this->next_addr = rhd.next_addr;	
}



Node list[100010];
Node r_list[100010];

int main()
{
	int head_addr;
	int N, K;	
	std::cin >> head_addr >> N >> K;

	int tmp_addr;
	for (int i = 0; i < N; i ++){
		std::cin >> tmp_addr;
		list[tmp_addr].addr = tmp_addr;
		std::cin >> list[tmp_addr].value >> list[tmp_addr].next_addr;
	}
	
	int next_addr = head_addr;
	int cnt = 0;
	while (next_addr != -1){
		r_list[cnt] = list[next_addr];
		// list[next_addr].print_node();
		next_addr = list[next_addr].next_addr;
		cnt ++;
	}
	
	int new_head_addr = r_list[K - 1].addr;
	int part_num = cnt / K + 1;	
	int part_head = 0;
	int part_tail = K - 1;
	
	for (int i = 0; i < part_num; i ++){
	
		part_head = i * K;
		part_tail = (i + 1) * K - 1;
		
		if (part_head + K <= cnt){
			
			for (int j = part_tail; j > part_head; j --){
				r_list[j].next_addr = r_list[j - 1].addr;
			}
			
			if (part_head + 2 * K - 1 < cnt)
				r_list[part_head].next_addr = r_list[part_head + 2 * K - 1].addr;	
			
			// cnt % K == 0		
			else if (part_head + K == cnt)
				r_list[part_head].next_addr = -1;			
			else 
				r_list[part_head].next_addr = r_list[part_head + K].addr;				
			
			for (int j = part_tail; j >= part_head; j --)
				r_list[j].print_node();					
		}
		
		else{
			
			for (int j = part_head; j < cnt; j ++){
				r_list[j].print_node();
			}
			break;
		}		
	}


}



/*
00100 7 1
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
12323 12 12312


00100 1 12309
12309 2 33218
33218 3 00000
00000 4 99999
99999 5 68237
68237 6 -1

*/


