
#include <vector>
#include <iostream>
using namespace std;

//实现自定义单链表
template<class T>
struct Node{
    T data;
    Node<T>* next;
    Node(const T& item){
        data = item;
        next = NULL;
    }
};


template<class T>
class LinkList{
    Node<T>* head;
    Node<T>* tail;
    
    LinkList(): head(NULL), tail(NULL) {}
    
    Node<T>* insert_node(T& data) { //插入
        if(head == NULL) {
            head = new Node<T>(data);
            tail = head;
            return head;
        }
        else {
            Node<T>* temp = new Node<T>(data);
            tail->next = temp;
        }
    }

    Node* delete_node(T& data) { //删除
        if(head==NULL) {
            return head;
        }
        if(head->next == NULL && head->val == data) {
            delete head;
            head = tail = NULL;
            return head;
        }

        Node<T>* pre = head, *p = head->next;
        while(p != NULL) {
            if(p->val == data) {
                Node<T>* temp = p;
                p = p->next;  
                delete temp;
                pre->next = p;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
    }
   
    Node* reverse_link_list(){  //反转
        Node<T>* p=head;
         
    }
};




int main() {
    
    return 0;
}

