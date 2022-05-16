class Solution {
    vector<int> original,shuffled;
    int n;
public:
    Solution(vector<int>& nums) {
        original=nums;
        shuffled=nums;
        n=nums.size();
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        swap(shuffled[rand()%n], shuffled[rand()%n]);
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */