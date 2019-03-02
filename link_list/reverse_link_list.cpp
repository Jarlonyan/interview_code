
#include <vector>
#include <iostream>
using namespace std;

//实现单链表的反转：1、递归版本； 2、非递归版本

struct LinkNode{
    int val;
    LinkNode* next;
    LinkNode(int val): val(val){
        next = NULL;
    }
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

//=====================================================================

LinkNode* create_link_list(vector<int>& a) {
    LinkNode* head = NULL, *tail = NULL;
    for(int i=0; i<a.size(); ++i) {
        if(head==NULL) {
            head = new LinkNode(a[i]);
            tail = head;
        }
        else {
            LinkNode* temp = new LinkNode(a[i]);
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

LinkNode* destroy_link_list(LinkNode* head) {
    LinkNode* p = head;
    while(p!=NULL) {
        LinkNode* temp = p;
        p=p->next;
        delete temp;
    }
    return NULL;
}

void traverse_link_list(LinkNode* head) {
    LinkNode* p = head;
    while(p!=NULL) {
        cout<< p->val<<", ";
        p=p->next;
    }
    cout<<endl;
}

int main() {
    vector<int> a = {1,2,3,4,5};
    LinkNode* head = create_link_list(a);
    traverse_link_list(head);
    
    head = reverse_link_list(head);
    traverse_link_list(head);

    head = reverse_link_list_recursive(head);
    traverse_link_list(head);

    destroy_link_list(head);

    return 0;
}

