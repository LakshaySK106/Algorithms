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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        if(head -> next == NULL and n == 1) return NULL;
        ListNode * temp = head;
        int count = 1;
        while(temp -> next != NULL){
            temp = temp -> next;
            count++;
        }
        if(count == n) return head -> next;
        ListNode * ans = head;
        int count2 = count;
        while(ans -> next != NULL){
            if(count2 == n+1){
                ans -> next = ans -> next -> next;
                break;
            }
            else {ans = ans -> next; count2--;}
        }
        return head;        
    }
};
