


/*
	���������������׳��쳣

	1. һ���������������뿪��������ã����򲻻�ȥ��׽�쳣�� 
	2. �öϿ�����������ܾ���������Ͽ����ӿ��ܻ��׳��쳣����ô����ṩһ��public���������û�����

*/

class db {
public:
	void close() {
		// ....
		m_closed = true;
	}

	~db() {
		if (!m_closed) {
		
			try {
				close();
			}
			catch (/*exception*/) {
				
			}
		}
	}
private:
	bool m_closed;
};