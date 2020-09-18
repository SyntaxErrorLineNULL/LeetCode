#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Max Consecutive Ones
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int Count = 0;
        int Max = 0;

        for(auto &i : nums){
            if(i == 1){
                Count++;
            } else {
                if(Count > Max) Max = Count;
                if(Max >= nums.size() / 2) return Max;
                Count = 0;
            }
        }
        return max(Max, Count);
    }

    // Find Numbers with Even Number of Digits
    int findNumbers(vector<int>& nums) {
        return accumulate(begin(nums), end(nums), 0, [] (auto &s, auto &n) {
            return s + 1 - to_string(n).size() % 2;
        });

        /*
         * return count_if(begin(nums), end(nums), [](auto &num) {
            return to_string(num).size() % 2 == 0;
        });
         */
    }

    // Squares of a Sorted Array
    vector<int> sortedSquares(vector<int>& A) {
        for(auto i = 0; i != A.size(); i++) A[i] = A[i] * A[i];
        sort(A.begin(), A.end());
        return A;
    }

    // Duplicate Zeros
    void duplicateZeros(vector<int>& arr) {
        int count = 0, n = arr.size();
        for(int i: arr)
            if(i == 0)
                ++count;
        for(int i = n - 1, j = n - 1 + count; i >= 0; --i, --j){
            if(j < n)
                arr[j] = arr[i];
            if(arr[i] == 0 && --j < n)
                arr[j] = 0;
        }
    }

    // Merge Sorted Array
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        nums1.erase(remove(nums1.begin(), nums1.end(), 0), nums1.end());
        std::sort(nums1.begin(), nums1.end());*/

        int size = nums1.size();
        for(int i = 1; i <= m; ++i){
            nums1[size - i] = nums1[m - i];
        }
        int k = 0, i = size - m, j = 0;
        for(int k = 0; k < m + n; ++k){
            int a = i < size ? nums1[i] : INT_MAX;
            int b = j < n ? nums2[j] : INT_MAX;
            if(a < b){
                nums1[k] = a;
                ++i;
            }else{
                nums1[k] = b;
                ++j;
            }
        }
    }

    // Remove Element
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        auto tmp = 0;
        for(auto i = 0; i < nums.size(); i++){
            if(nums[i] != val) nums[tmp++] = nums[i];
        }
        return tmp;

        /*
         * return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));
         */
    }

    int digital_root(int n){
        int sum = 0;
        int i = 10;
        while (n + 10 > i){
            sum += n % i;
            n /= i;
        }
        return (sum == sum % 10) ? sum : digital_root(sum);
    }

    // Remove Duplicates from Sorted Array
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();

        /*
         *  if(nums.empty()) return 0;
            int i = 0, j = 0;
            while(++j < nums.size()){
                if(nums[j] != nums[i])
                   nums[++i] = nums[j];
            }
            return i+1;
         */
    }

    // Check If N and Its Double Exist
    bool checkIfExist(vector<int>& arr) {

        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr.size(); j++){
                if(i != j)
                    if(arr[i] == arr[j] * 2) return true;
            }
        }
        return false;

        /*const int N = arr.size();
        unordered_set<int> visited{arr.back()};
        for (int i = N - 2; i >= 0; --i) {
            if (visited.count(arr[i] * 2)) return true;
            if (arr[i] % 2 == 0 && visited.count(arr[i] / 2)) return true;
            visited.insert(arr[i]);
        }
        return false;*/
    }

    // Valid Mountain Array
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3) return false;

        int MaxElement = max_element(A.begin(), A.end()) - A.begin();
        if(MaxElement == A.size()-1 || MaxElement == 0) return false;

        for(int i = 0; i < MaxElement; i++)
            if(A[i] >= A[i+1]) return false;

        for(int i = MaxElement; i < A.size()-1; i++)
            if(A[i] <= A[i+1]) return false;

        return true;
    }

    // Replace Elements with Greatest Element on Right Side
    vector<int> replaceElements(vector<int>& arr) {

    }

    // Move Zeroes
    void moveZeroes(vector<int>& nums) {

    }

    // Sort Array By Parity
    vector<int> sortArrayByParity(vector<int>& A) {

    }

    std::vector<std::string> dup(std::vector<std::string> arr){
        for(auto &s : arr){
            s.erase(std::unique(s.begin(), s.end()), s.end());
        }
        return arr;
    }


};

int main() {
    Solution Solution;

    vector<int> Test = {1,1,1,1,1,1,1,0,1,1,1};
    vector<int> TestTwo = {555,901,482,1771};
    vector<int> TestThree = {-7,-3,2,3,11};
    std::cout << Solution.findMaxConsecutiveOnes(Test) << std::endl;
    Solution.sortedSquares(TestThree);

    return 0;
}