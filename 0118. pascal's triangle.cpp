#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;
/*
void printPascal(int n)
{

for (int line = 1; line <= n; line++)
{
	int c = 1; // used to represent C(line, i)
	for (int i = 1; i <= line; i++)
	{
		cout<< c<<" ";
		c = c * (line-i) / i;
	}
	cout<<endl;
}
}
*/

vector<vector<int>> generate1(int numRows) {

        vector<vector<int>> result;
        if(numRows==0) return result;
        for (int i = 0; i < numRows; ++i) {
            result[i].resize(i + 1);
        }
        for(int line=1;line<=numRows;line++){
            int c=1;

            for(int i=1;i<=line;i++){
                result[line-1][i-1]=c;
                cout<<c<<"hello1 ";
                c=c*(line-i)/i;
            }
        }

    return result;
}


int main()
{
	int numRows = 5;
	//printPascal(n);
	vector<vector<int>> ans=generate1(5);
	for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
	}
	return 0;
}
