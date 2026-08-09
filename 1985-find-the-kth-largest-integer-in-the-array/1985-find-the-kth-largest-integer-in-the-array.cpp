class Solution {
public:
    static bool compare(string a, string b) {
        if (a.size() != b.size())
            return a.size() < b.size();

        return a < b;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), compare);
        return nums[nums.size() - k];
    }
};