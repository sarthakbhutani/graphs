class Solution {
public:
    // vector<vector<int>> dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int r,int c, int m, int n, vector<vector<char>>& board){
        if(board[r][c]!='O'){
            return;
        }
        
        board[r][c]='#';
        if(r-1>=0)
            dfs(r-1,c,m,n,board);
        if(r+1<m)
            dfs(r+1,c,m,n,board);
        if(c-1>=0)
            dfs(r,c-1,m,n,board);
        if(c+1<n)
            dfs(r,c+1,m,n,board);
            
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0){
            return;
        }
        int n=board[0].size();
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')
            dfs(0,i,m,n,board);
        }
        for(int i=0;i<n;i++){
            if(board[m-1][i]=='O')
            dfs(m-1,i,m,n,board);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
            dfs(i,0,m,n,board);
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O')
            dfs(i,n-1,m,n,board);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
