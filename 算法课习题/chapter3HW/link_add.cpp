#include<iostream>
using namespace std;
struct Node
{
    int  data;
    Node* next;
};
Node* Phead = NULL;//һ��ʼû�нڵ� ���趨һ���սڵ���Ϊͷ�ڵ� ��ͷ�ڵ� ����data=NULL��next=NULL;

void Addhead(int d)//ͷ�巨
{
    Node* p = (Node*)(malloc(sizeof(Node)));
    p->data = d;
    p->next = Phead;//{ ������ͷ��NULL��ֵ�����������next,ʹ֮Ϊ�ռ�ʹ�����ݳ�Ϊβ��㣨�����Բ���ĵ�һ�������ԣ�}���������������ݵ�nextָ����һ�����ݣ���ΪPheadֵ����ΪNULL��Ҳ��һ��С����������ĵط�
    Phead = p;//��������Ŀռ丳��ͷ�ڵ㣻ʹ֮��һ�η���ͷ���Ӹ����ݿ�ʼ���γ�������ʹ�ýڵ��Ϊͷ���
}
void Addtail(int d)//β����
{
    Node* p = Phead;
    while (p->next != NULL)//Ѱ��β��㣨β�����ص���next=NULL��
    {
        p = p->next;
    }
    Node* pnew = (Node*)(malloc(sizeof(Node)));//Ϊ����������ռ�
    pnew->data = d;
    pnew->next = NULL;//ʹ�����ݳ�Ϊβ���
    p->next = pnew;//ʹ��һ�����ݵ�nextָ�������� �γ�����
}
void display()
{
    Node* p = Phead;
    while (p != NULL)//�жϽڵ��Ƿ�Ϊ�� ���ǿվʹ�ӡ���
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