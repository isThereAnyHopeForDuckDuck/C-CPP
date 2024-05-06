/*

	05 ������Ĭ�����ɵĺ���
		Ĭ�Ϲ��캯�� �������캯�� ��ֵ�����
		�������⹹�캯�����Ͳ�������Ĭ�Ϲ��캯���������͸�ֵ���С�

	06 ��ʹ�õĺ�������ȷ�ܾ�
		�����͸�ֵд��private
		C11������delete

	07 ʹ��virtual ��������
		1. �ͷŻ���ָ�룬�����������������麯������ô���������������ִ�С�
		2. �����������������麯�����Ͳ�Ҫȥ�̳��������� std::string ����ȻҲ��������Դû�ͷš�
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
	allDefault ins;//Ĭ��
	allDefault ins_1;
	allDefault ins_copy(ins);//����

	ins_1 = ins_copy;//��ֵ
}

void test05_02() {
//	nobase ins;//û��Ĭ���� ���벻��
	nobase ins(1);
	nobase ins_copy(ins);//����

	ins = ins_copy;//��ֵ
}

void test07_0102() {
	nobase* pNb = new inherit_nobase;
	allDefault* pAll = new inherit_Default;

	delete pNb;
	delete pAll;
}