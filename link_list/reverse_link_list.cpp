
#include <vector>
#include <iostream>
using namespace std;

#include "link_list.hpp"

//实现单链表的反转：1、递归版本； 2、非递归版本

ListNode* reverse_link_list_recursive(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* new_head = reverse_link_list_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}


ListNode* reverse_link_list(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* pre = head, *p = head->next;
    pre->next = NULL;
    while(p != NULL) {
        ListNode* temp = p;
        p = p->next;
        temp->next = pre;
        pre = temp;
    }
    return pre;
}

int main() {
    vector<int> a = {1,2,3,4,5};
    ListNode* head = create_link_list(a);
    traverse_link_list(head);
    
    head = reverse_link_list(head);
    traverse_link_list(head);

    head = reverse_link_list_recursive(head);
    traverse_link_list(head);

    destroy_link_list(head);

    return 0;
}

