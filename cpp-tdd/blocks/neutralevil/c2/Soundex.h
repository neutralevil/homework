#ifndef CPP_TDD_SOUNDEX_H
#define CPP_TDD_SOUNDEX_H
#include <string>

class Soundex {
public:
    std::string encode(const std::string& word) const {
        auto encoded = word.substr(0, 1);
        if (word.length() > 1)
            encoded += "1";
        return zeroPad(encoded);
    }

private:
    std::string zeroPad(const std::string& word) const {
        auto zeroNeeded = 4 - word.length();
        return word + std::string(zeroNeeded, '0');
    }
};

#endif //CPP_TDD_SOUNDEX_H
