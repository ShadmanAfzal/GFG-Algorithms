#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList *next;
};

LinkedList *insertIntoList(vector<int> arr)
{
    LinkedList *head = new LinkedList();
    LinkedList *ptr = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            head->data = arr[i];
            head->next = NULL;
            ptr = head;
        }
        else
        {
            LinkedList *newNode = new LinkedList();
            newNode->data = arr[i];
            newNode->next = NULL;
            ptr->next = newNode;
            ptr = newNode;
        }
    }
    return head;
}

void printList(LinkedList *head)
{
    LinkedList *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void findMiddle(LinkedList *head, LinkedList **first, LinkedList **second)
{
    LinkedList *fast = head->next;
    LinkedList *slow = head;

    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *first = head;
    *second = slow->next;
    slow->next = NULL;
}

LinkedList *merge(LinkedList *a, LinkedList *b)
{

    LinkedList *node = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    
    if(a->data <= b->data){
        node = a;
        node->next = merge(a->next,b);
    }
    else{
        node = b;
        node->next = merge(a,b->next);
    }

    return node;
}

void mergeSort(LinkedList **headRef)
{
    LinkedList* head = *headRef;
    LinkedList *first = NULL;
    LinkedList *second = NULL;
    if (!head or !head->next)
        return;
    findMiddle(head, &first, &second);
    mergeSort(&first);
    mergeSort(&second);
    *headRef = merge(first, second);
}

int main()
{
    vector<int> arr{5, 3, 2, 1, 4};
    LinkedList *head = insertIntoList(arr);
    printList(head);
    mergeSort(&head);
    printList(head);

}