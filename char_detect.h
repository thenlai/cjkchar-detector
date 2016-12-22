#ifndef _CHAR_DETECT_H
#define _CHAR_DETECT_H

#include <iostream>
#include <string>
#include <vector>
#include "utf8-cpp/utf8.h"

static unsigned HANZI_FIRST = 0x4E00;
static unsigned HANZI_LAST = 0x9FA5;

void detect(const std::string &str);

bool isUpperLatin(const unsigned &scalar);

bool isLowerLatin(const unsigned &scalar);

bool isHanzi(const unsigned &scalar);

bool isHangul(const unsigned &scalar);

bool isKatakana(const unsigned &scalar);

bool isHiragana(const unsigned &scalar);

#endif