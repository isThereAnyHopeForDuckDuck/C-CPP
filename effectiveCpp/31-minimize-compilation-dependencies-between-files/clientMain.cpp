
#include "demux.h"
#include "decode.h"
#include "stdOtherModel.h"
#include "renderIf.h"

/*
	1. �޸���Ķ��壬��ô���������������࣬��Ҫ���±��롣
		main ���� decode ���� otherModel
		����޸� otherModel.h �� otherModel�����ƣ���ô
			1>clientMain.cpp
			1>decode.cpp
			1>otherModel.cpp
		����Ҫ���±��롣

	2. ������otherModel �Ķ���ʽ��ֻ��һ��ǰ������, ʹ��ָ��ά��
		main ���� demux ��ָ��ά�� otherModel
		����޸� otherModel.h �� otherModel�����ƣ���ô
			demux.cpp
		����Ҫ���±��롣

	3. demux��otherModel�����������ʽ,demux��û������otherModel�еĺ����ģ���Ϊû�������� 
		���������otherModel�еĺ�������ôdemuxά��otherModel��ָ�����

		effective �����ķ���֮һ��
			������ stdOtherModel
			stdOtherModel.h�У�ֻ������ʽ�� ��ǰ������stdOtherModelImpl�� ά��һ��stdOtherModelImplָ�� m_Impl��
			stdOtherModel.cpp �У����Ժ��������� m_Impl �е�ʵ�֡�
			stdOtherModelImpl.h �� stdOtherModelImpl.cpp ����ʵ�� stdOtherModel��
			
			����ʹ���� clientgMain.cpp ��ֻ��Ҫ����stdOtherModel.h, stdOtherModel���ʵ�ַ����仯������Ӱ��clientgMain.cpp��
			��Ȼ�����stdOtherModel.h�еĽӿڷ����˱仯��clientgMain.cpp��Ҫ���±����

			����ģʽ��sdk������˵Ҳ�����ƣ���Ϊ������ʵ��ϸ�ڡ�

	4. ʹ�ýӿ�
		renderByOpengl �̳��� renderIf 
		renderByOpengl �Ķ������ʵ�ָı䣬������Ӱ��ʹ����clientgMain.cpp
			ʵ�ָı� ֻ Ӱ��renderByOpengl.cpp
			����ı� ֻ Ӱ��renderByOpengl.cpp �� renderIf.cpp ����������renderByOpengl������ļ�
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