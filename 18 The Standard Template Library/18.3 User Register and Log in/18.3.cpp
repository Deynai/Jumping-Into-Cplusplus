/*
Write a program with two options: register user and log in. Register user allows a new user to
create a login name and password. Log in allows a user to log in and access a second area, with
options for “change password” and “log out”. Change password allows the user to change the
password, and log out will return the user to the original screen.
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>

std::string requestInput(std::string request)
{
	// instead of typing this out 10 times for different inputs, here's a general function with an arg to request anything.
	std::cout << "\nPlease enter " << request << ":\n";
	std::cin >> request;
	return request;
}

std::map<std::string, std::string> loadUsers()
{
	std::string input;
	std::map<std::string, std::string> users;

	std::ifstream file;
	file.open("Users.txt");
	if (file.is_open())
	{
		while (std::getline(file, input))
		{
			// substr(starting character, length)
			// let 'username' be the start of the line to the first space
			std::string username = input.substr(0, input.find(" "));
			// let 'password' be the character AFTER the first space to the end of the line
			std::string password = input.substr(input.find(" ") + 1, input.length() - input.find(" "));
			users[username] = password;
		}
		file.close();
	}
	return users;
}

void saveUsers(std::map<std::string, std::string> users)
{
	std::ofstream file;
	file.open("Users.txt");

	for (std::map<std::string, std::string>::iterator i = users.begin(), end = users.end(); i != end; ++i)
	{
		// save each entry in the map to a line of the form "name address" in a text file
		file << i->first << " " << i->second << "\n";
	}

	file.close();
	return;
}

void registerUser(std::map<std::string, std::string> &users)
{
	std::string username = requestInput("Username");
	// check that we don't already have the username, we don't want to write over other users (even worse, effectively let them change other users passwords and then access their account!)
	if (users.find(username) != users.end())
	{
		std::cout << "\nUsername already exists!\n\n";
		return;
	}
	// if the username is unique, request a password and register the new user.
	users[username] = requestInput("Password");
	std::cout << "\nNew user successfully registered.\n\n";
	return;
}

std::string attemptLogin(std::map<std::string, std::string> users)
{
	std::string user = requestInput("username");
	std::string pw = requestInput("password"); 
	// slightly dangerous, the second statement could crash the program if it is evaluated and user doesn't exist. The first statement evaluates first and if true, the second is skipped!
	if (users.find(user) == users.end() || users.find(user)->second != pw) 
	{
		// if the user doesn't exist, or if the password doesn't match, then return a blank string
		return "";
	}
	//else return the user;
	return user;
}

void changePassword(std::map<std::string, std::string> &users, std::string currentUser)
{
	if (requestInput("current Password") == users[currentUser]) // let's make sure the user knows the current password
	{
		std::string newPass = requestInput("a new password");
		if (newPass == requestInput("the new password again")) // let's make the user enter the new password twice to avoid any accidental typos
		{
			users[currentUser] = newPass; // finally! update currentUser with the new password
			std::cout << "\nSuccessfully updated password.\n\n";
			return;
		}
		std::cout << "\nNew password does not match\n\n";
		return;
	}
	std::cout << "\nIncorrect Password\n\n";
	return;
}

bool afterLogin(std::map<std::string, std::string> &users, std::string currentUser)
{
	system("CLS");
	std::cout << "Welcome " << currentUser; ".\n";

	int menu = 0;
	// let's stay logged in until we choose an option to leave
	while (true)
	{
		std::cout << "\n1. Change Password\n2. Log out\n3. Exit Program\n";
		std::cin >> menu;
		switch (menu)
		{
		case 1:
			changePassword(users, currentUser); // change password requires the currentUser too, we don't want to allow changing anyones password!
			break;
		case 2: return 0; // sets exit = 0 in the mainMenu, so we will stay looping in the main menu.
			break;
		case 3: return 1; // sets exit = 1 in the mainMenu, so we will exit the program entirely without further input.
			break;
		default:
			break;
		}
	}
}

void mainMenu(std::map<std::string, std::string> &users)
{
	bool exit = 0;
	int menu = 0;
	std::string currentUser;

	while (!exit)
	{
		std::cout << "Main Menu\n1. Log-in\n2. Register\n3. Exit.\n";
		std::cin >> menu;
		switch (menu)
		{
		case 1: 
			// attempt to login, if successful we will have a currentUser.
			currentUser = attemptLogin(users);
			if (currentUser != "")
			{
				// if we have a currentUser, we can enter the program, (which will return either 0 or 1 depending on if we want to just log out, or exit the program entirely)
				exit = afterLogin(users, currentUser);
			}
			else
			{
				// unsuccessful login attempt
				std::cout << "\nIncorrect username or password.\n";
			}
			break;
		case 2:
			registerUser(users);
			break;
		case 3: exit = 1;
			break;
		default:
			break;
		}
	}
}


int main()
{
	// load map of users,passwords from a text file
	std::map<std::string, std::string> users = loadUsers();

	// enter the main menu. mainMenu() handles most of the work here and I probably should have just put all of it into main()
	mainMenu(users);

	// before exiting, let's save our map of users to a text file so it can be loaded next time we run the program.
	saveUsers(users);
}