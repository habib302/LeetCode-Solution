#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int helper(vector<vector<int>> nums);

int main()
 {
    // added the two lines below for faster input
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n;
        // cin>>n;
        
        //query
        // vector<vector<int>> nums={
        //     {1,0,0,0,1},
        //     {0,0,0,0,0},
        //     {0,0,1,0,0}
        // };

        vector<vector<int>> nums={
            {1,1,0,0,1},
            {1,0,1,0,0},
            {0,0,1,0,1}
        };
        
        int ans=helper(nums);
        
        cout<<ans<<'\n';
    }
	return 0;
}

int helper(vector<vector<int>> nums){
    
    int row=nums.size(),col=nums[0].size();
    vector<int> xCord,yCord;

    //find all xCord
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
           if(nums[r][c]==1){
                xCord.push_back(r);
           }
        }
    }

    //find all yCord
    for(int c=0;c<col;c++){
        for(int r=0;r<row;r++){
           if(nums[r][c]==1){
                yCord.push_back(c);
           }
        }
    }

    int xMedian = xCord[xCord.size()/2] ;
    int yMedian = yCord[yCord.size()/2] ;

    int dist=0;
    for(int i=0;i<xCord.size();i++){
        dist += abs(xMedian-xCord[i]);
    }

    for(int i=0;i<yCord.size();i++){
        dist += abs(yMedian-yCord[i]);
    }


    return dist;
}