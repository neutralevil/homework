#ifndef CPP_TDD_SOUNDEX_H
#define CPP_TDD_SOUNDEX_H
#include <string>

class Soundex {
public:
    std::string encode(const std::string& word) const {
        return zeroPad(head(word) + encodedDigits(word));
    }

private:
    static const size_t MaxCodeLength = 4;

    std::string head(const std::string& word) const {
        return word.substr(0, 1);
    }

    std::string encodedDigits(const std::string& word) const {
        if (word.length() > 1)
            return "1";
        return "";
    }

    std::string zeroPad(const std::string& word) const {
        auto zeroNeeded = MaxCodeLength - word.length();
        return word + std::string(zeroNeeded, '0');
    }
};

#endif //CPP_TDD_SOUNDEX_H
