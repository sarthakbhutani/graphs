class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        if(!n)
            return 0;
        int m=grid[0].size();
        int sz,count=0;
        sz=n>m?n:m;
        vector<int> row(sz,0),col(sz,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    count++;
                    row[i]++;
                }
            }
        } 
        
        //col fil,m
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[j][i]){
                    col[i]++;
                }
            }
        }
        
        //ans
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    if(row[i]*col[j]==1)
                    count--;
                }
            }
        }
        return count;
    }
};
