
#include <vector>
#include <iostream>
using namespace std;

#include "link_list.hpp"

//输出该链表中倒数第k个结点

ListNode* tail_kth_node(ListNode* head, int k) {
    if (k<=0 || !head) {
        return NULL;
    }
    ListNode *p1=head, *p2=head;
    while(p1->next && k!=0) {
        p1 = p1->next;
        k--;
    }

    while(p1!=NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

int main() {
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    ListNode* head = create_link_list(a);
    
    auto x = tail_kth_node(head, 9);
    if(x) {
        cout<< x->val <<endl;
    }
    else {
        cout<<"error idx"<<endl;
    }

    destroy_link_list(head);
    return 0;
}

