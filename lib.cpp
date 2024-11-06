#include <iostream>

typedef struct {
	char author[50];	// автор
	char title[100];	// заголовок
	short year;		    // год издания
} BOOK;

struct Node {
public:
	BOOK data;
	Node* next;

public:
	Node(BOOK data) {
		this->data = data;
		this->next = NULL;
	}
};

struct OneLinkedList {
public:
	Node* head, * tail;

public:
	OneLinkedList() {
		this->head = this->tail = NULL;
	}

	~OneLinkedList() {
		while (head != NULL) pop_front();
	}

	void pop_front() {
		if (head == NULL) return;
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}

		Node* node = head;
		head = node->next;
		delete node;
	}

	void push_back(BOOK data) {
		Node* node = new Node(data);
		if (head == NULL) head = node;
		if (tail != NULL) tail->next = node;
		tail = node;
	}

	void push_front(BOOK data) {
		Node* node = new Node(data);
		node->next = head;
		head = node;
		if (tail == NULL) tail = node;
	}

	void pop_back() {
		if (tail == NULL) return;
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}

		Node* node = head;
		for (; node->next != tail; node = node->next);

		node->next = NULL;
		delete tail;
		tail = node;
	}

	Node* getAt(int k) {
		if (k < 0) return NULL;

		Node* node = head;
		int n = 0;
		while (node && n != k && node->next) {
			node = node->next;
			n++;
		}

		return (n == k) ? node : NULL;
	}

	void insert(int k, BOOK data) {
		Node* left = getAt(k);
		if (left == NULL) return;

		Node* right = left->next;
		Node* node = new Node(data);

		left->next = node;
		node->next = right;
		if (right == NULL) tail = node;
	}

	void erase(int k) {
		if (k < 0) return;
		if (k == 0) {
			pop_front();
			return;
		}

		Node* left = getAt(k - 1);
		Node* node = left->next;
		if (node == NULL) return;

		Node* right = node->next;
		left->next = right;
		if (node == tail) tail = left;
		delete node;
	}
};

int main(void)
{
    using namespace std;     
    OneLinkedList lib;
    int i = 0;    
    BOOK books[10]{
        {"Пушкин А.С.", "Пиковая дама", 2007},
        {"Тургенев И.С.", "Муму", 2011},
        {"Толстой А.Н.", "Аэлита", 1995},
        {"Балакирев С.М.", "Моя жизнь, мои достижения", 2045}
    };
    if(books+5 != nullptr)
        std::cout << sizeof(books+10) << '\n';

    for(int i = 0; i < 4; i++)
        lib.push_back(books[i]);

    for (Node* node = lib.head; node != NULL; node = node->next) {
		std::cout << node->data.author << " ";
	}
    
    return 0;
}
