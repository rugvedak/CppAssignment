class Stack {
private:
    int* array;     // Dynamically allocated array
    int top;        // Index of the top element
    int size;       // Size of the stack

public:
    // Parameterized constructor
    Stack(int stackSize = 5) {
        size = stackSize;
        array = new int[size];
        top = -1;  // Initialize top to -1 (empty stack)
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] array;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push element." << std::endl;
            return;
        }
        array[++top] = value;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop element." << std::endl;
            return;
        }
        top--;
    }

    // Peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << std::endl;
            return -1; // Return a default value
        }
        return array[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == size - 1;
    }

    // Print the elements of the stack
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty." << std::endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            cout << array[i] << " ";
        }
        cout << std::endl;
    }
};
// to use fixed constant values
typedef enum menuchoice {
	Exit = 0, Push_Element, Pop_Element, Peek_Element, Print_Stack
} MENUCHOCIE;

int MenuChoice();
void AcceptRecord(int &data);
void PrintRecord(int &data);

int main() {

	int data, size; // to add data  as integer number

	cout << "Enter how many size" << endl;
	cin >> size;

	Stack stack(size);

	do {

		choice = MenuChoice();
		switch (choice) {
		case Push_Element: // Push
			if (!stack.isFull()) { //checking the condition here is stack is not full
				AcceptRecord(data);
				stack.push(data);
				stack.PrintStack();
			} else
				cout << "stack is full" << endl;
			break;
		case Pop_Element: // Pop
			if (!stack.isEmpty()) {
				data = stack.peek();
				stack.pop();
				cout << "poped value =" << data << endl;
				stack.PrintStack();
			} else {
				cout << "stack is empty" << endl;
			}

			break;
		case Peek_Element: // Peek
			if (!stack.isEmpty()) {
				data = stack.peek();
				cout << "poped value =" << data << endl;
				stack.PrintStack();
			} else
				cout << "Stack is empty" << endl;
			break;
		case Print_Stack: // print stack

			stack.PrintStack();
			break;
		default:
			cout << "invalid choice" << endl;
			continue;

		}

		cout << "Enter 1 to continue or 0 to Exit";
		cin >> choice;

	} while (choice != 0);

	return 0;
}
void AcceptRecord(int &data) {
	cout << "Enter value :: ";
	cin >> data;
}
void PrintRecord(int &data) {
	cout << "data :: " << data << endl;
}

int MenuChoice() {
	int choice;
	cout << "1. Push (add element into stack )" << endl;
	cout << "2. Pop (remove element from stack )" << endl;
	cout << "3. Peek (display top element from stack )" << endl;
	cout << "4. Print Stack " << endl;

	cout << "Enter Your Choice :: ";
	cin >> choice;
	return choice;
}
