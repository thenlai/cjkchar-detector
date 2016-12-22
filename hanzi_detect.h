#ifndef _HANZI_DETECT_H
#define _HANZI_DETECT_H

namespace cjkdetect {

static unsigned HANZI_FIRST = 0x4E00;
static unsigned HANZI_LAST = 0x9FA5;

bool isHanzi(const unsigned &scalar);

}

#endif