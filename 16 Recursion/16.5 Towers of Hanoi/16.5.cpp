#include <iostream>

struct disk
{
	int size;
	disk* p_next;
};

disk* initStickA(disk* stickA, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		disk* newDisk = new disk;
		newDisk->size = n - i;
		newDisk->p_next = stickA;
		stickA = newDisk;
	}
	return stickA;
}

void displaySticks(disk* stickA = NULL, disk* stickB = NULL, disk* stickC = NULL)
{
	disk* currentDisk = stickA;
	std::cout << "Stick A:\n";
	while (currentDisk != NULL)
	{
		std::cout << currentDisk->size << "\n";
		currentDisk = currentDisk->p_next;
	}

	std::cout << "Stick B:\n";
	currentDisk = stickB;
	while (currentDisk != NULL)
	{
		std::cout << currentDisk->size << "\n";
		currentDisk = currentDisk->p_next;
	}

	std::cout << "Stick C:\n";
	currentDisk = stickC;
	while (currentDisk != NULL)
	{
		std::cout << currentDisk->size << "\n";
		currentDisk = currentDisk->p_next;
	}
	return;
}

int main()
{
	disk* stickA = NULL;
	disk* stickB = NULL;
	disk* stickC = NULL;
	int n = 5; // number of disks
	stickA = initStickA(stickA, n);

	displaySticks(stickA);

	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}