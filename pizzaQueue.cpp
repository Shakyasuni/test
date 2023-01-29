#include <iostream>
#include <string>
using namespace std;

class pizza
{
public:
	string toppings, address;
	pizza* next;
	pizza(string toppings, string address)
	{
		this->address = address;
		this->toppings = toppings;
		next = NULL;
	}
};

void enqueue(pizza** head, pizza** tail, pizza* thispizza)
{
	if (*head == NULL) *head = thispizza;
	else (*tail)->next = thispizza;
	*tail = thispizza;
	return;
}

pizza* dequeue(pizza** head, pizza** tail)
{
	pizza* pizzatodeliver = NULL;
	if (*head != NULL)
	{
		pizzatodeliver = *head;
		*head = (*head)->next;
	}
	if (*head == NULL) *tail = NULL;
	return pizzatodeliver;
}

void deliver(pizza** head, pizza** tail)
{
	pizza* thispizza = dequeue(head, tail);
	if (thispizza == NULL)
	{
		cout << "No deliveries pending" << endl; return;
	}
	cout << "Deliver a pizza with " << thispizza->toppings
		 << " to " << thispizza->address << endl;
}

void onestore()
{
	pizza *first=NULL, *last=NULL;

	enqueue(&first, &last, new pizza("pepperoni", "1234 Bobcat Trail"));
	enqueue(&first, &last, new pizza("sausage", "2345 University Drive"));
	deliver(&first, &last);
	enqueue(&first, &last, new pizza("extra cheese", "3456 Rickster Road"));
	enqueue(&first, &last, new pizza("everything", "4567 King Court"));
	enqueue(&first, &last, new pizza("coffee beans", "5678 Java Circle"));
	deliver(&first, &last);
	deliver(&first, &last);
	deliver(&first, &last);
	deliver(&first, &last);
	deliver(&first, &last);
}

void twostores()
{
	pizza* s1f = NULL, * s1l = NULL;  //first and last ptrs for 1st store queue
	pizza* s2f = NULL, * s2l = NULL;  //first and last ptrs for 2nd store queue

	enqueue(&s1f, &s1l, new pizza("111111", "111111111111111"));
	enqueue(&s2f, &s2l, new pizza("AAAAAA", "AAAAAAAAAAAAAAA"));
	enqueue(&s1f, &s1l, new pizza("222222", "222222222222222"));
	enqueue(&s2f, &s2l, new pizza("BBBBBB", "BBBBBBBBBBBBBBB"));
	enqueue(&s1f, &s1l, new pizza("333333", "333333333333333"));
	enqueue(&s2f, &s2l, new pizza("CCCCCC", "CCCCCCCCCCCCCCC"));
	enqueue(&s1f, &s1l, new pizza("444444", "444444444444444"));
	enqueue(&s2f, &s2l, new pizza("DDDDDD", "DDDDDDDDDDDDDDD"));
	enqueue(&s1f, &s1l, new pizza("555555", "555555555555555"));
	enqueue(&s2f, &s2l, new pizza("EEEEEE", "EEEEEEEEEEEEEEE"));
	enqueue(&s1f, &s1l, new pizza("666666", "666666666666666"));
	enqueue(&s2f, &s2l, new pizza("FFFFFF", "FFFFFFFFFFFFFFF"));

	deliver(&s1f, &s1l);
	deliver(&s1f, &s1l);
	deliver(&s1f, &s1l);
	deliver(&s1f, &s1l);
	deliver(&s1f, &s1l);
	deliver(&s1f, &s1l);
	deliver(&s1f, &s1l);

	deliver(&s2f, &s2l);
	deliver(&s2f, &s2l);
	deliver(&s2f, &s2l);
	deliver(&s2f, &s2l);
	deliver(&s2f, &s2l);
	deliver(&s2f, &s2l);
	deliver(&s2f, &s2l);
}

int main()
{
	// onestore();
	twostores();
	return 0;
}