#pragma once

#include "renderIf.h"

class renderByOpengl : public renderIf
{
public:
	void render() override;

private:
	int m_id;
	int m_id1;
};

