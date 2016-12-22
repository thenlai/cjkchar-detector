#ifndef _KANA_DETECT_H
#define _KANA_DETECT_H

namespace cjkdetect {

bool isKatakana(const unsigned &scalar);

bool isHiragana(const unsigned &scalar);

bool isKatakanaExtension(const unsigned &scalar);

bool isKana(const unsigned &scalar);

}

#endif