#include <cstdlib>
#include <iostream>

namespace CStack {
	using namespace std;

#define MAX 10
	int size = 0;

	// Creating a stack
	struct stack {
		int items[MAX];
		int top;
	};
	typedef struct stack st;

	void createEmptyStack(st* s) {
		s->top = -1;
	}

	// Check if the stack is full
	int isfull(st* s) {
		if (s->top == MAX - 1)
			return 1;
		else
			return 0;
	}

	// Check if the stack is empty
	int isempty(st* s) {
		if (s->top == -1)
			return 1;
		else
			return 0;
	}

	// Add elements into stack
	void push(st* s, int newitem) {
		if (isfull(s)) {
			cout << "STACK FULL";
		} else {
			s->top++;
			s->items[s->top] = newitem;
		}
		size++;
	}

	// Remove element from stack
	void pop(st* s) {
		if (isempty(s)) {
			cout << "\n STACK EMPTY \n";
		} else {
			cout << "Item popped= " << s->items[s->top];
			s->top--;
		}
		size--;
		cout << endl;
	}

	// Print elements of stack
	void printStack(st* s) {
		printf("Stack: ");
		for (int i = 0; i < size; i++) {
			cout << s->items[i] << " ";
		}
		cout << endl;
	}

	// Driver code
	int _main() {
		std::cout << "CStack Output: " << std::endl;
		st* s = (st*)malloc(sizeof(st));

		createEmptyStack(s);

		push(s, 1);
		push(s, 2);
		push(s, 3);
		push(s, 4);

		printStack(s);

		pop(s);

		cout << "\nAfter popping out\n";
		printStack(s);
		std::cout << std::endl;
		return 0;
	}

} // namespace CStack

namespace CQueue {
#include <iostream>
#define SIZE 5

	using namespace std;

	class Queue {
	private:
		int items[SIZE], front, rear;

	public:
		Queue() {
			front = -1;
			rear  = -1;
		}

		bool isFull() {
			if (front == 0 && rear == SIZE - 1) {
				return true;
			}
			return false;
		}

		bool isEmpty() {
			if (front == -1)
				return true;
			else
				return false;
		}

		void enQueue(int element) {
			if (isFull()) {
				cout << "Queue is full";
			} else {
				if (front == -1)
					front = 0;
				rear++;
				items[rear] = element;
				cout << endl << "Inserted " << element << endl;
			}
		}

		int deQueue() {
			int element;
			if (isEmpty()) {
				cout << "Queue is empty" << endl;
				return (-1);
			} else {
				element = items[front];
				if (front >= rear) {
					front = -1;
					rear  = -1;
				} /* Q has only one element, so we reset the queue after
					 deleting it. */
				else {
					front++;
				}
				cout << endl << "Deleted -> " << element << endl;
				return (element);
			}
		}

		void display() {
			/* Function to display elements of Queue */
			int i;
			if (isEmpty()) {
				cout << endl << "Empty Queue" << endl;
			} else {
				cout << endl << "Front index-> " << front;
				cout << endl << "Items -> ";
				for (i = front; i <= rear; i++)
					cout << items[i] << "  ";
				cout << endl << "Rear index-> " << rear << endl;
			}
		}
	};

	int main() {
		Queue q;

		// deQueue is not possible on empty queue
		q.deQueue();

		// enQueue 5 elements
		q.enQueue(1);
		q.enQueue(2);
		q.enQueue(3);
		q.enQueue(4);
		q.enQueue(5);

		// 6th element can't be added to because the queue is full
		q.enQueue(6);

		q.display();

		// deQueue removes element entered first i.e. 1
		q.deQueue();

		// Now we have just 4 elements
		q.display();

		return 0;
	}
} // namespace CQueue
namespace CCircularQueue {
#include <iostream>
#define SIZE 5 /* Size of Circular Queue */

	using namespace std;

	class Queue {
	private:
		int items[SIZE], front, rear;

	public:
		Queue() {
			front = -1;
			rear  = -1;
		}
		// Check if the queue is full
		bool isFull() {
			if (front == 0 && rear == SIZE - 1) {
				return true;
			}
			if (front == rear + 1) {
				return true;
			}
			return false;
		}
		// Check if the queue is empty
		bool isEmpty() {
			if (front == -1)
				return true;
			else
				return false;
		}
		// Adding an element
		void enQueue(int element) {
			if (isFull()) {
				cout << "Queue is full";
			} else {
				if (front == -1)
					front = 0;
				rear		= (rear + 1) % SIZE;
				items[rear] = element;
				cout << endl << "Inserted " << element << endl;
			}
		}
		// Removing an element
		int deQueue() {
			int element;
			if (isEmpty()) {
				cout << "Queue is empty" << endl;
				return (-1);
			} else {
				element = items[front];
				if (front == rear) {
					front = -1;
					rear  = -1;
				}
				// Q has only one element,
				// so we reset the queue after deleting it.
				else {
					front = (front + 1) % SIZE;
				}
				return (element);
			}
		}

		void display() {
			// Function to display status of Circular Queue
			int i;
			if (isEmpty()) {
				cout << endl << "Empty Queue" << endl;
			} else {
				cout << "Front -> " << front;
				cout << endl << "Items -> ";
				for (i = front; i != rear; i = (i + 1) % SIZE)
					cout << items[i];
				cout << items[i];
				cout << endl << "Rear -> " << rear;
			}
		}
	};

