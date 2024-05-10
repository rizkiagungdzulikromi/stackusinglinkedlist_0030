#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() {
		next = NULL;
	}
};

class Stack {
private:
	Node* top;

public:
	Stack() {
		top = NULL;
	}

	int push(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = top;
		top = newNode;
		cout << "Push value: " << value << endl;
		return value;
	}

	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty." << endl;
		}
		else {
			cout << "Popped value: " << top->data << endl;
			Node* temp = top;
			top = top->next;
			delete temp;
		}
	}

	void peek() {
		if (isEmpty()) {
			cout << "Stack is empty. No top value." << endl;
		}
		else {
			cout << "Top value: " << top->data << endl;
		}
	}

	bool isEmpty() {
		return top == NULL;
	}
};

int main() {
	Stack stack;

	int choice = 0;
	int value;

	while (choice != 4) {
		cout << "1. Push\n";
		cout << "2. Pop\n";
		cout << "3. Peek\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the value to push: ";
			cin >> value;
			stack.push(value);
			break;
		case 2:
			if (!stack.isEmpty()) {
				stack.pop();
			}
			else {
				cout << "Stack is empty. Cannot pop." << endl;
			}
			break;
		case 3:
			stack.peek();
			break;
		case 4:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice. Try again." << endl;
			break;
		}

		cout << endl;
	}

	return 0;
}

