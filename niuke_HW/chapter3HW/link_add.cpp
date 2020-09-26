#include<iostream>
using namespace std;
struct Node
{
    int  data;
    Node* next;
};
Node* Phead = NULL;//一开始没有节点 先设定一个空节点作为头节点 此头节点 数据data=NULL，next=NULL;

void Addhead(int d)//头插法
{
    Node* p = (Node*)(malloc(sizeof(Node)));
    p->data = d;
    p->next = Phead;//{ 将现有头的NULL赋值给该新申请的next,使之为空即使该数据成为尾结点（仅仅对插入的第一个数而言）}，但而后插入的数据的next指向上一个数据，因为Phead值不再为NULL这也是一不小心最不容易理解的地方
    Phead = p;//将现申请的空间赋给头节点；使之下一次访问头结点从该数据开始，形成链表，即使该节点成为头结点
}
void Addtail(int d)//尾插入
{
    Node* p = Phead;
    while (p->next != NULL)//寻找尾结点（尾结点的特点是next=NULL）
    {
        p = p->next;
    }
    Node* pnew = (Node*)(malloc(sizeof(Node)));//为新数据申请空间
    pnew->data = d;
    pnew->next = NULL;//使新数据成为尾结点
    p->next = pnew;//使上一个数据的next指向新数据 形成链表
}
void display()
{
    Node* p = Phead;
    while (p != NULL)//判断节点是否为空 不是空就打印输出
    {
        cout << p->data << "  ";
        p = p->next;
    }

}
int main()
{
    Addhead(6);
    Addhead(5);
    Addhead(4);
    display();
    Addhead(3);
    Addhead(2);
    Addhead(1);
    display();
    Addtail(7);
    Addtail(8);
    Addtail(9);
    display();
    system("pause");
    return 0;
}