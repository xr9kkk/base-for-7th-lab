#include <iostream>
#include <fstream>
#include <functional>
//инициализая
//1) создание пустого списка
//2) проверка на пустоту
//3) добавление элементов (в голову(в начало)), в хвост
//4) удаление элемента из списка (тоже два варианта)
//создание
//1) по принципу стека
//2) по принципу очереди
//3) упорядоченно
//обработка списка на примере функции печати
//уничтожение списка(деструктор)

using Tinfo = int;
struct NODE
{
	Tinfo info;
	NODE* next;
	NODE(Tinfo info, NODE * ptr= nullptr): info(info),next(ptr) {};
	~NODE() { next = nullptr; };
};

using ptrNode = NODE*;

struct Flist {
private:
	ptrNode head, tail;
	size_t size;
	void adding_by_pointer(ptrNode& ptr, Tinfo elem)
	{
		ptr = new NODE(elem, ptr);
		++size;
	}
	void del_by_pointer(ptrNode& ptr, Tinfo elem)
	{
		ptrNode p = ptr;
		ptr = p->next;
		delete p; 
		--size;
	}
public:
	Flist()
	{
		tail = head = new NODE(0);
		size = 0;
	}
	~Flist();
	ptrNode get_head();
	ptrNode get_tail();
	void set_tail(ptrNode ptr);
	Tinfo get_elem(ptrNode ptr);
	size_t get_size();
	bool empty();
	void add_to_head(Tinfo elem);
	void add_to_tail(Tinfo elem);
	void add_after(ptrNode ptr, Tinfo elem);
	void del_from_head();
	void del_after(ptrNode ptr);
	void create_by_queue(std::ifstream& file);
	void print(const char* message, std::ostream& stream = std::cout);
	void sorting();
};




int main()
{
	
	std::ifstream file("data.txt");
	if (file) {
		
	}

	std::cin.get();
	return 0;
}