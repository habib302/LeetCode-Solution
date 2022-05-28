class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size(), n=grid[0].size(),fresh=0,rotten=0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        
        if(fresh==0) return 0;
        
        vector<pair<int,int>> dirs{{0,1} ,{0,-1}, {1,0}, {-1,0}};
        int time=-1;
        
        while(q.size()>0){
            int qSize=q.size();
            time++;
            
            for(int i=0;i<qSize;i++){
                
                int row=q.front().first;
                int col=q.front().second;
                
                q.pop();
                
                for(auto d: dirs){
                    int r = row + d.first;
                    int c = col + d.second;
                    
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1){
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--;
                    }
                }
            }
        }
        
        return (fresh==0) ? time : -1;
    }
};