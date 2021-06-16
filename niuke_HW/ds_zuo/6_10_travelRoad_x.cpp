#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <climits>

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
	int weight;
	Node *from;
	Node *to;
	Edge(int w, Node *f, Node *t) {
		weight = w;
		from = f;
		to = t;
	}
};
struct Graph {
	unordered_map<int, Node*> nodes;
	unordered_set<Edge*> edges;
};

Graph* createGraphByMatrix(vector< vector<int> > v) {
	/*every row [from  to  weight]*/
	Graph *graph = new Graph;
	for (int i = 0; i < v.size(); i++) {
		int from = v[i][0];
		int to = v[i][1];
		int weight = v[i][2];

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
		Edge *newEdge = new Edge(weight, fromNode, toNode);
		fromNode->nexts.push_back(toNode);
		fromNode->out++;
		toNode->in++;
		fromNode->edges.push_back(newEdge);
		graph->edges.insert(newEdge);
	}
	return graph;
}
/**********dijkstral*************/
/**********单源最短路径算法*************/
Node* getMinDistanceAndUnselectedNode(unordered_map<Node*, int> &distanceMap, 
									  unordered_set<Node*> &selectedNodesSet){
	Node *minNode = NULL;
	int minDistance = INT_MAX;
	for(auto p=distanceMap.begin();p!=distanceMap.end();p++){
		if(!selectedNodesSet.count(p->first)&&(p->second<minDistance)){
			minNode = p->first;
			minDistance = p->second;
		}
	}
	return minNode;
}
unordered_map<Node*,int> dijkstral(Node *node){
	if(node==NULL)
		return unordered_map<Node*,int>{};
	unordered_map<Node*, int> distanceMap;
	unordered_set<Node*> selectedNodesSet;
	distanceMap[node] = 0;
	Node *minNode = getMinDistanceAndUnselectedNode(distanceMap, selectedNodesSet);
	while(minNode !=NULL){
		int distance = distanceMap[minNode];
		for(auto p=minNode->edges.begin();p!=minNode->edges.end();p++){
			Node *toNode = (*p)->to;
			if(!distanceMap.count(toNode)){
				distanceMap[toNode] = distance + (*p)->weight;
			}else{
				distanceMap[toNode] = min(distanceMap[toNode],distance+(*p)->weight);
			}
		}
		selectedNodesSet.insert(minNode);
		minNode = getMinDistanceAndUnselectedNode(distanceMap,selectedNodesSet);
	}
	return distanceMap;
}
int getMax(unordered_map<Node*,int> m){
    priority_queue<int> q;
    if(m.size()<=1)
        return -1;
    for(auto p=m.begin();p!=m.end();p++){
        q.push(p->second);
    }
    int a= q.top();
    q.pop();
    int b = q.top();
    //cout<<"a:"<<a<<"b:"<<b<<endl;
    return a+b;
}
void buildTable(vector<vector<int>> &m, int from, int to, int weight){
	m.push_back(vector<int>{from, to, weight});
	m.push_back(vector<int>{to, from, weight});
}
/*****************************************
 *			main.cpp
*****************************************/
int main() {
    int teamNum;
    cin>>teamNum;
    while(teamNum--){
        vector<vector<int> > matrix;
        priority_queue<int> q;
        int dotNum, roadNum;
        int from, to, weight;
        cin>>dotNum>>roadNum;
        for(int i=0;i<roadNum;i++){
            cin>>from>>to>>weight;
            buildTable(matrix,from,to,weight);
        }
        Graph *graph = createGraphByMatrix(matrix);
        for(int j=0;j<dotNum;j++){
            q.push(getMax(dijkstral(graph->nodes[j+1])));
        } 
        if(q.top()==1){
            cout<<-1<<endl;
        }
        else
            cout<<q.top()<<endl;
    }

	return 0;
}
