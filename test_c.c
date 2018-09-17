/*================================================================
*   
*   文件名称：test_c.c
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月16日
*   描    述：C语言仿写C++Vector类模板的测试
*
================================================================*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"vector_demo.h"
int showINT(const T* a){
    printf("%d ",*a);
    return 1;
}
int cmp(const T* a,const T* b){
    return *a>=*b;
}
int main(){
	int b=1,c=3,d=4,e=5;
    int* a=NULL;
	int alen,acap;
	a=create(&alen,&acap);    
	push_front(a,&alen,&acap,&b);
	push_front(a,&alen,&acap,&c);
	push_back(a,&alen,&acap,&c);
	push_front(a,&alen,&acap,&d);
	insert(a,&alen,&acap,2,&c);
	push_front(a,&alen,&acap,&e);
	visit(a,alen,showINT);
	printf("\n");

	reverse(a,alen);
	visit(a,alen,showINT);
	printf("\n");
    
	sort(a,alen,cmp);
	visit(a,alen,showINT);
	printf("\n");
    return 0;
}
