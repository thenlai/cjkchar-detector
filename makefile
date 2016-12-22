## cjkchar-detector

cc = g++
cpp11 = -std=c++11
cc11 = $(cc) $(cpp11)

CJK_OBJECTS = hanzi_detect.o kana_detect.o hangul_detect.o
TARGET = test.out

$(TARGET) : test.o char_detect.o $(CJK_OBJECTS)
	$(cc) -o $(TARGET) $(CJK_OBJECTS) char_detect.o test.o

hanzi_detect.o: hanzi_detect.h hanzi_detect.cpp
	$(cc) -c hanzi_detect.cpp

kana_detect.o: kana_detect.h kana_detect.cpp
	$(cc) -c kana_detect.cpp

hangul_detect.o: hangul_detect.h hangul_detect.cpp
	$(cc) -c hangul_detect.cpp

char_detect.o : char_detect.h char_detect.cpp \
	hanzi_detect.h kana_detect.h hangul_detect.h
	$(cc) -c char_detect.cpp

test.o : char_detect.h test.cpp
	$(cc) -c test.cpp

.PHONY : clean
clean:
	rm -r $(TARGET) $(CJK_OBJECTS) char_detect.o app.o