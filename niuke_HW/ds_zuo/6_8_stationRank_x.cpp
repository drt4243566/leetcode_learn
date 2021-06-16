#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;
/**********图相关结构定义*************/
struct Edge;
struct Node {
	int value;
	int in;
	int out;
	vector<Node*> nexts;
	vector<Edge*> edges;
	Node(int val) {
		value = val;
		in = 0;
		out = 0;
	}
};
struct Edge {
	Node *from;
	Node *to;
	Edge(Node *f, Node *t) {
		from = f;
		to = t;
	}
};
struct Graph {
	unordered_map<int, Node*> nodes;
	unordered_set<Edge*> edges;
};

Graph* createGraphByMatrix(set<vector<int>> v) {
	/*every row [from  to  weight]*/
	Graph *graph = new Graph;
	for (auto p = v.begin();p!=v.end();p++) {
		int from = (*p)[0];
		int to = (*p)[1];
		int weight = (*p)[2];

		if (!graph->nodes.count(from)) {
			Node *temp = new Node(from);
			graph->nodes[from] = temp;
		}
		if (!graph->nodes.count(to)) {
			Node *temp = new Node(to);
			graph->nodes[to] = temp;
		}
		Node *fromNode = graph->nodes[from];
		Node *toNode = graph->nodes[to];
		Edge *newEdge = new Edge(fromNode, toNode);
		fromNode->nexts.push_back(toNode);
		fromNode->out++;
		toNode->in++;
		fromNode->edges.push_back(newEdge);
		graph->edges.insert(newEdge);
	}
	return graph;
}
int topolySort(Graph *graph) {
    int ans = 0;
	if (graph == NULL)
		return ans;
	unordered_map<Node*, int> inMap;
    unordered_set<Node*> visSet;
	queue<Node*> zeroInQueue;
    for (auto p = graph->nodes.begin(); p != graph->nodes.end();p++) {
        Node* curNode = p->second;
        inMap[curNode] = curNode->in;
        if (curNode->in == 0 and !visSet.count(curNode)) {
            zeroInQueue.push(curNode);
            visSet.insert(curNode);
        }
    }
    int flag;    
    while(1){
        flag = 0;
        while (!zeroInQueue.empty()) {
            flag = 1;
            Node* curNode = zeroInQueue.front();
            zeroInQueue.pop();
            for (int i = 0; i < curNode->nexts.size(); i++) {
                inMap[curNode->nexts[i]]--;
            }
        }
        for (auto p = graph->nodes.begin(); p != graph->nodes.end();p++) {
            Node* curNode = p->second;
            if (inMap[curNode] == 0 and !visSet.count(curNode)) {
                zeroInQueue.push(curNode);
                visSet.insert(curNode);
            }
        }
        ans++;
        if(flag==0)break;
    }
    
    return ans-1;
}
/*****************************************
 *			main.cpp
*****************************************/
int main() {
	int M,N;
    set<vector<int>> matrixSet;
    cin>>M>>N;
    for(int i=0;i<N;i++){
        int stationNum;
        int stationName;
        vector<int> stations;
        cin>>stationNum;
        for(int i=0;i<stationNum;i++){
            cin>>stationName;
            stations.push_back(stationName);
        }
        vector<int> otherstation;
        for(int i=stations[0];i<stations[stationNum-1];i++){
            if(find(stations.begin(),stations.end(),i)==stations.end()){
                otherstation.push_back(i);
            }
        }
        for(int i=0;i<otherstation.size();i++){
            for(int j=0;j<stations.size();j++){
                matrixSet.insert(vector<int>{stations[j],otherstation[i],1});
            }
        }
    }
    Graph  *graph = createGraphByMatrix(matrixSet);
    int result = topolySort(graph);
    cout<<result<<endl;
	return 0;
}