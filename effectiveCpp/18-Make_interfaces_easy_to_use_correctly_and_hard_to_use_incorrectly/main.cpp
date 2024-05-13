/*
	�û�����ʹ�ã��ӿڴﲻ���û�Ҫ��Ч�����Ͳ��ñ���ͨ����
	�ӿڲ��������ã�������ʹ�á�

	1 ��Դ����
		ʹ��shared_ptr�Զ��ͷ���Դ�� ͬʱ��ָ��ɾ����

	2 ��������
		���������������ͣ�ʹ���Զ������͡� ��������û� ���� �·ݺ��� �÷�

	3 ����ֵ
		����ֵ�������·ݣ�ʹ�ú�������
		����˵enum���������Ͱ�ȫ�� ��int����ת����enum 


		 c11 �� enumclass��  2��3 �����⣬�����Խ����

	4 ���Ʋ���
		int a , b, c;
		a * b = c;  //�������ֲ���
		�����еĲ��������ο��������͡�
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
	d.setDate_0(03, 2024, 32);//�����㷴  ����Խ�� ���޷�ʶ�������

	//d.setDate_1(2024, 03, 12);//���Ʋ�������
	//d.setDate_1(Data::YEAR::Y2024, Data::DAY::D1, Data::MONTH::M1);//���Ʋ���˳��
	//d.setDate_1(Data::YEAR::Y2024, Data::MONTH::M1, Data::DAY::D3);//���Ʋ�����С
	d.setDate_1(Data::YEAR::Y2024, Data::MONTH::M1, Data::DAY::D1);
}

void test04() {
	Data a, b, c;

	//(a * b) = c; //û���ҵ��ܺõķ���ȥ��ֹ������Ϊ��
}

void test01(){
	std::shared_ptr<Data> p = std::shared_ptr<Data>(new Data(), customDeleter);
}