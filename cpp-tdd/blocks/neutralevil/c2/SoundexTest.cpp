#include <gmock/gmock.h>

class Soundex {

};

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    Soundex soundex;
    auto encoded = soundex.encode("A");
}