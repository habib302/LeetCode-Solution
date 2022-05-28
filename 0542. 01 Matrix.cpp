class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m=mat.size(), n=mat[0].size();
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
                
                else{
                    mat[i][j] = -1;
                }
            }
        }
        
        int level=0;
        vector<pair<int,int>> dirs{{0,1}, {0,-1}, {1,0},{-1,0}};
        
        while(q.size()>0){
            
            int qSize=q.size();
            level++;
            
            for(int i=0;i<qSize;i++){
                
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                
                //traverse all the four directions
                for(auto dir:dirs){
                    
                    //cout<<dir.first<<" "<<dir.second<<endl;
                    
                    int r = row + dir.first;
                    int c = col + dir.second;
                    
                    //cout<<r<<" "<<c<<endl;
                    
                    //first check it is valid cell or not
                    if(r>=0 && r<m && c>=0 && c<n && mat[r][c]==-1){
                        mat[r][c]=level;
                        q.push({r,c});
                    }
                    
                }
            }
        }
        
        return mat;
    }
};