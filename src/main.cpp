#include <iostream>
#include <chrono>
#include <ncurses.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
using namespace std::chrono;
#ifdef Windows_NT
#define CLS "cls"
#else
#define CLS "clear"
#endif
char getChar()
{
	initscr(); 
    cbreak(); 
    noecho(); 

    char ch = getch(); 

    endwin();
	return ch;
}

int main(int argc, char* argv[]){
	vector<string> stations = {};
	system(CLS);
	ifstream In;
	In.open("stations.cmt");
	if(In)
	{
		string RawInput = "", curStat = "";
		getline(In, RawInput);
		stations.clear();
		for(int i = 0; i < RawInput.length(); i++)
		{
				if(RawInput[i] == ';')
				{
						stations.push_back(curStat);
						curStat = "";
				}
				else{curStat += RawInput[i];}
		}
		cout << "size of stations vector : " << stations.size() << "\n\n"; 
	}
	int startsta = 0;
	string welcome = "";
	for(int i = 0; i < stations.size(); i++){
		int sortnum = i + 1;
		welcome += to_string(sortnum) + ". " + stations[i] + "  ";	
	}
	cout << welcome << "\n\n";
	string numtxt = ""; 
	cin >> startsta;
	startsta -= 1;
	system(CLS);
	cout << "will you go towards right(-->)? (Y/n)\n";
	cin >> welcome;
	bool reversed = false;
	if(welcome == "N" || welcome == "n"){reversed = true;}
	system(CLS);
	for(int i = startsta; i < stations.size() && !reversed; i++)
	{
		bool pause = false;
		auto strt = steady_clock::now();
		char option = getChar();
		
		if(option == 't'){pause = true;}
		
		auto end = steady_clock::now();
		auto duration = duration_cast<seconds>(end - strt).count();
		cout << stations[i] << "  " << duration << " sn.\n";
		if(pause){getChar();}
	}
	for(int i = startsta; i >= 0 && reversed; i--)
	{
		bool pause = false;
		auto strt = steady_clock::now();
		char option = getChar();
		if(option == 't'){pause = true;}
		
		auto end = steady_clock::now();
		auto duration = duration_cast<seconds>(end - strt).count();
		cout << stations[i] << "  " << duration << " sn.\n";
		if(pause){getChar();}
	}
	endwin();
	return 0;
}
