#include "hangul_detect.h"

namespace cjkdetect {

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

}