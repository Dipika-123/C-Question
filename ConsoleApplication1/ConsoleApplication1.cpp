#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

struct PalindromeInfo {
    std::string text;
    int index;
    int length;
};


bool isPalindrome(const std::string& str) {
    int n = str.size();
    for (int i = 0; i < n / 2; ++i) {
        if (str[i] != str[n - i - 1]) return false;
    }
    return true;
}

int main() {
    std::string input = "sqrrqabccbatudefggfedvwhijkllkjihxymnnmzpop";
    std::vector<PalindromeInfo> palindromes;
    std::unordered_set<std::string> seen;

    for (int start = 0; start < input.size(); ++start) {
        for (int end = start + 1; end <= input.size(); ++end) {
            std::string substring = input.substr(start, end - start);
            if (isPalindrome(substring) && seen.find(substring) == seen.end()) {
                palindromes.push_back({ substring, start, static_cast<int>(substring.size()) });
                seen.insert(substring);
            }
        }
    }


    std::sort(palindromes.begin(), palindromes.end(), [](const PalindromeInfo& a, const PalindromeInfo& b) {
        return a.length > b.length;
        });


    for (int i = 0; i < 3 && i < palindromes.size(); ++i) {
        std::cout << "Text: " << palindromes[i].text
            << ", Index: " << palindromes[i].index
            << ", Length: " << palindromes[i].length << std::endl;
    }

    return 0;
}