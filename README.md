# C++Vector容器模版类的仿写
## 分别由C语言的仿写和C++语言的仿写
## 版本
### v1.00
实现了Vector容器类模板的功能

## 函数展示
		void sort(T* array,int len,int(*cmp)(const T&,const T&));
		MyVector();
		MyVector(int cap);
		~MyVector();
		void push_front(const T& data);
		void push_back(const T& data);
		void insert(int pos,const T& data);
		bool remove(const T& data);
		int find(const T& data);
		bool empty();
		int size();
		void clear();
		void visit(int(*show)(const T&));
		void reverse();
		void sort(int(*cmp)(const T&,const T&));

		T& operator[](int n);
