class Solution {
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    bool backtrack(vector<vector<char>>& board, int row, int col, int idx,
                   string word) {
        if (idx == word.length()) {
            return true;
        }

        if (row < 0 || col < 0 || row >= m || col >= n ||
            board[row][col] == '$' || board[row][col] != word[idx])
            return false;

        char ch = board[row][col];
        board[row][col] = '$';

        for (auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if (backtrack(board, newRow, newCol, idx + 1, word)) {
                return true;
            }
        }
        
        board[row][col] = ch; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == word[0] &&
                    backtrack(board, row, col, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};