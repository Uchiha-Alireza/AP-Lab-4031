#include "AccountList.h"


AccountList::AccountList(){}

AccountList::AccountList(Account* _head)
	: head(_head),size(1){}

void AccountList::addAccount(Account* _accountToAdd)
{
   Account *account = new Account(*_accountToAdd);
    this->at(size-1).next= new Account(*account);   
    size++;
}

Account* AccountList:: getHead()const { return head; }

void AccountList::swap(Account& acc1, Account& acc2)
{

    Account* prevX = nullptr, * currX = nullptr;
    Account* prevY = nullptr, * currY = nullptr;
    Account* curr = head;

    // First loop to find x
    while (curr != nullptr) {
        if (curr->getUniqeId() == acc1.getUniqeId()) {
            currX = curr;
            break;
        }
        prevX = curr;
        curr = curr->next;
    }

    curr = head;

    // Second loop to find y
    while (curr != nullptr) {
        if (curr->getUniqeId() == acc2.getUniqeId()) {
            currY = curr;
            break;
        }
        prevY = curr;
        curr = curr->next;
    }

    // If either x or y is not present, nothing to do
    if (currX == nullptr || currY == nullptr) return;

    // If x is not head of the linked list
    if (prevX != nullptr) {
        prevX->next = currY;
    }
    else {
        head = currY;
    }

    // If y is not head of the linked list
    if (prevY != nullptr) {
        prevY->next = currX;
    }
    else {
        head = currX;
    }

    // Swap next pointers
    Account* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;

    return ;
}
  

Account& AccountList::at(int index)
{
    Account* current = head;
    for (size_t i = 0; i < index; i++)
    {
        current = current->next;
    }
    return *current;
}

Account* AccountList::split(Account* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Account* slow = head;
    Account* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Account* second = slow->next;
    slow->next = nullptr;
    return second;
}

Account* AccountList::merge(Account* first, Account* second) {
    if (first == nullptr) return second;
    if (second == nullptr) return first;

    if (first->getName()<= second->getName()) {
        first->next = merge(first->next, second);
        return first;
    }
    else {
        second->next = merge(first, second->next);
        return second;
    }
}

Account* AccountList::MergeSort(Account* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Account* second = split(head);
    head = MergeSort(head);
    second = MergeSort(second);
    return merge(head, second);
}
Account* AccountList::split(Account* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; 
    }

    Account* slow = head;        
    Account* fast = head->next;  
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       
        fast = fast->next->next; 
    }

    Account* secondHalf = slow->next; 
    slow->next = nullptr; 
    return secondHalf; 
}

void AccountList::print()
{
    Account* current = head;
    for (size_t i = 0; i < size; i++)
    {
        current->print();
        current = current->next;
    }
}