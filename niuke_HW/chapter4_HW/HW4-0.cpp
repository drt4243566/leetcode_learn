#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x),next(nullptr){}   // 构造函数很有用 
};

// 最原始的判断方式，n的额外空间复杂度
bool isPalindrome1(ListNode* head) {
	stack<int> myStock;
	ListNode* curNode = head;
	// 先将链表放置在堆栈中
	while (curNode != nullptr) {
		myStock.push(curNode->val);
		curNode = curNode->next;
	}
	//然后再从头遍历单链表，并且和堆栈Top的数字比较
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

// 使用一半的额外空间的操作
bool isPalindrome2(ListNode* head) {
	if (head == nullptr || head->next == nullptr)  // 刚好只有一个元素或者没有元素时，自然是回文序列
		return true;
	ListNode* fast_p = head->next;    // 快慢指针的初始值设计有讲究
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

//  使用O(1)的额外空间
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
	p3 = p1;  // p1是右边序列的最后一个元素, 在P3里多存一手，方便复原
	p2 = head;
	while (p2 != nullptr&&p1!=nullptr) {       // 偶数个元素时，都要判断一下
		if (p2->val != p1->val)
			return false;
		else {
			p2 = p2->next;
			p1 = p1->next;
		}
	}
	p1 = p3->next;	// 必须先保存头指针的next，再将头指针的下一个指针设为NULL
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
	// 输出链表的值
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
	//  再输出一遍
	cur = head;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	return 0;
}