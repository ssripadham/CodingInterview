/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    void moveNode(struct ListNode** srcRef, struct ListNode** destRef){
        
        ListNode* tmp = *srcRef;
        *srcRef = tmp->next;
        tmp->next = *destRef;
        *destRef = tmp;
        
    }
    
    
    void push(struct ListNode** head, int data){
        ListNode* newNode = new ListNode(data);
        newNode->next = *head;
        *head = newNode;
    }
    
    struct MyCompare{
        bool operator () (pair<int, int> a, pair<int, int> b){
            return a.first > b.first;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode dummy(0);
        ListNode* output = &dummy;
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, MyCompare> pq;
        
        for (int i =0 ; i < lists.size(); ++i){
        
            if (lists[i] != NULL){
                pq.push(make_pair(lists[i]->val,i));
            }
            //put the list[i], i in a min heap
            //extract the top element and splice element in the ith list
            
        }
        
        while (!pq.empty()){
        
            pair<int,int> elem = pq.top(); pq.pop();
            
            int index = elem.second;
            
            moveNode( &lists[index], &(output->next));
            output = output->next;
            
            if (lists[index] != NULL) {
                pq.push(make_pair(lists[index]->val, index));
            }
        }
        
        return dummy.next;    
    }
};