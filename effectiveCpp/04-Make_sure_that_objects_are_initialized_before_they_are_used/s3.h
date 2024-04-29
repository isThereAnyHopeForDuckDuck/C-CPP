#pragma once
class s3
{
public:
	s3();
	void run();

	static s3& get() {
		static s3 g_s3;
		return g_s3;
	}
};


