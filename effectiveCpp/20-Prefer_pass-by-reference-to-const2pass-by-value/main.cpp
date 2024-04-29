#include "myWindow.h"

void displayByBasevalue(window w) {

}
/*
	1. by value 带来的拷贝开销，除了被拷贝的类，还有类中的成员类对象 如MyString
	2. 对象分割问题。    用 基类window 接 派生类myWindow , 只会调用window的拷贝构造，派生类部分丢了。
*/
int main(){
	myWindow w;
	displayByBasevalue(w);
}