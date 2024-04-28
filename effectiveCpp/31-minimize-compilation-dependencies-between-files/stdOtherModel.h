#pragma once

#include <memory>

class stdOtherModelImpl;

class stdOtherModel {
public:
	stdOtherModel();

	void stdOtherModel_func_0();
	void stdOtherModel_func_1();
	void stdOtherModel_func_2();
	void stdOtherModel_func_3();

private:
	std::shared_ptr<stdOtherModelImpl> m_Impl;
};