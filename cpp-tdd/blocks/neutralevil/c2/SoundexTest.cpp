#include <gmock/gmock.h>

class Soundex {
public:
    std::string encode(const std::string& word) {
        return "";
    }
};

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    Soundex soundex;
    auto encoded = soundex.encode("A");
}