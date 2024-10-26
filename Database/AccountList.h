#pragma once
#include "Account.h"


class AccountList
{
public:
	AccountList();
	AccountList(Account* _head);
	Account* getHead()const;
	void addAccount(Account* _accountToAdd);

	/* find element number i */
	Account& at(int i);
	Account* merge(Account*, Account*);
	Account* MergeSort(Account*);
	Account* split(Account*);
	/* search by the account uniqe id*/
	Account search(int _uniqeId);

	/*search by accout username*/
	void search(std::string _username);
	
	void swap(Account& acc1, Account& acc2);
	void print();
private:
	Account* head;
	int size;
};



