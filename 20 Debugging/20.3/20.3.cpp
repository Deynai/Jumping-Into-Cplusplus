// Problem 3: Bugs with Fibonacci

#include <iostream>
using namespace std;

int fibonacci(int n)
{
	// if (n == 0)
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
	int n;
	cout << "Enter the number to compute fibonacci for: " << endl;
	cin >> n;
	cout << fibonacci(n);

	int exit;
	std::cin >> exit;
	return 0;
}