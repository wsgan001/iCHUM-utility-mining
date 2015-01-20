#include<iostream>
using namespace std;

#include "HeadTable.h"
#include "pardhp.h"

HeadTable::HeadTable(const double *&d){
	int count = 0;
	int i;
	for (i = 0; i < maxitem; i++){
		if (d[i] >= MIN_UTILITY){
			count++;
		}
	}
	size = count;
	
	count = 0;
	HeadNode = (item_2 *)calloc(size, sizeof(item_2));
	for (i = 0; i<maxitem; i++) {
		if (d[i] >= MIN_UTILITY){
			HeadNode[count].item2 = i;//��������Ʒ���
			HeadNode[count].t_utility = d[i];//��������Ʒ��TWUֵ
			count++;
		}
	}
	
}

HeadTable::HeadTable(const double *&d,int c){
	size = c;
	HeadNode = (item_2 *)calloc(size, sizeof(item_2));
	for (int i = 0; i < maxitem; i++){
		if (d[i] >= MIN_UTILITY){
			HeadNode[count].item2 = i;//��������Ʒ���
			HeadNode[count].t_utility = d[i];//��������Ʒ��TWUֵ
			count++;
		}
	}
}

HeadTable::~HeadTable(){
	clear();
}

void HeadTable::TWU_sort(){
	qsort(HeadNode, size, sizeof(item_2), compare);
}

int compare(const void *a, const void*b){//�Ӵ�С����
	item_2 arg1 = *reinterpret_cast<const item_2*>(a);
	item_2 arg2 = *reinterpret_cast<const item_2*>(b);
	if (arg1.t_utility < arg2.t_utility) { return 1; }
	if (arg1.t_utility == arg2.t_utility) { return 0; }
	if (arg1.t_utility > arg2.t_utility) { return -1; }
}

void HeadTable::clear(){
	delete[] HeadNode;
	size = 0;
}