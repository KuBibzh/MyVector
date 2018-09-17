/*================================================================
*   
*   文件名称：MyVector.h
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月16日
*   描    述：C++Vector类模板的仿写
*
================================================================*/


#ifndef _MYVECTOR_H_
#define _MYVECTOR_H_
#include<cstring>
#include<iostream>
template <class T>
class MyVector{
	private:
		T* array;
		int len;
		int cap;
		enum{INCREMENT=50};
	private:
		//快速排序的实现
		void sort(T* array,int len,int(*cmp)(const T&,const T&)){
			if(len<2) return;
			int i=0,j=len-1;
			T key=array[0];

			while(i!=j){
				while(i!=j && cmp(array[j],key)) j--;
				array[i]=array[j];
				while(i!=j && cmp(key,array[i])) i++;
				array[j]=array[i];
			}
			array[i]=key;
			sort(array,i,cmp);
			sort(array+i+1,len-i-1,cmp);
		}
	public:
		//无参构造函数，容器大小默认
		MyVector(){
			cap=100;
			len=0;
			array=new T[cap];
		}
		//用户传入容器大小的带参构造函数
		MyVector(int cap):cap(cap){
			len=0;
			array=new T[cap];
		}
		//析构函数
		~MyVector(){
			delete[] array;
		}
		//向头部插入
		void push_front(const T& data){
			if(len==cap){
				cap+=INCREMENT;
				T* buf=array;
				array=new T[cap];
				memcpy(array,buf,sizeof(T)*cap);
				delete[] buf;
			}
			for(int i=len-1;i>=0;i--){
				array[i+1]=array[i];
			}
			array[0]=data;
			len++;
		}
		//向尾部插入
		void push_back(const T& data){
			if(len==cap){
				cap+=INCREMENT;
				T* buf=array;
				array=new T[cap];
				memcpy(array,buf,sizeof(T)*cap);
				delete[] buf;
			}
			array[len]=data;
			len++;
		}
		//朝指定位置插入
		void insert(int pos,const T& data){
			if(len==cap){
				cap+=INCREMENT;
				T* buf=array;
				array=new T[cap];
				memcpy(array,buf,sizeof(T)*cap);
				delete[] buf;
			}
			if(pos<0) pos=0;
			if(pos>len) pos=len;
			for(int i=len-1;i>=pos;i--){
				array[i+1]=array[i];
			}
			array[pos]=data;
			len++;
		}
		//移除跟指定数据相同的容器项
		bool remove(const T& data){
			if(cap>5*len){
				cap=2*len;
				T* buf=array;
				array=new T[cap];
				memcpy(array,buf,sizeof(T)*len);
				delete[] buf;
			}
			for(int i=0;i<len;i++){
				if(array[i]==data){
					for(;i<len;i++){
						array[i]=array[i+1];
					}
					return true;
				}
			}
			return false;
		}
		//查找指定数据的位置
		int find(const T& data){
			for(int i=0;i<len;i++){
				if(array[i]==data) return i;
			}
			throw 1;

		}
		//判断容器是否为空
		bool empty(){
			return !len;
		}
		//判断容器数据长度
		int size(){
			return len;
		}
		//清空容器
		void clear(){
			len=0;
		}
		//遍历
		void visit(int(*show)(const T&)){
			for(int i=0;i<len;i++){
				if(!show(array[i]))
					break;
			}
		}
		//数据遍历
		void reverse(){
			for(int i=0;i<len/2;i++){
				T temp=array[i];
				array[i]=array[len-i-1];
				array[len-i-1]=temp;
			}
		}
		//数据排序
		void sort(int(*cmp)(const T&,const T&)){
			sort(array,len,cmp);
		}
		//根据传入参数访问数据
		T& operator[](int n){
			if(n<0 || n>=len) throw 1;
			return array[n];
		}

};



    
    
#endif
