#ifndef CPP_TDD_SOUNDEX_H
#define CPP_TDD_SOUNDEX_H
#include <string>

class Soundex {
public:
    std::string encode(const std::string& word) const {
        return zeroPad(word);
    }

private:
    std::string zeroPad(const std::string& word) const {
        return word + "000";
    }
};

#endif //CPP_TDD_SOUNDEX_H
