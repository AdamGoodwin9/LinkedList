#include "List.h"

int main()
{
	LinkedList<int> list = LinkedList<int>();

	for (char i = 58; i < 64; i++)
	{
		list.add(i);
	}
	
	//list.makeCircle();

	list.print();

	getchar();
	return 0;
}