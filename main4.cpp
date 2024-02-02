#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T item) : data(item), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(T item) {
        Node<T>* newNode = new Node<T>(item);
        newNode->next = top;
        top = newNode;
    }

    T pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            // You might want to handle this error differently based on your application
            exit(EXIT_FAILURE);
        }

        T data = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;

        return data;
    }

    T peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty" << std::endl;
            // You might want to handle this error differently based on your application
            exit(EXIT_FAILURE);
        }

        return top->data;
    }

    void display() const {
        Node<T>* current = top;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Stack:" << std::endl;
    stack.display();

    std::cout << "Peek: " << stack.peek() << std::endl;

    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;

    std::cout << "Stack after pops:" << std::endl;
    stack.display();

    return 0;
}
