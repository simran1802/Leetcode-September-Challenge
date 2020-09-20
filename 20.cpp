int helper(vector<vector<int>>& grid,int i,int j,int s,int t_s){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == -1)
        return 0;
    if (grid[i][j] == 2)
        return s == t_s ? 1 : 0;
    grid[i][j] = -1;
    int paths = helper(grid,i+1,j,s+1,t_s) + helper(grid,i-1,j,s+1,t_s) + helper(grid,i,j+1,s+1,t_s) + helper(grid,i,j-1,s+1,t_s);
    grid[i][j] = 0;
    return paths;
    
}

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        auto x=0,y=0,t_steps=0;
        for(auto i=0;i<grid.size();i++){
            for(auto j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1)
                    x = i, y = j;
                if(grid[i][j] != -1)
                    ++t_steps;
                
            }
        }
        return helper(grid,x,y,1,t_steps);
        
    }
};
