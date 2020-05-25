// vector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<cstring>
using namespace std;

template <typename T>
class Vector
{
public:
	//无参构造的初始化
	Vector() :p(NULL), capacity(0), size(0)
	{
		//this->capacity = 20;
		//this->size = 0;
		//T *p = new T[capacity];
	}
	//有参构造的初始化方式
	Vector(int size, T data)
	{
		this->capacity = 20 + size;
		this->size = size;
		this->p = new T[capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->p[i] = data;
		}
	}
	//析构函数，释放掉唯一的指针
	~Vector()
	{
		if (p != NULL)
		{
			delete[] p;
		}
	}
	//拷贝构造函数
	Vector(const Vector& v)
	{
		//令人发指，如果直接调用拷贝构造，虽然没给成员变量p赋值，但这个指针不是空的
		//等号赋值那里可以加上判断是否为空
		this->capacity = v.capacity;
		this->size = v.size;
		this->p = new T[this->capacity];
		memcpy(this->p, v.p, this->size * sizeof(T));
	}

	//打印容器内容
	void print()
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << this->p[i] << '\t';
		}
		cout << endl;
	}
	//插入，要判断溢出没
	void push_back(T data)
	{
		if (this->p == NULL)
		{
			this->capacity = 20;
			this->size = 0;
			T* p = new T[capacity];
		}
		if (this->size == this->capacity)
		{
			//如果满了，每次容量拓展到2倍
			T* new_p = new T[this->capacity * 2];
			memcpy(new_p, p, this->size * sizeof(T));
			this->capacity *= 2;
			delete[] p;
			p = new_p;

		}
		this->print();
		this->p[this->size] = data;
		this->size++;
	}
	//删除最后一个元素，无返回值
	void pop_back()
	{
		if (this->size > 1)
		{
			this->p[this->size - 1] = 0;
			this->size--;
		}
	}
	//插入
	void insert(int pos, T data)
	{
		if (pos >= 0 && pos <= this->size)
		{

			if (this->size == this->capacity)
			{
				//如果满了，每次容量拓展到2倍
				T* new_p = new T[this->capacity * 2];
				memcpy(new_p, p, this->size * sizeof(T));
				this->capacity *= 2;
				delete[] p;
				p = new_p;
			}
			for (int i = this->size; i > pos; i--)
			{
				this->p[i] = this->p[i - 1];
			}
			this->p[pos] = data;
			this->size++;

		}
	}
	//清除，很佛系，假装清除了
	void clear()
	{
		this->size = 0;
	}
	//重载[]运算符，可以用[]修改函数
	T& operator[](int index)
	{
		if (index > 0 && index < this->size)
		{
			return this->p[index];
		}
	}
	//重载赋值=，其实和拷贝构造函数一个样
	void operator=(const Vector& v)
	{
		if (this->p != NULL)
		{
			delete[] this->p;
			this->capacity = 0;
			this->size = 0;
			this->p = NULL;
		}
		this->capacity = v.capacity;
		this->size = v.size;
		this->p = new T[this->capacity];
		memcpy(this->p, v.p, this->size * sizeof(T));
	}



	//故意打成public的
public:
	T* p;
	int capacity;
	int size;

};

void test()
{
	Vector<int> v(3, 1);
	v.print();
	cout << "size: " << v.size << " capacity: " << v.capacity << endl;
	for (int iter = 0; iter < 11; iter++)
	{
		v.push_back(iter);
	}
	v.print();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.print();
	v[3] = 10086;
	v.print();

	cout << "what" << endl;
	Vector<int> v2(v);
	v2.print();

	Vector<int> v3 = v;
	v3.print();

	Vector<int> v4;
	v4 = v;
	v4.print();

	cout << "size: " << v4.size << " capacity: " << v4.capacity << endl;
	v4.insert(1, 11111);
	v4.insert(0, 22222);
	v4.insert(v4.size - 1, 33333);
	v4.insert(v4.size, 44444);
	// v4.insert(2,11111);
	v4.print();
	v4.clear();
	v4.print();
}

int main()
{
	test();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
