#include <string>
#include <map>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string& s) {
        int FirstIndex = 0, Length = 0;
        std::map<char, int> Result;
        for (int LastIndex = 0; LastIndex < s.size(); LastIndex++) {
            if (Result.find(s[LastIndex]) != Result.end()) {
                // Find the last index of s[last index(j)]
                // Update i(first index) (starting index of current letter)
                // as maximum of current letter of i and last
                // index ++
                FirstIndex = std::max(FirstIndex, Result[s[LastIndex]] + 1);
            }
            Result[s[LastIndex]] = LastIndex;
            Length = std::max(Length, LastIndex - FirstIndex + 1);
        }
        return Length;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}