# About AutoCraft

AutoCraft is a crafting script for Final Fantasy XIV(FF14). It simulate the key pressing events.
The key specified by the user in the command line should be set to in-game macros, which are crafting macros.
The delay between two macros is set to 40 seconds.
	
Instruction:  
	To Compile  
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

## Will I get banned if I use this?
According to Yoshida, bot will be punished. However, if the player is in front of the computer and is able to control your character at anytime, the player won't get banned. That is, if you use this script to craft while you are playing your phone in front of the computer, you are safe. If you get reported in the game, the GM will PM you and you will only get banned if you can't reply the PM.
More on this: https://noshilog.com/ff14-crafter-mouse-keyboard-macro (in Japanese)
