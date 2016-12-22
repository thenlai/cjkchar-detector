#include "char_detect.h"

namespace cjkdetect {

void detect(const std::string &str) {
    std::vector<unsigned short> utf16line;
    
    std::string::const_iterator end_it = utf8::find_invalid(str.begin(), str.end());
    utf8::utf8to16(str.begin(), end_it, back_inserter(utf16line));
    std::vector<unsigned short>::iterator utf16it = utf16line.begin();

    unsigned int en = 0, zh = 0, jp = 0, kr = 0;
    for (; utf16it != utf16line.end(); utf16it++) {
        // std::cout << *utf16it << " / ";
        if (isUpperLatin(*utf16it) || isLowerLatin(*utf16it)) {
            en ++;
        } else if(isHangul(*utf16it)) {
            kr ++;
        } else if(isKana(*utf16it)) {
            jp ++;
        } else if(isHanzi(*utf16it)) {
            zh ++;
        }
    }

    std::cout
    << en << " english letters and "
    << kr << " hanguls and "
    << jp << " kanas and "
    << zh << " chinese characters."
    << std::endl;
}

bool isUpperLatin(const unsigned &scalar) {
    return scalar >= 65 && scalar <= 90;
}

bool isLowerLatin(const unsigned &scalar) {
    return scalar >= 92 && scalar <= 122;
}

}