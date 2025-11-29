#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Linked List: ";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    bool searchElement(int key)
    {
        Node *current = head;
        int c = 0;
        while (current != nullptr)
        {
            c++;
            if (current->data == key)
            {
                cout << "Element found at position " << c << endl;
                return true;
            }
            current = current->next;
        }
        cout << "Element not found.\n";
        return false;
    }

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            cout << "LL was empty inserted " << value << " as the first element.\n";
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << value << " at the end.\n";
    }

    void insertAtPosition(int value, int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid position.\n";
            return;
        }
        if (pos == 1)
        {
            insertAtBeginning(value);
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "Position out of range.\n";
            return;
        }
        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << pos << ".\n";
    }

    void deleteAtBeginning()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        cout << "Deleted element " << temp->data << " from the beginning.\n";
        delete temp;
    }

    void deleteAtEnd()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next)
        {
            cout << "Deleted element " << head->data << " from the end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        cout << "Deleted element " << temp->next->data << " from the end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int pos)
    {
        if (pos <= 0 || !head)
        {
            cout << "Invalid position or empty list.\n";
            return;
        }
        if (pos == 1)
        {
            deleteAtBeginning();
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
        {
            temp = temp->next;
        }
        if (!temp || !temp->next)
        {
            cout << "Position out of range.\n";
            return;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        cout << "Deleted element " << delNode->data << " from position " << pos << ".\n";
        delete delNode;
    }
};

int main()
{
    LinkedList list;
    int choice, value, pos, key;

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Display\n";
        cout << "2. Search\n";
        cout << "3. Insert at Beginning\n";
        cout << "4. Insert at End\n";
        cout << "5. Insert at Position\n";
        cout << "6. Delete at Beginning\n";
        cout << "7. Delete at End\n";
        cout << "8. Delete at Position\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.display();
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> key;
            list.searchElement(key);
            break;
        case 3:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 4:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 5:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            list.insertAtPosition(value, pos);
            break;
        case 6:
            list.deleteAtBeginning();
            break;
        case 7:
            list.deleteAtEnd();
            break;
        case 8:
            cout << "Enter position: ";
            cin >> pos;
            list.deleteAtPosition(pos);
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
