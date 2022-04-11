long long int countSubarrWithEqualZeroAndOne(int arr[],int n){
	
	//Your code here
        map<int,int> map;
        map[0]=1;
        
        int count=0,sum=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                sum = sum -1;
            }
            else{
                sum = sum +1;
            }
            
            //check in map
            if(map.find(sum) != map.end()){
                count = count + map[sum];
                map[sum]++;
            }
            else{
                map[sum]=1;
            }
        }
        
        return count;
}