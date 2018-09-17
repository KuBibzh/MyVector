/*================================================================
*   
*   文件名称：test_cpp.cpp
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月16日
*   描    述：MyVector类模板的测试
*
================================================================*/


#include<iostream>
#include"MyVector.h"
int show(const int& a){
	std::cout<<a<<" ";
	return 1;
}
int compare(const int& a,const int& b){
	return a>=b;
}
int main(){
	MyVector<int> vector;
	//测试加入
	vector.push_back(1);
	vector.push_front(2);	
	vector.push_front(9);
	vector.push_back(88);
	vector.push_back(0);
	vector.push_front(23);
	vector.push_front(66);
	vector.insert(3,9);
	//测试查找
	std::cout<<vector.find(2)<<std::endl;
	//测试容器遍历
	vector.visit(show);
	std::cout<<std::endl;
	//测试移除
	if(!vector.remove(100)){
		std::cout<<"没有此数据！"<<std::endl;
	}
	//测试[]操作符重载
	try{
		std::cout<<vector[3]<<std::endl;
	
		vector[100];
	}
	catch(int){
		std::cout<<"超出界限！"<<std::endl;	
	}
	//测试排序
	vector.sort(compare);
	vector.visit(show);
	std::cout<<std::endl;
	//测试逆序
	vector.reverse();
	vector.visit(show);
	std::cout<<std::endl;
	//测试容器清空，容器是否为空函数
	vector.clear();
	if(vector.empty()){
		std::cout<<"容器为空！"<<std::endl;	
	}



	return 0;
}
