#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class edge;

class node{
public:
    int value;
    int in;
    int out;
    vector<node*> nexts;
    vector<edge*> edges;
    node(int val){
        this->value = val;
        in = 0;
        out = 0;
    };
};

class edge{
public:
    int weight;
    node* from;
    node* to;
    edge(int w,node* f,node* t){
        weight = w;
        f = from;
        t = to;
    };
};

class graph{
public:
    unordered_map<int,node*> nodes;
    unordered_set<edge*> edges;
};

int main(){

    return 0;
}