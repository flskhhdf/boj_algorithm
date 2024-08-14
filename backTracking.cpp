#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, const vector<int>& candidates, int target, vector<int>& cur, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(cur);
        return;
    }

    for (int j = i; j < candidates.size(); ++j) {
        if (target - candidates[j] >= 0) {
            cur.push_back(candidates[j]);
            dfs(j, candidates, target - candidates[j], cur, res);
            cur.pop_back();
        }
    }
}

int main() {
    vector<vector<int>> result;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<int> cur;
    dfs(0, candidates, target, cur, result);

    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << '\n';
    }

    return 0;
}
