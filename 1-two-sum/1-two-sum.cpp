class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<int> answer;
        
        for(int i=0; i<nums.size(); i++)
        {
            int num = target - nums[i];
            for(int j=0; j<nums.size(); j++)
                if(num ==  nums[j] && i != j)
                {
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
        }
        return {};
    }
};