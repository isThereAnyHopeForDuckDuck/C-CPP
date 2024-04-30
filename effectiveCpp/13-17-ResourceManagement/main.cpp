#include <memory>

/*
	1. ʹ�ö��������Դ ��RAII ���������ͷ���Դ shared_ptr lock_guard
	2. ��ζ��� RAII �����COPY��Ϊ��   ���ü��� ���� ��ֹcopy
	3. ��ԭʼ��Դ�ķ��ʣ�����ʽת�������� �� shared_ptrһ���ṩget������  ����������ʾ��
	4. new delete, new[] delete[] �ɶ�ʹ��
	5. test��ʵ���У�throwFunc ��new int��std::shared_ptr<int>����,���ܻ�����ɣ�
		new int
		throwFunc
		std::shared_ptr<int>����
		���� throwFunc �׳��쳣����ô new int ��й¶�ˡ�
		�����д���ǣ�
			auto p = std::shared_ptr<int>(new int);
			test(p, throwFunc());

		�������ó��֣���ͬ����������Ҳ��ͬ���������ڵı������Ѿ��Ż����ء�
		���������������ڶ࣬��ͬ�������汾�ڶࡣҲ���ܾ�������ɵ�ı�������
		��ôд���ܹ��Ǳ��յġ�
*/

int throwFunc() {
	return 1;
}

int test(std::shared_ptr<int> p, int id) {
	return id;
}

int main() {
	test(std::shared_ptr<int>(new int), throwFunc());


}