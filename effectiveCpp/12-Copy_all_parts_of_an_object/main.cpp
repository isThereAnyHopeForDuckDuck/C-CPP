
/*
	1. 处理所有成员 包括基类的成员
	2. 不要视图在copy函数中调用另一个copy函数，要提取公共部分
*/

class custom {
public:

	custom() {}
	custom(const custom & c) {
		copy(c);
	}
	custom&  operator = (const custom& c) {
		copy(c);

		return *this;
	}
private:
	//这就是 公共部分
	void copy(const custom& c) {
		m_i = c.m_i;
		m_f = c.m_f;
		m_c = c.m_c;
	}

	int m_i;
	float m_f;
	char m_c;
};

class newCustom : public custom {
public:
	newCustom() {}
	newCustom(const newCustom& c) : m_id(c.m_id), custom(c){
	
	}
	newCustom& operator = (const newCustom& c) {
		m_id = c.m_id;
		custom::operator=(c);

		return *this;
	}
private:
	int m_id;
};

int main() {

	newCustom nc;
	newCustom nc1 = nc;
	nc = nc1;
}