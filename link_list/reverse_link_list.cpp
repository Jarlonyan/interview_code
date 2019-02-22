
#include <vector>
#include <iostream>
using namespace std;

//实现单链表的反转：1、递归版本； 2、非递归版本

struct LinkNode{
    int val;
    LinkNode* next;
};

LinkNode* reverse_link_list_recursive(LinkNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    LinkNode* new_head = reverse_link_list_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}


LinkNode* reverse_link_list(LinkNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    LinkNode* pre = head, *p = head->next;
    pre->next = NULL;
    while(p != NULL) {
        LinkNode* temp = p;
        p = p->next;
        temp->next = pre;
        pre = temp;
    }
    return pre;
}

int main() {
    
    return 0;
}