	int main() {
		Queue q;

		// Fails because front = -1
		q.deQueue();

		q.enQueue(1);
		q.enQueue(2);
		q.enQueue(3);
		q.enQueue(4);
		q.enQueue(5);

		// Fails to enqueue because front == 0 && rear == SIZE - 1
		q.enQueue(6);

		q.display();

		int elem = q.deQueue();

		if (elem != -1)
			cout << endl << "Deleted Element is " << elem;

		q.display();

		q.enQueue(7);

		q.display();

		// Fails to enqueue because front == rear + 1
		q.enQueue(8);

		return 0;
	}
} // namespace CCircularQueue

namespace CPriorityQueue {
	// Priority Queue implementation in C++

#include <iostream>
#include <vector>
	using namespace std;

	// Function to swap position of two elements
	void swap(int* a, int* b) {
		int temp = *b;
		*b		 = *a;
		*a		 = temp;
	}

	// Function to heapify the tree
	void heapify(vector<int>& hT, int i) {
		int size = hT.size();

		// Find the largest among root, left child and right child
		int largest = i;
		int l		= 2 * i + 1;
		int r		= 2 * i + 2;
		if (l < size && hT[l] > hT[largest])
			largest = l;
		if (r < size && hT[r] > hT[largest])
			largest = r;

		// Swap and continue heapifying if root is not largest
		if (largest != i) {
			swap(&hT[i], &hT[largest]);
			heapify(hT, largest);
		}
	}

	// Function to insert an element into the tree
	void insert(vector<int>& hT, int newNum) {
		int size = hT.size();
		if (size == 0) {
			hT.push_back(newNum);
		} else {
			hT.push_back(newNum);
			for (int i = size / 2 - 1; i >= 0; i--) {
				heapify(hT, i);
			}
		}
	}

	// Function to delete an element from the tree
	void deleteNode(vector<int>& hT, int num) {
		int size = hT.size();
		int i;
		for (i = 0; i < size; i++) {
			if (num == hT[i])
				break;
		}
		swap(&hT[i], &hT[size - 1]);

		hT.pop_back();
		for (int i = size / 2 - 1; i >= 0; i--) {
			heapify(hT, i);
		}
	}

	// Print the tree
	void printArray(vector<int>& hT) {
		for (int i = 0; i < hT.size(); ++i)
			cout << hT[i] << " ";
		cout << "\n";
	}

	// Driver code
	int main() {
		vector<int> heapTree;

		insert(heapTree, 3);
		insert(heapTree, 4);
		insert(heapTree, 9);
		insert(heapTree, 5);
		insert(heapTree, 2);

		cout << "Max-Heap array: ";
		printArray(heapTree);

		deleteNode(heapTree, 4);

		cout << "After deleting an element: ";

		printArray(heapTree);
	}
} // namespace CPriorityQueue

namespace CDeque {
	// Deque implementation in C++

#include <iostream>
	using namespace std;

#define MAX 10

	class Deque {
		int arr[MAX];
		int front;
		int rear;
		int size;

	public:
		Deque(int size) {
			front	   = -1;
			rear	   = 0;
			this->size = size;
		}

		void insertfront(int key);
		void insertrear(int key);
		void deletefront();
		void deleterear();
		bool isFull();
		bool isEmpty();
		int getFront();
		int getRear();
	};

	bool Deque::isFull() {
		return ((front == 0 && rear == size - 1) || front == rear + 1);
	}

	bool Deque::isEmpty() {
		return (front == -1);
	}

	void Deque::insertfront(int key) {
		if (isFull()) {
			cout << "Overflow\n" << endl;
			return;
		}

		if (front == -1) {
			front = 0;
			rear  = 0;
		}

		else if (front == 0)
			front = size - 1;

		else
			front = front - 1;

		arr[front] = key;
	}

	void Deque ::insertrear(int key) {
		if (isFull()) {
			cout << " Overflow\n " << endl;
			return;
		}

		if (front == -1) {
			front = 0;
			rear  = 0;
		}

		else if (rear == size - 1)
			rear = 0;

		else
			rear = rear + 1;

		arr[rear] = key;
	}

	void Deque ::deletefront() {
		if (isEmpty()) {
			cout << "Queue Underflow\n" << endl;
			return;
		}

		if (front == rear) {
			front = -1;
			rear  = -1;
		} else if (front == size - 1)
			front = 0;

		else
			front = front + 1;
	}

	void Deque::deleterear() {
		if (isEmpty()) {
			cout << " Underflow\n" << endl;
			return;
		}

		if (front == rear) {
			front = -1;
			rear  = -1;
		} else if (rear == 0)
			rear = size - 1;
		else
			rear = rear - 1;
	}

	int Deque::getFront() {
		if (isEmpty()) {
			cout << " Underflow\n" << endl;
			return -1;
		}
		return arr[front];
	}

	int Deque::getRear() {
		if (isEmpty() || rear < 0) {
			cout << " Underflow\n" << endl;
			return -1;
		}
		return arr[rear];
	}

	int main() {
		Deque dq(4);

		cout << "insert element at rear end \n";
		dq.insertrear(5);
		dq.insertrear(11);

		cout << "rear element: " << dq.getRear() << endl;

		dq.deleterear();
		cout << "after deletion of the rear element, the new rear element: "
			 << dq.getRear() << endl;

		cout << "insert element at front end \n";

		dq.insertfront(8);

		cout << "front element: " << dq.getFront() << endl;

		dq.deletefront();

		cout << "after deletion of front element new front element: "
			 << dq.getFront() << endl;
	}
} // namespace CDeque