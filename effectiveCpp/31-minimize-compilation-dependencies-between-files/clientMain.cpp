
#include "demux.h"
#include "decode.h"
#include "stdOtherModel.h"
#include "renderIf.h"

/*
	1. 修改类的定义，那么依赖这个类的其他类，都要重新编译。
		main 依赖 decode 依赖 otherModel
		如果修改 otherModel.h 中 otherModel类的设计，那么
			1>clientMain.cpp
			1>decode.cpp
			1>otherModel.cpp
		都需要重新编译。

	2. 不依赖otherModel 的定义式，只做一个前置声明, 使用指针维护
		main 依赖 demux 用指针维护 otherModel
		如果修改 otherModel.h 中 otherModel类的设计，那么
			demux.cpp
		不需要重新编译。

	3. demux和otherModel的这种组合形式,demux是没法调用otherModel中的函数的，因为没有声明。 
		如果不调用otherModel中的函数，那么demux维护otherModel的指针干嘛

		effective 给出的方案之一：
			对于类 stdOtherModel
			stdOtherModel.h中，只做声明式。 并前置声明stdOtherModelImpl。 维护一个stdOtherModelImpl指针 m_Impl。
			stdOtherModel.cpp 中，所以函数都调用 m_Impl 中的实现。
			stdOtherModelImpl.h 和 stdOtherModelImpl.cpp 负责实现 stdOtherModel。
			
			对于使用者 clientgMain.cpp ，只需要包含stdOtherModel.h, stdOtherModel类的实现发生变化，不会影响clientgMain.cpp。
			当然，如果stdOtherModel.h中的接口发生了变化，clientgMain.cpp是要重新编译的

			这种模式对sdk开发来说也有优势，因为隐藏了实现细节。

	4. 使用接口
		renderByOpengl 继承自 renderIf 
		renderByOpengl 的定义或者实现改变，都不会影响使用者clientgMain.cpp
			实现改变 只 影响renderByOpengl.cpp
			定义改变 只 影响renderByOpengl.cpp 和 renderIf.cpp ，即引入了renderByOpengl定义的文件
*/
int main() {

	demux dm;
	decode dc;
	stdOtherModel stdo;

	dm.open();
	dc.run();
	stdo.stdOtherModel_func_0();
	stdo.stdOtherModel_func_1();
	stdo.stdOtherModel_func_2();
	stdo.stdOtherModel_func_3();

	renderIf* prender = renderIf::create("xx");
	prender->render();

	return 0;
}