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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // This will be the final answer
        ListNode* first = nullptr;
        
        ListNode* currentNode = nullptr;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            int digit = sum % 10;
            carry = sum / 10;
        
            ListNode* value = new ListNode(digit);
            if (first == nullptr) {
                first = value;
            }
            
            if (currentNode == nullptr) {
                currentNode = value;
            } else {
                currentNode->next = value;
                currentNode = value;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode* remaining = (l1 == nullptr) ? l2 : l1;
        while (remaining != nullptr) {
            int sum = remaining->val + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            ListNode* value = new ListNode(digit);
            currentNode->next = value;
            currentNode = value;
            
            remaining = remaining->next;
        }
        
        if (carry != 0) {
            ListNode* value = new ListNode(carry);
            currentNode->next = value;
            currentNode = value;
        }
        return first;
    }
};
