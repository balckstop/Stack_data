#include <iostream>
#include <string>

template<class T>class Data {
    
    private:
    struct Node {
        T data;
        Node *link;
    };
    Node *top;
    public:
    Data();
    ~Data();
    void push(T x);
    void pop();
    void peek();
    void display();
};

template<class T> Data<T>::Data() { top = 0; }

template<class T> Data<T>::~Data() {}

template<class T> void Data<T>::push(T x) {
    Node *newnode;
    newnode = new Node();
    newnode -> data = x;
    newnode -> link = top;
    top = newnode;
}

template<class T> void Data<T>::pop() {
    if (top == 0) { std::cout << "Stack is empty" << std::endl; }
    Node *temp;
    temp = top;
    top = top -> link;
    std::cout << temp -> data << " is deleted" << std::endl;
    delete temp;
}

template<class T> void Data<T>::peek() {
    if (top == 0) { std::cout << "Stack is empty" << std::endl; }
    std::cout << top -> data << std::endl;
}

template<class T> void Data<T>::display() {
    if (top == 0) { std::cout << "Stack is empty" << std::endl; }
    Node *temp;
    temp = top;
    std::cout << "\n===========" << std::endl;
    while (temp != 0) {
        std::cout << temp -> data << std::endl;
        temp = temp -> link;
    }
    std::cout << "\n===========" << std::endl;
}

int main() {
    Data<int> b;
    b.push(1);
    b.push(2);
    b.push(3);
    b.push(4);
    b.display();
    b.pop();
    b.display();
    
    Data<std::string> a;
    a.push("!!!");
    a.push("THERE");
    a.push("HI");
    a.display();
}