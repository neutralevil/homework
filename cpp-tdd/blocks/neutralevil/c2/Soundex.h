#ifndef CPP_TDD_SOUNDEX_H
#define CPP_TDD_SOUNDEX_H
#include <string>
#include <unordered_map>

class Soundex {
public:
    std::string encode(const std::string& word) const {
        return zeroPad(upperFront(word) + encodedDigits(tail(word)));
    }

    std::string encodedDigit(char letter) const {
        std::unordered_map<char, std::string> encodings = {
                {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
                {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
                {'s', "2"}, {'x', "2"}, {'z', "2"},
                {'d', "3"}, {'t', "3"},
                {'l', "4"},
                {'m', "5"}, {'n', "5"},
                {'r', "6"},
        };

        auto it = encodings.find(letter);
        return (it == encodings.end()) ? "" : it->second;
    }

private:
    static const size_t MaxCodeLength = 4;

    std::string upperFront(const std::string& word) const {
        return std::string(1, std::toupper(word.front()));
    }

    std::string tail(const std::string& word) const {
        return word.substr(1);
    }

    std::string encodedDigits(const std::string& word) const {
        std::string encoding;
        for (auto letter: word) {
            if (isComplete(encoding))
                break;
            if (encodedDigit(letter) != lastDigit(encoding))
                encoding += encodedDigit(letter);
        }
        return encoding;
    }

    bool isComplete (const std::string& encoding) const {
        return encoding.length() == MaxCodeLength -1;
    }

    std::string lastDigit(const std::string& encoding) const {
        if (encoding.empty())
            return "";
        return std::string(1, encoding.back());
    }

    std::string zeroPad(const std::string& word) const {
        auto zeroNeeded = MaxCodeLength - word.length();
        return word + std::string(zeroNeeded, '0');
    }
};

#endif //CPP_TDD_SOUNDEX_H
