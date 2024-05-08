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

//������� ���������� � ������
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
void create_by_order(ptrNode& head, std::ifstream& file)
{
	Tinfo elem;
	init(head);
	auto find_place = [&head](Tinfo elem)->ptrNode
		{
			ptrNode result = head;
			while (result->next && result->next->info < elem)
			{
				result = result->next;
			}
			return result;
		};
	ptrNode ptr{};
	while (file >> elem)
	{
		if (empty(head) || head->info >= elem)
			add_to_head(head, elem);
		else
		{
			ptr = find_place(elem);
			add_after(ptr, elem);
		}
	}
}

void print(ptrNode head, const char* message)
{
	std::cout << message << '\n';
	ptrNode ptr{ head };
	while (ptr)
	{
		std::cout << ptr->info << ' ';
		ptr = ptr->next;
	}
	std::cout << '\n';
}

void clear(ptrNode& head)
{
	while (empty(head))
	{
		del_from_head(head);
	}
}

bool delete_all_even(ptrNode& head)
{
	bool result{ 0 };
	while (!empty(head) && head->info % 2 == 0)
	{
		result = true;
		del_from_head(head);
	}
	if (!empty(head))
	{
		ptrNode ptr{ head };
		while (ptr->next)
			if (ptr->next->info % 2 == 0)
			{
				result = true;
				del_after(ptr);
			}
			else
				ptr = ptr->next;

	}
	return result;
}



int main()
{
	
	std::ifstream file("data.txt");
	if (file) {
		ptrNode head{};
		create_by_stack(head, file);
		print(head, "***");
		clear(head);
		delete_all_even(head);
		print(head, "###");
		clear(head);
	}

	std::cin.get();
	return 0;
}