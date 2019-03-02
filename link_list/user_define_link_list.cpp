
#include <vector>
#include <iostream>
using namespace std;

//实现自定义单链表
template<class T>
struct Node{
    T data;
    Node<T>* next;
    Node(T& item){
        data = item;
        next = NULL;
    }
};


template<class T>
class LinkList{
public:
    Node<T>* _head;
    Node<T>* _tail;

public:    
    LinkList(): _head(NULL), _tail(NULL) {}
    
    Node<T>* insert_node(T& data) { //插入节点
        if(_head == NULL) {
            _head = new Node<T>(data);
            _tail = _head;
            return _head;
        }
        else {
            Node<T>* temp = new Node<T>(data);
            _tail->next = temp;
            _tail = temp;
        }
    }

    Node<T>* delete_node(T& data) { //删除节点
        if(_head == NULL) {
            return _head;
        }
        if(_head->next == NULL && _head->val == data) {
            delete _head;
            _head = _tail = NULL;
            return _head;
        }

        Node<T>* pre = _head, *p = _head->next;
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
   
    void reverse_link_list(){  //反转链表
        if(_head==NULL || _head->next==NULL) {
            return _head;
        }
        Node<T>* pre=_head, *p=_head->next;
        pre->next = NULL;
        _tail = _head;
        while(p!=NULL) {
            Node<T>* temp = p;
            p=p->next;
            temp->next = pre;
            pre = temp;
        }
    }

    //=============================================
    void create_link_list(vector<int>& a) {  //创建链表
        Node<T>* _head = NULL, *_tail = NULL;
        for(int i=0; i<a.size(); ++i) {
            if(_head==NULL) {
                _head = new Node<T>(a[i]);
                _tail = _head;
            }
            else {
                Node<T>* temp = new Node<T>(a[i]);
                _tail->next = temp;
                _tail = temp;
            }
        }
        cout<<_head->data<<endl;
    }

    void destroy_link_list() { //销毁链表
        Node<T>* p = _head;
        while(p!=NULL) {
            Node<T>* temp = p;
            p=p->next;
            delete p;
        }
        _head = _tail = NULL;
    }

    void travserse_link_list() { //遍历链表
        Node<T>* p=_head;
        while(p!=NULL) {
            cout<< p->data<<", ";
            p=p->next;
        }
        cout<<endl;
    }
};

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    LinkList<int> lista;

    lista.create_link_list(a);
    cout<<lista._head->data<<endl;
    lista.travserse_link_list();

    lista.destroy_link_list();

    return 0;
}

