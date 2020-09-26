#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x),next(nullptr){}   // ���캯�������� 
};

// ��ԭʼ���жϷ�ʽ��n�Ķ���ռ临�Ӷ�
bool isPalindrome1(ListNode* head) {
	stack<int> myStock;
	ListNode* curNode = head;
	// �Ƚ���������ڶ�ջ��
	while (curNode != nullptr) {
		myStock.push(curNode->val);
		curNode = curNode->next;
	}
	//Ȼ���ٴ�ͷ�������������ҺͶ�ջTop�����ֱȽ�
	curNode = head;
	while (curNode) {
		if (curNode->val != myStock.top())
			return false;
		else {
			curNode = curNode->next;
			myStock.pop();
		}
	}
	return true;
}

// ʹ��һ��Ķ���ռ�Ĳ���
bool isPalindrome2(ListNode* head) {
	if (head == nullptr || head->next == nullptr)  // �պ�ֻ��һ��Ԫ�ػ���û��Ԫ��ʱ����Ȼ�ǻ�������
		return true;
	ListNode* fast_p = head->next;    // ����ָ��ĳ�ʼֵ����н���
	ListNode* slow_p = head;
	stack<int> myStack;
	while (fast_p->next != nullptr && fast_p->next->next != nullptr) {
		fast_p = fast_p->next->next;
		slow_p = slow_p->next;
	}
	while (slow_p != nullptr) {
		myStack.push(slow_p->val);
		slow_p = slow_p->next;
	}
	ListNode* curNode = head;
	while (!myStack.empty()) {
		if (curNode->val != myStack.top())
			return false;
		else {
			curNode = curNode->next;
			myStack.pop();
		}
	}
	return true;
}

//  ʹ��O(1)�Ķ���ռ�
bool isPalindrome3(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return true;
	ListNode* fNode = head;
	ListNode* sNode = head;
	while (fNode->next != nullptr && fNode->next->next != nullptr) {
		fNode = fNode->next->next;
		sNode = sNode->next;
	}
	ListNode* p1 = sNode, * p2 = sNode->next;
	ListNode* p3 = nullptr;
	p1->next = nullptr;
	while (p2 != nullptr) {
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	p3 = p1;  // p1���ұ����е����һ��Ԫ��, ��P3����һ�֣����㸴ԭ
	p2 = head;
	while (p2 != nullptr&&p1!=nullptr) {       // ż����Ԫ��ʱ����Ҫ�ж�һ��
		if (p2->val != p1->val)
			return false;
		else {
			p2 = p2->next;
			p1 = p1->next;
		}
	}
	p1 = p3->next;	// �����ȱ���ͷָ���next���ٽ�ͷָ�����һ��ָ����ΪNULL
	p3->next = nullptr;
	while (p1 != nullptr) {
		p2 = p1->next;
		p1->next = p3;
		p3 = p1;
		p1 = p2;
	}
	return true;
}
int main() {
	int InputNum(0);
	cin >> InputNum;
	//  shared_ptr<ListNode> head = make_shared<ListNode>(InputNum);
	ListNode* head = new ListNode(InputNum);
	ListNode* cur = head;
	while (cin >> InputNum) {
		if (InputNum == -1)
			break;
		else {
			ListNode* nextNode = new ListNode(InputNum);
			cur->next = nextNode;
			cur = cur->next;
		}
	}
	// ��������ֵ
	cur = head;
	while (cur) {
		cout << cur->val<<" ";
		cur = cur->next;
	}
	cout << endl;
	bool res1= isPalindrome1(head);
	bool res2 = isPalindrome2(head);
	bool res3 = isPalindrome3(head);
	cout << "res1  " << (res1 > 0 ? "True" : "False") << endl;
	cout << "res2  " << (res2 > 0 ? "True" : "False") << endl;
	cout << "res3  " << (res3 > 0 ? "True" : "False") << endl;
	//  �����һ��
	cur = head;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	return 0;
}