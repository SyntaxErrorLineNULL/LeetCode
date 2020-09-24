#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    static double findMedianSortedArrays(std::vector<int>& ArrayOne, std::vector<int>& ArrayTwo) {
        std::vector<int> Result;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (i == nums1.size()) {
                Result.push_back(nums2[j++]);
            } else if (j==nums2.size()) {
                Result.push_back(nums1[i++]);
            } else {
                if (nums1[i] < nums2[j]) {
                    Result.push_back(nums1[i++]);
                }
                else {
                    Result.push_back(nums2[j++]);
                }
            }
        }
        if (Result.size() % 2 == 0) {
            return (Result[Result.size()/2-1] + Result[Result.size()/2]) /2.0;
        }
        return Result[Result.size()/2];
    }
};

int main() {

    std::vector<int> ArrayOne = {6, 2, 3};
    std::vector<int> ArrayTwo = {4, 5, 1};

    ArrayOne.insert(ArrayOne.end(), ArrayTwo.begin(), ArrayTwo.end());
    std::sort(ArrayOne.begin(), ArrayOne.end());

    for(auto &i : ArrayOne)
        std::cout << i << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
