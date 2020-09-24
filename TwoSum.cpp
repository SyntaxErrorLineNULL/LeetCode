#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for(auto i = 0; i < nums.size(); i++){
            for(auto j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    std::vector<int> Result {i, j};
                    return Result;
                }
            }
        }
        return std::vector<int>{0, 0};
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}