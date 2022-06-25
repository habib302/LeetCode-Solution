class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        helper(sr, sc, image[sr][sc], newColor, image);
        return image;
    }
    
    void helper(int i,int j,int oldColor, int newColor, vector<vector<int>>& image){
        
        //boundary base case
        if(i<0 || i==image.size() || j<0 || j==image[0].size())
            return;
        
        if(image[i][j]==newColor || image[i][j]!=oldColor)
            return;
        
        //color the pixel
        image[i][j]=newColor;
        
        
        helper(i+1, j, oldColor, newColor, image);
        helper(i-1, j, oldColor, newColor, image);
        helper(i, j+1, oldColor, newColor, image);
        helper(i, j-1, oldColor, newColor, image);
    }
};