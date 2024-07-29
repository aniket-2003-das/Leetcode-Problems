class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> freq;
        
        for (int num : nums) {
            freq[num]++;
        }
        
        for (auto pair : freq) {
            if (pair.second>1) {
                result.push_back(pair.first);
            }
        }
        return result;
    }
};