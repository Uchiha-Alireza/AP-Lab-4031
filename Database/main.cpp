#include "Account.h"
#include "AccountList.h"



AccountList* generateSomeRandomAccounts()
{
	auto acc1 = new Account("reyhan");
	Account* acc2 = new Account("nikoo");
	Account *acc3 = new Account("ali");
	Account *acc4 = new Account("mohammad");
	Account* acc5 = new Account("peyman");
	Account* acc6 = new Account("Azar");
	Account* acc7 = new Account("Maryam");

	auto list = new AccountList(acc6);
	list->addAccount(acc1);
	list->addAccount(acc5);
	list->addAccount(acc7);
	list->addAccount(acc3);
	list->addAccount(acc2);
	list->addAccount(acc4);

	return list;
}

int main()
{
	AccountList *test = generateSomeRandomAccounts();
	test->print();
	Account* sortedHead = test->MergeSort(test->getHead());	std::cout << "\n \n";
	test->print();
	
	return 0;
}