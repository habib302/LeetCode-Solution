class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int m=image.size(), n=image[0].size();
        
        helper( image, sr, sc, newColor, image[sr][sc],m,n) ;
        
        
        return image;
    }
    
    void helper(vector<vector<int>>& image, int i, int j, int newColor,int oldColor,int m,int n){
        
        //base case
        if(i<0 || i>=m ||j<0 || j>=n || image[i][j] != oldColor || image[i][j]==newColor) return ;
        
        //color the pixel
        image[i][j]=newColor;
        
        helper( image, i+1, j, newColor, oldColor,m,n) ;
        helper( image, i-1, j, newColor, oldColor,m,n) ;
        helper( image, i, j+1, newColor, oldColor,m,n) ;
        helper( image, i, j-1, newColor, oldColor,m,n) ;
    }
};