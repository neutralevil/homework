#include <gmock/gmock.h>

class Soundex {
public:
    std::string encode(const std::string& word) {
        return word + "000";
    }
};

using namespace testing;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    Soundex soundex;
    auto encoded = soundex.encode("A");
    ASSERT_THAT(encoded, Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    Soundex soundex;
    auto encoded = soundex.encode("I");
    ASSERT_THAT(encoded, Eq("I000"));
}
