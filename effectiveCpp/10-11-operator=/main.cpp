/*

	1. ����ֵд�� & , Ϊ��������ֵ��

	2. Ϊ���Ҹ��ư�ȫ�Ժ��쳣��ȫ����һЩŬ��
		
*/

class bitMap {};

class test {

public:

	void swap(test&) {}

	//���߱����Ҹ�ֵ��ȫ�� �� �쳣��ȫ��
	test& operator =(const test& rhs) {
		delete m_map;
		m_map = new bitMap(*rhs.m_map);

		return *this;
	}

	//�Բ��߱��쳣��ȫ��
	test& operator =(const test& rhs) {
		if (this == &rhs) return *this;

		delete m_map;
		m_map = new bitMap(*rhs.m_map);

		return *this;
	}
	//һ�����еİ汾
	test& operator =(const test& rhs) {
		bitMap* temp = m_map;

		m_map = new bitMap(*rhs.m_map);
		delete temp;

		return *this;
	}
	// ������ ʲô���쳣��ȫ�ԣ� ���ǲ���m_mapָ��Ұָ��
	// ����һ��rhs �ɹ��ͽ��� *this��temp  ����ͬʱҲ��֤�ˣ����Ҹ�ֵ�İ�ȫ�� ֻ�Ƕ���һ����������
	test& operator =(const test& rhs) {
		test temp(rhs);

		swap(temp);

		return *this;
	}

	// ���������������βδ���Ч�ʿ��ܸ��ߡ���������û��ô��ȷ��    ͬ����һ������Ҳ��������һ��д����
	test& operator =(test rhs) {

		swap(rhs);

		return *this;
	}

	bitMap* m_map;
};