
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
    LinkNode* left = head, *right = head->next;
    left->next = NULL;
    while(right != NULL) {
        LinkNode* temp = right;
        right = right->next;
        temp->next = left;
        left = temp;
    }
    return left;
}

int main() {
    
    return 0;
}

