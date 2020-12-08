#include "Queue.h"
#include <string> 

int main()
{
	cout << "STack: " << endl;
	TStack<int> a({ 5, 10, 22 });
	cout << "Is full? " << a.IsFull() << endl;
	for (int i = 0; i < 3; i++)
		cout << a.pop() << ' ';
	
	cout << endl;

	cout << "Copying" << endl;
	TStack<int> b({ 1,2,3,4,5 });
	cout << b << endl;
	TStack<int> t(b);
	cout << t << endl;

	cout << "Queue:" << endl;

	TQueue<int> c({ 4,5,6,7,8 });

	cout << c << endl;
	cout << "Testing find max odd" << endl;
	cout << c.find_max_odd() << endl;

	cout << "Popping" << endl;
	c.pop();
	c.pop();
	cout << c << endl;

	cout << "Pushing" << endl;
	c.push(9);
	cout << c << endl;

	cout << "Cleansing (3)" << endl;
	c.cleanse(3);
	cout << c << endl;

	cout << "Transforming" << endl;
	TStack<int> p = c.transform();
	cout << p << endl;

	return 0;
}