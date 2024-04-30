#include <memory>

/*
	1. 使用对象管理资源 即RAII 借助析构释放资源 shared_ptr lock_guard
	2. 如何定义 RAII 对象的COPY行为。   引用计数 或者 禁止copy
	3. 对原始资源的访问，该隐式转换，还是 像 shared_ptr一样提供get函数。  我倾向于显示。
	4. new delete, new[] delete[] 成对使用
	5. test的实参中，throwFunc ，new int，std::shared_ptr<int>（）,可能会乱序成：
		new int
		throwFunc
		std::shared_ptr<int>（）
		假如 throwFunc 抛出异常，那么 new int 就泄露了。
		建议的写法是：
			auto p = std::shared_ptr<int>(new int);
			test(p, throwFunc());

		此条不好呈现，不同编译器处理也不同，或许现在的编译器已经优化了呢。
		不过编译器种类众多，不同编译器版本众多。也可能就有那种傻的编译器。
		这么写，总归是保险的。
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