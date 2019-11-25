
#include <vector>
#include <iostream>
using namespace std;

#include "link_list.hpp"

//简单版本：链表是向左对齐的，反向存储，第一位是个位

ListNode* add_two_link_list(ListNode* head1, ListNode* head2) {
    ListNode dummy(0);
    ListNode* prev = &dummy;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0) {
        int sum = (head1==NULL?0:head1->val) + (head2==NULL?0:head2->val) + carry;
        carry = sum / 10;
        prev->next = new ListNode(sum % 10);
        prev = prev->next;
        head1 = (head1 == NULL ? NULL : head1->next);
        head2 = (head2 == NULL ? NULL : head2->next);
    }
    return dummy.next;
}

int main() {
    vector<int> a = {2, 4, 3};
    vector<int> b = {5, 6, 4};
    ListNode* head1 = create_link_list(a);
    ListNode* head2 = create_link_list(b); 

    ListNode* p_ret = add_two_link_list(head1, head2);
    traverse_link_list(p_ret);

    destroy_link_list(head1);
    destroy_link_list(head2);
    destroy_link_list(p_ret);
    return 0;
}

