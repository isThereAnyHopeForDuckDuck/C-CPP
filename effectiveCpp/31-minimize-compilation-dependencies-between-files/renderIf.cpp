#include "renderIf.h"

#include "renderByOpengl.h"

renderIf* renderIf::create(const char* name) {

	return new renderByOpengl;
}