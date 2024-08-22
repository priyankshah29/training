#include <iostream>
#include <vector>

using namespace std;


struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List 
class LinkedList
{
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void addToEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Value added to end of the linked list." << endl;
    }

    void addToBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Value added to beginning of the linked list." << endl;
    }

    void removeByValue(int value)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty" << endl;
            return;
        }

        
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Value " << value << " removed from the linked list." << endl;
            return;
        }

       
        Node *current = head;
        Node *previous = nullptr;
        while (current != nullptr && current->data != value)
        {
            previous = current;
            current = current->next;
        }

        
        if (current == nullptr)
        {
            cout << "Value " << value << " not found in the linked list." << endl;
            return;
        }

        
        previous->next = current->next;
        delete current;
        cout << "Value " << value << " removed from the linked list." << endl;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty!" << endl;
            return;
        }
        cout << "Linked list contents: ";
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout <<"NULL"<<endl;
    }
};

// Stack 
class Stack
{
    vector<int> stack;

public:
    void push(int value)
    {
        stack.push_back(value);
        cout << "Value pushed to stack." << endl;
    }

    void pop()
    {
        if (stack.empty())
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << "Popped value: " << stack.back() << endl;
            stack.pop_back();
        }
    }

    void peek()
    {
        if (stack.empty())
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << "Top value: " << stack.back() << endl;
        }
    }

    void display()
    {
        if (stack.empty())
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << "Stack contents: ";
            for (int i = stack.size() - 1; i >= 0; i--)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

// Queue class 
class Queue
{
    vector<int> queue;
    int front = 0;

public:
    void enqueue(int value)
    {
        queue.push_back(value);
        cout << "Value enqueued." << endl;
    }

    void dequeue()
    {
        if (front >= queue.size())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "Dequeued value: " << queue[front++] << endl;
            if (front == queue.size())
            { 
                queue.clear();
                front = 0;
            }
        }
    }

    void peek()
    {
        if (front >= queue.size())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "Front value: " << queue[front] << endl;
        }
    }

    void display()
    {
        if (front >= queue.size())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "Queue contents: ";
            for (int i = front; i < queue.size(); i++)
            {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int choice;
    bool exit = false;

    while (!exit)
    {
        cout << "Select the Data Structure to Implement:" << endl;
        cout << "1. Stack" << endl;
        cout << "2. Queue" << endl;
        cout << "3. Linked List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Stack stack;
            bool back = false;
            while (!back)
            {
                cout << "\nStack Operations:" << endl;
                cout << "1. Push" << endl;
                cout << "2. Pop" << endl;
                cout << "3. Peek" << endl;
                cout << "4. Display" << endl;
                cout << "5. Back" << endl;
                cout << "6. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    int value;
                    cout << "Enter value to push: ";
                    cin >> value;
                    stack.push(value);
                    break;
                }
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.peek();
                    break;
                case 4:
                    stack.display();
                    break;
                case 5:
                    back = true;
                    break;
                case 6:
                    exit = true;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
                }
            }
            break;
        }
        case 2:
        {
            Queue queue;
            bool back = false;
            while (!back)
            {
                cout << "\nQueue Operations:" << endl;
                cout << "1. Enqueue" << endl;
                cout << "2. Dequeue" << endl;
                cout << "3. Peek" << endl;
                cout << "4. Display" << endl;
                cout << "5. Back" << endl;
                cout << "6. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    int value;
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    queue.enqueue(value);
                    break;
                }
                case 2:
                    queue.dequeue();
                    break;
                case 3:
                    queue.peek();
                    break;
                case 4:
                    queue.display();
                    break;
                case 5:
                    back = true;
                    break;
                case 6:
                    exit = true;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
                }
            }
            break;
        }
        case 3:
        {
            LinkedList linkedList;
            bool back = false;
            while (!back)
            {
                cout << "\nLinked List Operations:" << endl;
                cout << "1. Add to end" << endl;
                cout << "2. Add to beginning" << endl;
                cout << "3. Remove by value" << endl;
                cout << "4. Display" << endl;
                cout << "5. Back" << endl;
                cout << "6. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    int value;
                    cout << "Enter value to add: ";
                    cin >> value;
                    linkedList.addToEnd(value);
                    break;
                }
                case 2:
                {
                    int value;
                    cout << "Enter value to add: ";
                    cin >> value;
                    linkedList.addToBeginning(value);
                    break;
                }
                case 3:
                {
                    int value;
                    cout << "Enter value to remove: ";
                    cin >> value;
                    linkedList.removeByValue(value);
                    break;
                }
                case 4:
                    linkedList.display();
                    break;
                case 5:
                    back = true;
                    break;
                case 6:
                    exit = true;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
                }
            }
            break;
        }
        case 4:
            exit = true;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    cout << "Exiting the application. Goodbye!" << endl;
    return 0;
}