#include <iostream>
#include <fstream>
#include <functional>
//�����������
//1) �������� ������� ������
//2) �������� �� �������
//3) ���������� ��������� (� ������(� ������)), � �����
//4) �������� �������� �� ������ (���� ��� ��������)
//��������
//1) �� �������� �����
//2) �� �������� �������
//3) ������������
//��������� ������ �� ������� ������� ������
//����������� ������(����������)

using Tinfo = int;
struct NODE
{
	Tinfo info;
	NODE* next;
	NODE(Tinfo info, NODE * ptr= nullptr): info(info),next(ptr) {};
	~NODE() { next = nullptr; };
};

using ptrNode = NODE*;

void init(ptrNode& head)
{
	head = nullptr;
}
bool empty(ptrNode head)
{
	return head == nullptr;
}
//���������� �������� � ������ ������
//1) ��������� ����� ������ ��� ��������
//2) ��������� ���� ������ ����
//3) �������� ������� � ������
void add_to_head(ptrNode& head, Tinfo elem)
{
	head = new NODE(elem, head);
}
//���������� �������� ����� ���������
void add_after(ptrNode& ptr, Tinfo elem)
{
	if (ptr)
	{
		ptr->next = new NODE(elem, ptr->next);
	}
}

//��������
//1) ��������� ����� ���������� ��������
//2) ��������� ������� �� ������
//3) ���������� ������

//�������� �� ������
void del_from_head(ptrNode& head)
{
	if (head)
	{
		ptrNode p = head;
		head = head->next;//p->next
		delete p;
	}
}

//�������e � ������
void del_after(ptrNode& ptr)
{
	if (ptr&& ptr->next)
	{
		ptrNode p = ptr->next;
		ptr->next = ptr->next->next;//p->next
		delete p;
	}
}

/*�������� �� �������� �����*/ 
void create_by_stack(ptrNode& head, std::ifstream& file)
{
	Tinfo elem;
	init(head);
	while (file >> elem)
	{
		add_to_head(head, elem);
	}
}

//�������� �� �������� �������
void create_be_queue(ptrNode& head, std::ifstream& file)
{
	Tinfo elem;
	init(head);
	file >> elem;
	add_to_head(head, elem);
	ptrNode tail = head;
	while (file >> elem)
	{
		add_after(tail, elem);
		tail = tail->next;
	}
}

/*�������� ������ ������������*/ 


int main() {

	system("pause");
}