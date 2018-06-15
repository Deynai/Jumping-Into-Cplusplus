#include <iostream>

// debug
int move_counter = 0;

struct disk
{
	int size;
	disk* p_next;
};

// initiates n ordered disks on stick 1;
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

// display current state of sticks - used for debug
void displaySticks(disk** stick)
{
	disk* currentDisk;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << "\n";
		currentDisk = stick[i];
		std::cout << "Stick " << i+1 << ": ";
		while (currentDisk != NULL)
		{
			std::cout << currentDisk->size << " ";
			currentDisk = currentDisk->p_next;
		}
	}
	return;
}

void moveDisk(disk** stick, int source, int target)
{
	// debug
	move_counter += 1;

	// debug - does nothing unless errors
	// displaySticks(stick);
	if (stick[source] == NULL)
	{
		std::cout << "\n\nILLEGAL MOVE - Tried to move a non-existent disk from an empty stick!";
		return;
	}
	//---

	disk* newDisk = new disk;
	newDisk->size = stick[source]->size;
	newDisk->p_next = stick[target];
	stick[target] = newDisk;

	disk* tempDisk = stick[source];
	stick[source] = stick[source]->p_next;
	delete tempDisk;

	// debug - does nothing unless errors
	if (newDisk->p_next != NULL)
	{
		if (newDisk->size > newDisk->p_next->size)
		{
			std::cout << "\n\nILLEGAL MOVE - Tried to place a big disk onto a smaller one!";
		}
	}
	//---

	return;
}

// meat and potatoes, this solves n hanoi disks moving from stick[source] to stick[target], lots of recursion inside
void solveHanoi(disk** stick, int n, int source, int target)
{
	if (n == 1) // base case of only moving the smallest disk
	{
		moveDisk(stick, source, target);
	}
	else
	{
		solveHanoi(stick, n - 1, source, 3 - source - target); // solve n-1 hanoi disks from the source to the free stick
		moveDisk(stick, source, target); // move the biggest nth disk from the source to the target stick
		solveHanoi(stick, n - 1, 3 - source - target, target);  // solve the n-1 hanoi disks from the free stick to the target stick
	}
	return;
}

int main()
{
	disk** stick = new disk*[3]; // pointer to array, stick[i] is a pointer to the first element of a linked list storing the disks on stick i+1
	for (size_t i = 0; i < 3; i++)
	{
		stick[i] = NULL; // empty sticks
	}
	int n = 20; // number of disks
	stick[0] = initStick(stick[0], n); // initialises disks on stick 1

	solveHanoi(stick, n, 0, 2); // start of recursion, no need to return anything as stick is a **pp and changes to each stick[i] will persist

	// debug
	displaySticks(stick);
	std::cout << "\n\nNumber of Moves: " << move_counter;
	// -- 

	int exitprogram;
	std::cout << "\n\nExiting.";
	std::cin >> exitprogram;
	return 0;
}