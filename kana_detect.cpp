#include "kana_detect.h"

namespace cjkdetect {

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

    bool isKatakanaExtension(const unsigned &scalar) {
        return scalar >= 0x31F0 && scalar <= 0x31FF;
    }

    bool isKana(const unsigned &scalar) {
        return isKatakana(scalar) || isHiragana(scalar) || isKatakanaExtension(scalar);
    }

}