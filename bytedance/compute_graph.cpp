#include <queue>
#include <vector>
#include <iostream>
using namespace std;

/*
给你一些神经网络的layer，实现nn的forward过程
*/


//实现自定义图节点
template<class T>
struct GraphNode{
    T _data;
    string _name;
    vector<GraphNode<T>*> _output;

    GraphNode(T& data, string name){
        _data = data;
        _name = name;
    }
};

template<class T>
class Graph{
public:
    vector<GraphNode<T>*> _head_nodes_vec;

public:    
    Graph(){}
    
    void insert_node(T& data, string node_name, string pre_node_name="NULL") { //插入节点
        GraphNode<T>* pre = find_node(pre_node_name);
        GraphNode<T>* temp = new GraphNode<T>(data, node_name);
            
        if(pre==NULL) {
            _head_nodes_vec.push_back(temp);
        }
        else {
            pre->_output.push_back(temp);
        }
    }

    GraphNode<T>* find_node(string target_name) {  //查找节点
        queue<GraphNode<T>*> que;
        
        for(int i=0;i<_head_nodes_vec.size(); ++i){
            que.push(_head_nodes_vec[i]);
        }

        while(!que.empty()) {
            GraphNode<T>* p = que.front();
            que.pop();
            if(p->_name == target_name){
                return p;
            }

            for(int i=0; i < p->_output.size(); ++i) {
                que.push(p->_output[i]);
            }
        }
        return NULL;     
    }
    
    /*
    vector<GraphNode<T>*> bfs_solve() {
        vector<GraphNode<T>*> res;

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
    }*/

    //=============================================
    void destroy_graph() { //销毁链表
        queue<GraphNode<T>*> que;
        
        for(int i=0;i<_head_nodes_vec.size(); ++i){
            que.push(_head_nodes_vec[i]);
        }

        while(!que.empty()) {
            GraphNode<T>* p = que.front();
            que.pop();
            for(int i=0; i < p->_output.size(); ++i) {
                que.push(p->_output[i]);
            }
            delete p;
        }
        _head_nodes_vec.clear();
    }

    ~Graph() {
        destroy_graph();
    }
};

int main() {
    typedef vector<float> VecFloat;

    VecFloat a = {1, 2, 3, 4, 5};
    Graph<VecFloat> G;

    G.insert_node(a, "slot1");

    return 0;
}

