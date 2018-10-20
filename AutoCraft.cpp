/*
	AutoCraft is a crafting script for Final Fantasy XIV(FF14). It simulate the key pressing events.
	The key specified by the user in the command line should be set to in-game macros, which are crafting macros.
	The delay between two macros is set to 40 seconds.
	
	Instruction:
		To Compile:
			- an simple c++ compile set-up will work. For example: g++ -o autocraft AutoCraft.cpp
		To Run:
			- Open crafting logs and go to the page of the item you want to craft
			- open a command line by searching "cmd"
			- navigate to the folder which contains this script
			- run the script by entering "autocraft.exe <macro_keys>". 
				Replace <macro_keys> by the keys binding the your macros
				The script is order sensitive.
				Example: autocraft.exe 2 1
					Where 2 is the key for the first macro and 1 is the key for the second
			- switch back to the game window
			- the game window IS REQUIRED to be OPENED while the script is running
		To Stop:
			- go to the command line and press ctrl+c
		
		
		Author: InazumaIkazuchi
		Date: 2018-10-18
*/



#include <iostream>
#include <cstdlib>
#include <windows.h>

#define MAX_SIZE 5
#define DELAY_IN_MS 5000
#define WAIT_TIME_IN_MS 45000

char key;
int n;

// Press the key
// 	parameters:
//		key: the key to press
void press(char key)
{
	INPUT ip;

	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	
	ip.ki.wVk = key;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));
	
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}


int main(int argc, char* argv[])
{
	// gather info from the arguments
	if(argc <= 1)
	{
		std::cout << "Invalid Input.\n\tUsage: autocraft.exe <macro_keys>" << std::endl;
		return 1;
	}
	else if(argc > MAX_SIZE)
	{
		std::cout << "ERROR: Too many arguments.\n" << std::endl;
	}
	
	
	n = argc - 1;
	
	std::cout << "Please switch to your game window...\nStart crafting in..." << std::endl;
	for(int i = DELAY_IN_MS / 1000; i > 0; i--)
	{
		std::cout << i << std::endl;
		Sleep(1000);
	}
	
	while(true)
	{
		std::cout << "Crafting item..." << std::endl;
		
		// Press numpad 0 three times to enter crafting
		press(VK_NUMPAD0);
		Sleep(1000);
		press(VK_NUMPAD0);
		Sleep(1000);
		press(VK_NUMPAD0);
		
		// Wait for the start animation
		Sleep(2000);

		
		for(int i = 0; i < n; i++)
		{
			key = argv[i+1][0];
			std::cout << "Macro #" << i + 1 << ": key " << key << std::endl;
			
			// Press the macro key
			press(key);
			Sleep(WAIT_TIME_IN_MS);
		}
		std::cout << "Finished item" << std::endl;
		
		// Wait for the finish animation
		Sleep(3000);
	}

	return 0;
}
