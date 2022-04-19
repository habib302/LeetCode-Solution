/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //base case
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* curr=new ListNode(0);
        ListNode* head1=new ListNode(0);
        ListNode* temp=new ListNode(0);
        
        curr=head;
        head1=head;
        temp=head;
        
        int count=0;
        stack<int> st;
        
        while(curr!=NULL){
            
            //store the start
            if(count==0){
                temp=curr;
            }
            
            if(count<k){
                st.push(curr->val);
                count++;
                curr=curr->next;
            }
           
            if(count==k){
                
                while(st.size()>0){
                    temp->val=st.top();
                    st.pop();
                    
                    temp=temp->next;
                }
                
                count=0;
            }
        }
        
        return head1;
    }
};