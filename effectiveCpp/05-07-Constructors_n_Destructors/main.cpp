/*

	05 编译器默认生成的函数
		默认构造函数 拷贝构造函数 赋值运算符
		声明任意构造函数，就不会生成默认构造函数，拷贝和赋值会有。

	06 不使用的函数，明确拒绝
		拷贝和赋值写成private
		C11可以用delete

	07 使用virtual 析构函数
		1. 释放基类指针，如果基类的析构不是虚函数，那么派生类的析构不会执行。
		2. 如果基类的析构不是虚函数，就不要去继承它，比如 std::string ，不然也可能有资源没释放。
*/

#include <iostream>

class allDefault {
public:
	virtual ~allDefault() {
		std::cout << " allDefault destructor" << std::endl;
	}
};

class nobase {

public:
	nobase(int i) : m_i(i){

	}
	
	~nobase() {
		std::cout << " nobase destructor" << std::endl;
	}
private:
	int m_i;
};

class inherit_Default : public allDefault {
public:
	~inherit_Default() {
		std::cout << " inherit_Default destructor" << std::endl;
	}
};

class inherit_nobase : public nobase {
public:
	inherit_nobase() : nobase(1){
	}

	~inherit_nobase() {
		std::cout << " inherit_nobase destructor" << std::endl;
	}
};

void test05_01();
void test05_02();
void test07_0102();

int main() {
	//test05_01();
	//test05_02();

	test07_0102();
}

void test05_01() {
	allDefault ins;//默认
	allDefault ins_1;
	allDefault ins_copy(ins);//拷贝

	ins_1 = ins_copy;//赋值
}

void test05_02() {
//	nobase ins;//没有默认了 编译不过
	nobase ins(1);
	nobase ins_copy(ins);//拷贝

	ins = ins_copy;//赋值
}

void test07_0102() {
	nobase* pNb = new inherit_nobase;
	allDefault* pAll = new inherit_Default;

	delete pNb;
	delete pAll;
}