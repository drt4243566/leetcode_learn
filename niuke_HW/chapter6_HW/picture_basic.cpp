#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;
// 边类型
class edge
{
public:
    int weight;
    ListNode *from;
    ListNode *to;
    edge() {}
    edge(int w, ListNode *f, ListNode *t) : weight(w), from(f), to(t) {}
};
// 节点类型
class ListNode
{
public:
    int val;
    int in;
    int out;
    vector<ListNode *> nexts;
    vector<edge *> edges;
    ListNode() {}
    ListNode(int value) : val(value) {}
};
// 图类型包括所有的点和边
class Graph
{
public:
    unordered_map<int, ListNode *> nodes;
    unordered_set<edge *> edges;
};

Graph createGraph(int inputMatrix[][3], size_t inputSize)
{
    Graph graph;
    for (size_t i = 0; i != inputSize; i++)
    {
        int weight = inputMatrix[i][0];
        int from = inputMatrix[i][1];
        int to = inputMatrix[i][2];
        // 首先在图中建立对应的节点
        if (graph.nodes.count(from) != 0)
        {
            graph.nodes[from] = new ListNode(from);
        }
        if (graph.nodes.count(to) != 0)
        {
            graph.nodes[to] = new ListNode(to);
        }
        // 建立节点和边
        ListNode *fromNode = graph.nodes[from];
        ListNode *toNode = graph.nodes[to];
        edge *newEdge = new edge(weight, fromNode, toNode);
        // 调整from和to节点的属性
        fromNode->out++;
        toNode->in++;
        fromNode->nexts.push_back(toNode);
        fromNode->edges.push_back(newEdge);
        graph.edges.insert(newEdge);
    }
    return graph;
}

// BFS 宽度优先遍历算法
void BFS(ListNode *node)
{
    if (node == NULL)
    {
        return;
    }
    queue<ListNode *> q;
    unordered_set<ListNode *> set;
    q.push(node);
    set.insert(node);
    while (!q.empty())
    {
        ListNode *cur = q.front();
        q.pop();
        printf("%d ", cur->val);
        for (ListNode *i : cur->nexts)
        {
            if (set.find(i) != set.end())
            {
                set.insert(i);
                q.push(i);
            }
        }
    }
}

// DFS 深度优先遍历算法
void DFS(ListNode *node)
{
    if (node == NULL)
    {
        return;
    }
    stack<ListNode *> stk;
    unordered_set<ListNode *> set;
    stk.push(node);
    set.insert(node);
    printf("%d ", node->val);
    while (!stk.empty())
    {
        ListNode *cur = stk.top();
        stk.pop();
        for (auto next : cur->nexts)
        {
            if (set.find(next) != set.end())
            {
                stk.push(cur);
                stk.push(next);
                set.insert(next);
                printf("%d ", next->val);
                break;
            }
        }
    }
}

int main()
{
    int InputMatrix[][3] = {{1, 1, 2}, {1, 1, 3}, {2, 1, 4}, {1, 3, 4}};
    size_t inputSize = sizeof(InputMatrix) / sizeof(InputMatrix[0]);
    Graph g = createGraph(InputMatrix, inputSize);
    return 0;
}