
#include <vector>
#include <iostream>
using namespace std;

//实现自定义图节点
template<class T>
struct GraphNode{
    T _data;
    string _name;
    vector<GraphNode<T>*> _input;
    vector<GraphNode<T>*> _output;

    GraphNode(T& data, string name){
        _data = data;
        _name = name;
    }
};

template<class T>
class GraphList{
public:
    vector<GraphNode<T>*> _head_vec;

public:    
    GraphList(): _head(NULL), _tail(NULL) {}
    
    void insert_node(T& data, string node_name, string pre_node_name="NULL") { //插入节点
        if(_head == NULL) {
            _head = new GraphNode<T>(data);
            _tail = _head;
            return;
        }
        GraphNode<T>* pre = find_node(pre_node_name);
        GraphNode<T>* temp = new GraphNode<T>(data, node_name);
            
        if(pre==NULL) {
            _head_vec.push_back(temp);
        }
        else {
            pre->_output.push_back(temp);
        }
    }

    GraphNode<T>* find_node(string target_name) {  //查找节点
        queue<GraphNode*> que;
        
        for(int i=0;i<_head_vec.size(); ++i){}
            que.push(_head_vec[i]);
        }

        while(!que.empty()) {
            GraphNode* p = que.top();
            que.pop();
            if(p->_name == target_name){
                return p;
            }

            for(int i=0; i < p->output.size(); ++i) {
                que.push(p->output[i]);
            }
        }
        return NULL;     
    }

    vector<GraphNode*> bfs_solve() {
        vector<GraphNode*> res;

        queue<GraphNode*> que;
        que.push(first);

        while(!que.empty()) {
            GraphNode* p = que.top();
            que.pop();
            //print p
            res.push_back(p);
            for(int i=0; i < p->output.size(); ++i) {
                que.push(p->output[i]);
            }
        }
    
        return 0;
    }

    //=============================================
    void create_link_list(vector<int>& a) {  //创建链表
        Node<T>* _head = NULL, *_tail = NULL;
        for(int i=0; i<a.size(); ++i) {
            cout<<"p=" << static_cast<const void *>(_head) << endl;
            insert_node(a[i]);
        }
        cout<<"p=" << static_cast<const void *>(_head) << endl;
    }

    void destroy_link_list() { //销毁链表
        GraphNode<T>* p = _head;
        while(p!=NULL) {
            GraphNode<T>* temp = p;
            p=p->next;
            delete p;
        }
        _head = _tail = NULL;
    }

    void travserse_link_list() { //遍历链表
        GraphNode<T>* p=_head;
        while(p!=NULL) {
            //cout<< p->data << ", ";
            p=p->next;
        }
        cout<<endl;
    }
    ~LinkList() {
        destroy_link_list();
    }
};

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    GraphList<int> lista;

    lista.create_link_list(a);
    cout<<"p="<<static_cast<const void *>(lista._head)<<endl;
    //cout<<lista._head->data<<endl;
    lista.travserse_link_list();
    
    lista.reverse_link_list();
    lista.travserse_link_list();

    return 0;
}

