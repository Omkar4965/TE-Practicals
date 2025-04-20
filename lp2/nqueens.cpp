class Solution {
    public:
        vector<vector<string>> res;
        bool is_valid(int i, int k, unordered_set<int>&row, unordered_set<int>&col, unordered_set<int>&right, unordered_set<int>&left){
            if(row.find(i) != row.end()) return false;
            if(col.find(k) != col.end()) return false;
            if(right.find(i+k) != right.end()) return false;
            if(left.find(i-k) != left.end()) return false;
            return true;
        }
        void f(vector<string>& board, int i, unordered_set<int>&row, unordered_set<int>&col, unordered_set<int>&right, unordered_set<int>&left){
            int n = board.size();
            if(i == n){
                res.push_back(board);
                return;
            }
            for(int k=0; k<n; k++){
                if(is_valid(i,k, row, col, right, left)){
                    board[i][k] = 'Q';
                    row.insert(i);
                    col.insert(k);
                    right.insert(i+k);
                    left.insert(i-k);
                    f(board, i+1, row, col, right, left);
                    row.erase(i);
                    col.erase(k);
                    right.erase(i+k);
                    left.erase(i-k);
                    board[i][k] = '.';
                }
            }
        }
        vector<vector<string>> solveNQueens(int n) {
            string rows(n,'.');
            vector<string> board(n, rows);
            unordered_set<int>row, col, right, left;
            f(board, 0, row, col, right, left);
            return res;
        }
    };