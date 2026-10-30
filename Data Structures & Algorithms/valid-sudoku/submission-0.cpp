class Solution {
   public:
    bool isPlaceValid(pair<int, int> lo, pair<int, int> current) {
        // row check
        if (lo.first == current.first) return false;
        // col check
        if (lo.second == current.second) return false;
        // 3x3 grid check
        if (lo.first/3==current.first/3 && lo.second/3==current.second/3) return false;

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, pair<int, int>> m;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int ele = board[i][j];
                if (ele != '.') {
                    if (m.find(ele) != m.end()) {
                        // check last occurence of ele at pos {}
                        pair<int, int> lo = m[ele];
                        if (isPlaceValid(lo, {i, j})) {
                            m[ele] = {i, j};
                        } else
                            return false;
                    } else {
                        m[ele] = {i, j};
                    }
                }
            }
        }
        return true;
    }
};
