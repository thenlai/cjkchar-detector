#include <fstream>
#include <iostream>
#include <string>
#include "char_detect.h"

int main(int argc, char** argv) {
    std::string str = "hello, 성함 世界 わかり";
    cjkdetect::detect(str);

    return 0;
}