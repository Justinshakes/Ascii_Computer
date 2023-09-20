/*
Course: COMP 150
Last Name: Sherrell
First Name: Justin

File:  Computer_Simulation_SherrellJ.cpp
Summary: A somewhat-functioning computer that can draw ascii, play music (not really) and write and save notes to a txt file.
*/
#include <fstream>	// working with files
#include <iostream> 
#include <string>	// get string
#include <windows.h> // windows time function 
#include <unistd.h> // Unix  time function  --> unsigned sleep(unsigned seconds);
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
fstream myfile;
void print(int x);
void ascii_Menu();
void notes();
void music_Player();
int main_menu();

int check[9] = {0,0,0,0,0,0,0,0,0};
bool Notes_first = true,music_first = true;

int main()
{
	srand (time(NULL));
 	int choice;
 	
 	do{
 		choice = main_menu();
	 	switch(choice) 
				{
				case 1:
					notes();		  		
					continue;					
				case 2:
					music_Player();				    
					continue;					
				case 3:
					ascii_Menu();
					continue;	
				case 4:
				cout<<"\nShuting Down ....";				    
				break;
				}
		}while(choice != 4);
 	
 	
}



void print(int x)
{								// 0                          1                    2                3                 4                      5
	string txt_Files[15]={"txt/menu/MainMenu.txt","txt/menu/asciiMenu.txt","txt/art/cat.txt","txt/art/dog.txt","txt/art/bunny.txt","txt/menu/notesMenu.txt",
	          //6                   7					8						9					10						11					12 						13					14
	"txt/music/song1.txt","txt/music/song2.txt","txt/music/song3.txt","txt/music/song4.txt","txt/music/song5.txt","txt/music/song6.txt","txt/music/song7.txt","txt/music/song8.txt","txt/music/song9.txt"};
	

	
	

	myfile.open(txt_Files[x].c_str()); // The c_str() makes it posible for myfile.open to read the file name.
	if(myfile.is_open()) // checks if file is open
	{
		string line; 
		while (getline(myfile,line)) // line will fail at end of txt file
		{
			Sleep(80); // sleeps the program 
			cout<<line<<endl; // output current line
		}
		myfile.close(); // closes file
	}
}

int main_menu()
{
	int choice;
  	print(0);
	do
		{
			cout<<"\nPlease Select From The List: ";
			cin>>choice;
			if(choice >4 || choice <1)
			{
				Sleep(300);
				cout<<"Invalid Input Please Try Again \n";
				Sleep(300);
			}
			
		}while(choice >4 || choice <1);
		return choice;
}

void ascii_Menu()
{
	int R;
	print(1);
	int choice;
	  do
	   {
		  do
		  {
			  cout<<"\n Please Select From The List: ";
			  cin>>choice;
			  if(choice >5 || choice <1)
			{	
				Sleep(300);
				cout<<"Invalid Input Please Try Again \n";
				Sleep(300);
			}
		  }while(choice >5 || choice <1);
		  
		  switch(choice) 
		  {
		  	case 1:
		  		print(2); // cat
			    continue;
		  	case 2:
		  		
			    print(3); // dog
			    continue;
			case 3:
			    print(4); // bunny
			    continue;
			case 4:
				R = rand() % 3 + 2; // between 2 - 4
				print(R);		// random
			    continue;
			case 5:;
			}
		}while(choice !=5);
}

void notes()
{
	string entered_data;
	fstream myFile;
	int choice;
	
	if (Notes_first == true)
	{
		print(5);
		cout<<"\n[Type ! to close notes]\n\n";
		myFile.open("notes.txt",ios::out); // write
		if(myFile.is_open())
		{
	  		getline (cin,entered_data, '!');// '!' deliminators
	  		myFile << entered_data;
			myFile.close();
		}
		Notes_first = false;
	}
	do
	{
		cout<<"[1] Add To Notes [2] Read Notes [3] Main Menu\n";
		cin>>choice;
		switch(choice) 
		{
		  	case 1:
		  		cout<<"[Type ! to close notes]\n\n";
				myFile.open("notes.txt",ios::app); // append to file aka: add to file 
				if(myFile.is_open())
				{
					getline (cin,entered_data, '!');
		  			myFile << entered_data;
					myFile.close();
				}
		    	continue;
		    	
		  	case 2:
		  		print(5);
		    	myFile.open("notes.txt", ios::in); // read
				if(myFile.is_open())
				{
					string line;
				while (getline(myFile,line)) //line will fail at end of txt file
				{
					cout<<line<<endl;
				}
					myFile.close();
				}
		    continue;
		  	case 3:
		    break;
		}
	}while(choice != 3);
}

void music_Player()
{	
	string song_Names[9] = {"Moves Like Jagger ","Californication ","The Real Slim Shady ","Beautiful Day ","Boulevard Of Broken Dreams ","I Want It That Way "," Despacito ","See You Again ","Sunflower  "};
	string artist_names[9] = {"Maroon 5 "," Red Hot Chili Peppers ","Eminem ","U2 ","Green Day ","Backstreet Boys ","Luis Fonsi","Wiz Khalifa  ft. Charlie Puth","Post Malone, Swae Lee "};
	
	fstream myFile;
	int choice,current_song = 0,prev_song;
	
		if (music_first == true)
		{
			myFile.open("Songs_Output.txt",ios::out); // write
			if(myFile.is_open())
			{	
		  		myFile << "   _____Favorite Songs_____ \n\n";
				myFile.close();
			}
		}
		music_first = false;
		print(current_song + 6);
	do 
	{	
		do{
			cout<<"\n Please Select From The List: ";
			cin>>choice;
			if(choice >4 || choice <1)
			{
				Sleep(300);
				cout<<"\n\n  Invalid Input Please Try Again \n\n";
				Sleep(300);
			}
			}while(choice >4 || choice <1);
		
		switch(choice) 
			{
			  	case 1: // next song
				current_song += 1;
			  	if(current_song == 9)
				  	{
				  		current_song = 0;
				  	}
				print(current_song + 6);
				continue;
			    	
			  	case 2: // random song
			  		prev_song = current_song; // so we don't get the same song twice
			  		do
					  	{
					  		current_song = rand() % 9; // 0 - 8
						}while(current_song == prev_song);
			  		print(current_song + 6);	
			  		continue;
			  	case 3: // favorite song
			  	if(check[current_song] == 1)
			  	{
			  		cout<<"That Song Is Already Favorited\n";
			  		continue;
				  }
			  	check[current_song] = 1;
			  	myFile.open("Songs_Output.txt",ios::app);
				if(myFile.is_open())
				{
		  			myFile<<"Song: " << song_Names[current_song] << endl;
		  			myFile<<"Artist: " << artist_names[current_song] << "\n\n";
					myFile.close();
				}
				cout<<"Song Favorited"<<endl;
		    	continue;
		    	
		    	case 4:;
			}
		}while(choice != 4);
}

