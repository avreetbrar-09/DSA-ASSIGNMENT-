#include <iostream>
using namespace std;



class Stack {
    int arr[10];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == 10 - 1);
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed into stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack empty. Nothing to pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
     Stack s;
    int  choice ,value;
    do {
        cout << "\nWhat operation do you want to perform?\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check Empty\n6. Check Full\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
        } 
        else if (choice == 2) {
            s.pop();
        } 
        else if (choice == 3) {
            s.peek();
        } 
        else if (choice == 4) {
            s.display();
        } 
        else if (choice == 5) {
            if (s.isEmpty())
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is NOT Empty." << endl;
        } 
        else if (choice == 6) {
            if (s.isFull())
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is NOT Full." << endl;
        } 
        else if (choice == 7) {
            cout << "Exiting program." << endl;
        } 
        else {
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 7);
    return 0;
}