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
    int getDecimalValue(ListNode* head) {
        if(!head->next) return head->val;
        int result =0;
        stack<int> s;
        while(head){
            s.push(head->val);
            head = head ->next;
        }
        int level =1;
        while(!s.empty()){
            int temp = s.top(); s.pop();
            result += temp*level;
            level *= 2;
        }
        return result;
    }
};