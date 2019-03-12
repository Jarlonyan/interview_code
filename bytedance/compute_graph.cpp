#include <queue>
#include <vector>
#include <iostream>
using namespace std;

/*
题目：给你一些神经网络的layer，求出在forward过程中，layer的先后计算顺序
*/

template<class T>
string vec2str(T& a);

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
    
    
    int bfs_solve() {
        queue<GraphNode<T>*> que;
        for(int i=0;i<_head_nodes_vec.size(); ++i){
            que.push(_head_nodes_vec[i]);
        }

        while(!que.empty()) {
            GraphNode<T>* p = que.front();
            que.pop();
            cout<< vec2str(p->_data) << endl;
            for(int i=0; i < p->_output.size(); ++i) {
                que.push(p->_output[i]);
            }
        }
    
        return 0;
    }

    //=============================================
    void destroy_graph() { //销毁图
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

    VecFloat x1 = {1, 1, 1};
    VecFloat x2 = {2, 2, 2};
    VecFloat x3 = {3, 3, 3};
    VecFloat x4 = {4, 4, 4};
    VecFloat x5 = {5, 5, 5};
    VecFloat x6 = {6, 6, 6};
    Graph<VecFloat> G;

    G.insert_node(x1, "slot1");
    G.insert_node(x2, "slot2");
    G.insert_node(x3, "layer_x3", "slot2");
    G.insert_node(x5, "layer_x5", "layer_x3");
    G.insert_node(x4, "layer_x4", "slot2");
    
    G.bfs_solve();

    return 0;
}

//====================
template<class T>
string vec2str(T& a) {
    int n = a.size();
    string res;
    for (int i = 0; i<n-1; i++) {
        res += to_string(a[i]) + ", ";
    }
    res += to_string(a[n-1]);
    return res;
}

