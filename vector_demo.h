/*================================================================
*   
*   文件名称：vector_demo.h
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月15日
*   描    述：C++Vector容器类模板C语言的仿写
*
================================================================*/


#ifndef _VECTOR_DEMO_H_
#define _VECTOR_DEMO_H_

    
typedef int T;

//创建容器
T* create(int* len,int* cap);
//void create(T** array,int* len,int* cap);
//在后方插入数据
void push_back(T* array,int* len,int* cap,const T* data);
//前面插入数据
void push_front(T* array,int* len,int* cap,const T* data);
//根据位置信息插入数据
void insert(T* array,int* len,int* cap,int pos,const T* data);
//清空容器
void clear(int* len);
//移除某一数据
void _remove(T* array,int* len,int* cap,const T* data);
//查找某一数据
int find(T* array,int len,const T* data);
//C语言的Vector容器长度只能由外部外部传入
//貌似empty函数和size函数没有什么用
//void empty(int len);
//void size(int len);
//容器的遍历
void visit(T* array,int len,int(*show)(const T*));
//容器的逆序
void reverse(T* array,int len);
//排序
void sort(T* array,int len,int(*compare)(const T*,const T*));
//销毁容器
void destroy(T* array);

    
    
    
#endif
