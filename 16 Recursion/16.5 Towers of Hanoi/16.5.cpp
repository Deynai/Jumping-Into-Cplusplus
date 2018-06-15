#include <iostream>

struct disk
{
	int size;
	disk* p_next;
};

disk* initStick(disk* stick, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		disk* newDisk = new disk;
		newDisk->size = n - i;
		newDisk->p_next = stick;
		stick = newDisk;
	}
	return stick;
}

void displaySticks(disk** stick)
{
	disk* currentDisk;
	for (size_t i = 0; i < 3; i++)
	{
		currentDisk = stick[i];
		std::cout << "Stick " << i << ":\n";
		while (currentDisk != NULL)
		{
			std::cout << currentDisk->size << "\n";
			currentDisk = currentDisk->p_next;
		}
	}
	return;
}

int main()
{
	disk** stick = new disk*[3];
	for (size_t i = 0; i < 3; i++)
	{
		stick[i] = NULL;
	}
	int n = 5; // number of disks
	stick[0] = initStick(stick[0], n);

	displaySticks(stick);

	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}