class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> matrix(n,vector<int> (n));
        
        int left,right,top,bottom,dir=1,p=1;
        left=0,right=n-1,top=0,bottom=n-1;
        
        
        while(left<=right && top<=bottom){
            
            //left -> right
            if(dir==1){
                for(int i=left;i<=right;i++){
                    matrix[top][i]=p;
                    p++;
                }
                
                dir=2;
                top++;
            }
            
            //top ->bottom
            else if(dir==2){
                for(int i=top;i<=bottom;i++){
                    matrix[i][right]=p;
                    p++;
                }
                
                dir=3;
                right--;
            }
            
            //right -> left
            else if(dir==3){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i]=p;
                    p++;
                }
                
                dir=4;
                bottom--;
            }
            
            //bottom -> top
            else if(dir==4){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left]=p;
                    p++;
                }
                
                dir=1;
                left++;
            }
        }
        
        return matrix;
    }
};