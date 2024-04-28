#pragma once
class renderIf
{
public:
	virtual void render() = 0;

	static renderIf* create(const char* name);
};

