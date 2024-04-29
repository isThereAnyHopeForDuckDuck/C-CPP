#pragma once

class myString
{
public:
	myString();
	myString(const myString &);
	myString(const myString&&);

private:
	int m_id;
};

