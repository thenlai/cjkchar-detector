#include "char_detect.h"

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
        } else if(isKatakana(*utf16it) || isHiragana(*utf16it)) {
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

/*
Block                                   Range       Comment
CJK Unified Ideographs                  4E00-9FFF   Common
CJK Unified Ideographs Extension A      3400-4DBF   Rare
CJK Unified Ideographs Extension B      20000-2A6DF Rare, historic
CJK Unified Ideographs Extension C      2A700–2B73F Rare, historic
CJK Unified Ideographs Extension D      2B740–2B81F Uncommon, some in current use
CJK Unified Ideographs Extension E      2B820–2CEAF Rare, historic
CJK Compatibility Ideographs            F900-FAFF   Duplicates, unifiable variants, corporate characters
CJK Compatibility Ideographs Supplement 2F800-2FA1F Unifiable variants
*/


/*
## Unicode range of Hanzi 
*/
bool isHanzi(const unsigned &scalar) {
    return (
        scalar >= 0x4E00 && scalar <= 0x9FA5
    );
}

/*
## Unicode range of Hangul:

U+AC00–U+D7AF [Hangul Syllables](http://www.unicode.org/charts/PDF/UAC00.pdf)
U+1100–U+11FF [Hangul Jamo](http://www.unicode.org/charts/PDF/U1100.pdf)
U+3130–U+318F [Hangul Compatibility Jamo](http://www.unicode.org/charts/PDF/U3130.pdf)
U+3200–U+32FF [Enclosed CJK Letters and Months](http://www.unicode.org/charts/PDF/U3200.pdf)
U+A960–U+A97F [Hangul Jamo Extended-A](http://www.unicode.org/charts/PDF/UA960.pdf)
U+D7B0–U+D7FF [Hangul Jamo Extended-B](http://www.unicode.org/charts/PDF/UD7B0.pdf)
U+FF00–U+FFEF [Halfwidth and Fullwidth Forms](http://www.unicode.org/charts/PDF/UFF00.pdf)
*/
bool isHangul(const unsigned &scalar) {
    return (
        scalar >= 0xAC00 && scalar <= 0xD7AF
    );
}

/*
## Unicode range of Japanese Kana

### Unicode range of Katakana

U+30A0–U+30FF [Katakana](http://www.unicode.org/charts/PDF/U30A0.pdf)
U+31F0–U+31FF [Katakana Phonetic Extensions](http://www.unicode.org/charts/PDF/U31F0.pdf)

### Unicode range of Hiragana

U+3041–U+309F [Hiragana](http://www.unicode.org/charts/PDF/U30A0.pdf)
(exclusive of 0x3097 and 0x3098)

### Kana supplement

U+1B000–U+1B001 [Kana Supplement](http://www.unicode.org/charts/PDF/U1B000.pdf)
*/
bool isKatakana(const unsigned &scalar) {
    return scalar >= 0x30A0 && scalar <= 0x30FF;
}

bool isHiragana(const unsigned &scalar) {
    return scalar >= 0x3041 && scalar <= 0x309F && scalar != 0x3097 && scalar != 0x3098;
}