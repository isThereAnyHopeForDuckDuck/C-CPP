/*

	1. 返回值写成 & , 为了连锁赋值。

	2. 为自我复制安全性和异常安全性做一些努力
		
*/

class bitMap {};

class test {

public:

	void swap(test&) {}

	//不具备自我赋值安全性 和 异常安全性
	test& operator =(const test& rhs) {
		delete m_map;
		m_map = new bitMap(*rhs.m_map);

		return *this;
	}

	//仍不具备异常安全性
	test& operator =(const test& rhs) {
		if (this == &rhs) return *this;

		delete m_map;
		m_map = new bitMap(*rhs.m_map);

		return *this;
	}
	//一个可行的版本
	test& operator =(const test& rhs) {
		bitMap* temp = m_map;

		m_map = new bitMap(*rhs.m_map);
		delete temp;

		return *this;
	}
	// 在这里 什么是异常安全性？ 就是不让m_map指向野指针
	// 拷贝一个rhs 成功就交换 *this和temp  这里同时也保证了，自我赋值的安全。 只是多了一个拷贝操作
	test& operator =(const test& rhs) {
		test temp(rhs);

		swap(temp);

		return *this;
	}

	// 拷贝操作放在了形参处，效率可能更高。但是语义没那么明确。    同作者一样，我也倾向于上一种写法。
	test& operator =(test rhs) {

		swap(rhs);

		return *this;
	}

	bitMap* m_map;
};