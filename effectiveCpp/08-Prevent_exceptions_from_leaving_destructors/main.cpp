


/*
	不在析构函数中抛出异常

	1. 一般析构函数，是离开作用域调用，程序不会去捕捉异常。 
	2. 用断开连接这个功能举例，假设断开连接可能会抛出异常，那么最好提供一个public函数，给用户处理

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