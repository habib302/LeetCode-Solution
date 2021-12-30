class Solution {
public:
    string multiply(string num1, string num2) {
      
      //base case
      if(num1=="0" || num2=="0") return "0";
      int n1=num1.size(),n2=num2.size(),n;
      n=n1+n2;
      
      vector<int> res(n,0);
      int val1,val2,k,carry,count=0,prod;
      
      //get val1
      for(int i=n1-1;i>=0;i--){
        k=n-1-count;
        val1=num1[i]-'0';
        carry=0;
        
        //get val2
        for(int j=n2-1;j>=0;j--){
          
          val2=num2[j]-'0';
          
          prod = (val1*val2)+carry+res[k];
          
          res[k]=prod%10;
          
          carry=prod/10;
          
          k--;
        }
        
        //check if carry>0
        if(carry>0){
          res[k]=carry+res[k];
        }
        count++;
      }
      
      int i=0;
      //remove leading zero
      for( ;i<n;i++){
        if(res[i]==0){
          continue;
        }
        else{
          break;
        }
      }
      
      string s="";
      for(int j=i;j<n;j++){
        char ch=res[j]+'0';
        s = s+ ch;
      }
      
      return s;
    }
};