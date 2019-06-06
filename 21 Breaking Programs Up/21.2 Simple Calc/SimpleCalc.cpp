int calcAdd(int &a, int &b)
{
	return a + b;
}

int calcSubtract(int &a, int &b)
{
	return a - b;
}

int calcMultiply(int &a, int&b)
{
	return a * b;
}

int calcDivide(int &a, int &b)
{
	if (b == 0)
	{
		return 0;
	}
	return a / b;
}