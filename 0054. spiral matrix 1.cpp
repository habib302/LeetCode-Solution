class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;
        
        //base case, if row=0
        if(matrix.size()==0) return res;
        
        int m=matrix.size(),n=matrix[0].size(),left,right,top,bottom,dir=1;
        left=0,right=n-1,top=0,bottom=m-1;
        
        
        while(left<=right && top<=bottom){
            
            //left -> right9
            if(dir==1){
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                
                dir=2;
                top++;
            }
            
            //top ->bottom
            else if(dir==2){
                for(int i=top;i<=bottom;i++){
                    res.push_back(matrix[i][right]);
                }
                
                dir=3;
                right--;
            }
            
            //right -> left
            else if(dir==3){
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                
                dir=4;
                bottom--;
            }
            
            //bottom -> top
            else if(dir==4){
                for(int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                
                dir=1;
                left++;
            }
        }
        
        return res;
    }
};