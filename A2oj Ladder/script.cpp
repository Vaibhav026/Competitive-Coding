#include <iostream>
#include <fstream>
using namespace std;

int main()
{


	ifstream is("uremoved.txt");

	char c;

	while(is.get(c))
	{
		cout << c;
	}	

	return 0;
}

