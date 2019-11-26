
#include <vector>
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val) {
        next = NULL;
    }
};

ListNode* create_link_list(vector<int>& a) {
    ListNode* head = NULL, *tail = NULL;
    for(int i=0; i<a.size(); ++i) {
        if(head==NULL) {
            head = new ListNode(a[i]);
            tail = head;
        }
        else {
            ListNode* temp = new ListNode(a[i]);
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

ListNode* destroy_link_list(ListNode* head) {
    ListNode* p = head;
    while(p!=NULL) {
        ListNode* temp = p;
        p=p->next;
        delete temp;
    }
    return NULL;
}

void traverse_link_list(ListNode* head) {
    if(head==NULL) return;
    ListNode* p = head;
    while(p->next!=NULL) {
        cout << p->val << ", ";
        p = p->next;
    }
    
    cout<< p->val <<endl;
}


