
#include <vector>
#include <iostream>
using namespace std;

//实现自定义单链表
template<class T>
struct Node{
    T data;
    Node<T>* next;
    Node(const T& item){

    }
};


template<class T>
class LinkList{
    Node<T>* head;
    Node<T>* tail;
    LinkList(){
        
    }
};




int main() {
    
    return 0;
}

