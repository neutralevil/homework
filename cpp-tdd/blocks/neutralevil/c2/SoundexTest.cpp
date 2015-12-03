#include <gmock/gmock.h>

class Soundex {
public:
    std::string encode(const std::string& word) {
        return word;
    }
};

using namespace testing;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    Soundex soundex;
    auto encoded = soundex.encode("A");
    ASSERT_THAT(encoded, Eq("A"));
}