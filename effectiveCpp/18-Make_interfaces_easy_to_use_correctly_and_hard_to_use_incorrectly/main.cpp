/*
	用户正常使用，接口达不到用户要的效果，就不该编译通过。
	接口不容易误用，并容易使用。

	1 资源管理
		使用shared_ptr自动释放资源， 同时可指定删除器

	2 限制类型
		参数不用内置类型，使用自定义类型。 避免参数用混 比如 月份和日 用反

	3 限制值
		有限值，比如月份，使用函数代替
		书里说enum不具有类型安全性 即int可以转换成enum 


		 c11 有 enumclass，  2、3 的问题，都可以解决了

	4 限制操作
		int a , b, c;
		a * b = c;  //限制这种操作
		即所有的操作，都参考内置类型。
*/
#include <memory>
#include <iostream>

class Data {
public:
	enum class YEAR {
		Y2024 = 2024,
	};

	enum class MONTH {
		M1 = 1,
		M2 = 2,
	};

	enum class DAY {
		D1 = 1,
		D2 = 2,
	};

	void setDate_0(int year, int month, int day) {}
	void setDate_1(YEAR year, MONTH mon, DAY day) {}

};

void customDeleter(Data* ptr) {
	std::cout << "customDeleter" << std::endl;
	delete ptr;
}

void test01();

int main() {
	test01();
}

void test23() {
	Data d;

	d.setDate_0(2024, 03, 12);
	d.setDate_0(03, 2024, 32);//参数搞反  日期越界 都无法识别出来。

	//d.setDate_1(2024, 03, 12);//限制参数类型
	//d.setDate_1(Data::YEAR::Y2024, Data::DAY::D1, Data::MONTH::M1);//限制参数顺序
	//d.setDate_1(Data::YEAR::Y2024, Data::MONTH::M1, Data::DAY::D3);//限制参数大小
	d.setDate_1(Data::YEAR::Y2024, Data::MONTH::M1, Data::DAY::D1);
}

void test04() {
	Data a, b, c;

	//(a * b) = c; //没有找到很好的方法去禁止这种行为。
}

void test01(){
	std::shared_ptr<Data> p = std::shared_ptr<Data>(new Data(), customDeleter);
}