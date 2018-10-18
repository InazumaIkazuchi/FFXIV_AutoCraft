#include <iostream>
#include <cstdlib>
#include <windows.h>

#define MAX_SIZE 5
#define DELAY_IN_MS 5000
#define WAIT_TIME_IN_MS 40000

char key;
int n;

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
	if(argc <= 1)
	{
		std::cout << "Invalid Input.\n\tUsage: ./AutoCraft.exe <macro keys>" << std::endl;
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
		std::cout << "Crafting Item..." << std::endl;
		for(int i = 0; i < n; i++)
		{
			std::cout << "Macro # " << i + 1 << std::endl;
			key = argv[i+1][0];
			press(key);
			Sleep(WAIT_TIME_IN_MS);
		}
		std::cout << "Finished Item" << std::endl;
	}

	return 0;
}
