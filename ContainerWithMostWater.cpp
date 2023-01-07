class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
    // This code Time Limit Exceeded
    int maxArea(vector<int>& height) {
        int maxarea = INT32_MIN;
        for(int i = 0; i < height.size(); i++){
            for(int j = i + 1; j < height.size(); j++)
                maxarea = max(maxarea, min(height[i], height[j]) * (j - i));
        }
        return maxarea;
    }
};
