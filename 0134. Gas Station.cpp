class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size();
        
        int totalGas=0,currGas=0,index=0;
        
        for(int i=0;i<n;i++){
            
            totalGas = totalGas + (gas[i]-cost[i]);
            currGas =  currGas +  (gas[i]-cost[i]);
            
            //if currGas less than zero, then currGas k zero kore dibo
            //and start index update korbo
            if(currGas < 0){
                currGas=0;
                index=i+1;
            }
        }
        
        return totalGas<0 ? -1 : index;
    }
};