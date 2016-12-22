#ifndef _CHAR_DETECT_H
#define _CHAR_DETECT_H

#include <iostream>
#include <string>
#include <vector>
#include "utf8-cpp/utf8.h"

#include "hanzi_detect.h"
#include "kana_detect.h"
#include "hangul_detect.h"

namespace cjkdetect {

void detect(const std::string &str);

bool isUpperLatin(const unsigned &scalar);

bool isLowerLatin(const unsigned &scalar);


}

#endif