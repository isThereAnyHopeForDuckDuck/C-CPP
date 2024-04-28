#pragma once

class otherModel;


class demux
{
public:
	void open();
	void setother(otherModel* ot);

private:
	int m_path;
	otherModel* m_o;
};

