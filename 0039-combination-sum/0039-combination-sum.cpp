class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> currentCombination;

        function<void(int, int)> backtrack = [&](int startIndex, int remainingSum) {
            if (remainingSum == 0) {
                result.emplace_back(currentCombination);
                return;
            }

            if (remainingSum < candidates[startIndex]) {
                return;
            }

            for (int j = startIndex; j < candidates.size(); ++j) {
                currentCombination.push_back(candidates[j]);

                backtrack(j, remainingSum - candidates[j]);

                currentCombination.pop_back();
            }
        };

        backtrack(0, target);

        return result;
    }
};