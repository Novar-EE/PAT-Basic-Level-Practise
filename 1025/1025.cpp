#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>

class Node
{
public:
	int addr;
	int value;
	int next_addr;

};

Node list[100010];

void print_list(int head_addr)
{
	int index = head_addr;
	while (list[index].next_addr != -1){
		printf("%05d %d %05d\n", index, list[index].value, list[index].next_addr);
		index = list[index].next_addr;
	}
	printf("%05d %d %d\n", index, list[index].value, list[index].next_addr);
}

void list_reverse(int pre_head_addr, int head_addr, int *new_head_addr, int *new_tail_addr, int list_len)
{
	int pre = head_addr;	
	int head = list[pre].next_addr;
	int next;
		
	for (int i = 0; i < list_len - 1; i ++){
		next = list[head].next_addr;
		list[head].next_addr = pre;
//		list[next].next_addr = head;
		
		pre = head;
		head = next;			
	}
	*new_tail_addr = head_addr;
	*new_head_addr = pre;
	
	if (pre_head_addr != -1){
		list[pre_head_addr].next_addr = *new_head_addr;
	}
	list[*new_tail_addr].next_addr = next;
}


int main()
{
	int N, K;
	int head_addr;
	scanf("%d %d %d", &head_addr, &N, &K); getchar();
	
	for (int i = 0; i < N; i ++){
		int tmp_addr, tmp_value, tmp_next_addr;
		scanf("%d %d %d", &tmp_addr, &tmp_value, &tmp_next_addr); getchar();
		list[tmp_addr].addr = tmp_addr;
		list[tmp_addr].value = tmp_value;
		list[tmp_addr].next_addr = tmp_next_addr;
	}
	
	
	int index = head_addr;
	int cnt = 0;

//	printf("\n");print_list(head_addr);

	int sub_head_addr, sub_tail_addr;
	int new_head_addr;
	list_reverse(-1, head_addr, &new_head_addr, &sub_tail_addr, K);
//	printf("\n");print_list(new_head_addr);
	for (int cnt = K; cnt + K <= N; cnt = cnt + K){
		int tmp_head_addr = list[sub_tail_addr].next_addr;
		list_reverse(sub_tail_addr, tmp_head_addr, &sub_head_addr, &sub_tail_addr, K);
//		printf("\n");print_list(new_head_addr);
	}
	
//	printf("\n");
	print_list(new_head_addr);


}

