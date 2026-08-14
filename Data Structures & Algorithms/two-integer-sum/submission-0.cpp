class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;

            for(int i=0; i<nums.size(); i++){
                indices[nums[i]] = i;
            }
            for(int i=0; i<nums.size(); i++){
                int j = target-nums[i];
                if(indices.count(j) && indices[j] != i){
                    return {i, indices[j]};
            }
        }
    return {};
    }
};
