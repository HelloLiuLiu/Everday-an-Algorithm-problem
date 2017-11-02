#include<iostream>
#include<cstdlib>

//给定俩个有序单链表，打印出两个链表的公共部分。
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}LinkList;
void Init(LinkList* head)
{//初始化一个单链表
	head->data = 0;
	head->next = NULL;
}
void Creat(LinkList* head,int n)
{//创建一个n个元素的单链表------带头节点
	/*
	参数：需要创建的单链表的头节点
		  元素个数
	*/
	LinkList* p = head;
	int num;
	for (int i = 0; i < n; ++i)
	{
		LinkList* new_node = (LinkList*)malloc(sizeof(LinkList));//动态分配内存，申请一个节点
		if (!new_node)//若分配失败
			exit(0);
		cin >> num;
		new_node->data = num;
		new_node->next = NULL;
		p->next = new_node;
		p = p->next;
	}
}
void printCommonItem(LinkList*head1, LinkList*head2)
{
	//打印两个有序单链表的公共部分
	LinkList* p, *q;
	p = head1->next;
	q = head2->next;
	while (p&&q)
	{
		if (p->data < q->data)
			p = p->next;
		else if (p->data>q->data)
			q = q->next;
		else
		{
			cout << p->data << " ";
			p=p->next;
			q=q->next;
		}
	}
}
int main()
{
	LinkList a, b;
	Init(&a);
	Init(&b);
	int n, m;
	cin >> n >> m;
	Creat(&a, n);
	Creat(&b, m);
	printCommonItem(&a, &b);
	cout << endl;
	return 0;
}
