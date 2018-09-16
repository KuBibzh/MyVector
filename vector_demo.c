/*================================================================
*   Copyright (C) 2018 Sangfor Ltd. All rights reserved.
*   
*   文件名称：vector_demo.c
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月15日
*   描    述：C++Vector容器类模板的C语言仿写
*
================================================================*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"vector_demo.h"

//创建容器
//利用返回值进行指针赋值
T* create(int*len,int *cap){
	*cap=100;
	*len=0;
	return (T*)malloc(sizeof(T)*(*cap));
}
//利用双重指针对传入的指针变量进行赋值
/*void create(T** array,int* len,int* cap){
	*cap=100;
	*array=(T*)malloc(sizeof(T)*(*cap));
	*len=0;
}*/
//在后方插入数据
void push_back(T* array,int* len,int* cap,const T* data){
	if(*cap==*len){
		T* buf=array;
		*cap+=50;
		array=(T*)malloc(sizeof(T)*(*cap));
		memcpy(array,buf,*len*sizeof(T));
		free(buf);
	}
	array[*len]=*data;
	++(*len);
}
//前面插入数据
void push_front(T* array,int* len,int* cap,const T* data){
	if(*cap==*len){
		T* buf=array;
        *cap+=50;
        array=(T*)malloc(sizeof(T)*(*cap));
        memcpy(array,buf,(*cap-50)*sizeof(T));
        free(buf);
	}
	int i=0;
	/*for(;i<*len;i++){
		array[*len-i]=array[*len-1-i];
	}*/
	for(i=*len-1;i>=0;i--){
		array[i+1]=array[i];
	}
	array[0]=*data;
	++(*len);
}
//根据位置信息插入数据
void insert(T* array,int* len,int* cap,int pos,const T* data){
	if(*cap==*len){
		T* buf=array;
		*cap+=50;
		array=(T*)malloc(sizeof(T)*(*cap));
		memcpy(array,buf,(*cap-50)*sizeof(T));
		free(buf);
	}
	if(pos<0)  pos=0;
	if(pos>*len) pos=*len;
	int i=0;
	/*for(;i<*len-pos;i++){
		array[*len-i]=array[*len-1-i];
	}*/
	for(i=*len-1;i>=pos;i--){
		array[i+1]=array[i];
	}
	array[pos]=*data;
	++(*len);
}
//清空容器
void clear(int* len){
	*len=0;
}
//移除某一数据
void _remove(T* array,int* len,int* cap,const T* data){
	if(*cap>5*(*len)){
		T* buf=array;
		array=(T*)malloc(sizeof(T)*2*(*len));
		memcpy(array,buf,sizeof(T)*(*len));
		free(buf);
		*cap=2*(*len);
	}
	int i=0;
	for(i=0;i<*len;i++){
		if(array[i]==*data){
			break;
		}
	}
	for(;i<*len-1;i++){
		array[i]=array[i+1];
	}
	--(*len);
}
//查找某一数据
int find(T* array,int len,const T* data){
	int i=0;
	for(i=0;i<len;i++){
		if(array[i]==*data) return i;
	}
	return -1;
}
//容器的遍历
void visit(T* array,int len,int(*show)(const T*)){
	int i=0;
	for(i=0;i<len;i++){
		if(!show(&array[i])) break;
	}
}
//容器的排序
void reverse(T* array,int len){
	int i=0;
	for(i=0;i<len/2;i++){
		T temp=array[i];
		array[i]=array[len-i-1];
		array[len-i-1]=temp;
	}
}
void sort(T* array,int len,int(*compare)(const T*,const T*)){
	//快排
	int i=0,j=len-1;
	T key=array[0];
	if(len<2) return;
	while(i!=j){
		while(i!=j && compare(&array[j],&key)) j--;
		array[i]=array[j];
		while(i!=j && compare(&key,&array[i])) i++;
		array[j]=array[i];
	}
	array[i]=key;
	key=array[i];
	sort(array,i,compare);
	sort(array+i+1,len-i-1,compare);

}
//销毁容器
void destroy(T* array){
	free(array);
}

