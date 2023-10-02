#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>

using namespace std;

//function declaration
void welcome();
void login();

void stars();	//prints stars in menus and welcome
void main_menu(char &input);

//function declaration to fill customer data in arrays
void rooms_fill();
void customer_name_fill();
void customer_phone_fill();
void customer_cnic_fill();

//fucntion declaration to output data in file
void rooms_outstream();
void customer_name_outstream();
void customer_phone_outstream();
void customer_cnic_outstream();

//function declaration for program to define what to do
int floor_input();
int room_input();
void add_reservation();
void view_reservation();
void print_data(int floor, int rooms);
void edit_reservation_menu(char &input);
void edit_reservation();
void delete_reservation();

string username, password,saved_username, saved_password;	//for getting username and password from user and checking it

int username_flag, password_flag;	//flags will tell whether the username and passwords are correct

int p_index, u_index;	//username and password indexes in file to check that the entered password belongs to same username

string hotel[30][30];	//hotel rows will be floors and columns will be rooms
string c_names[30][30], c_phone[30][30], c_cnic[30][30];	//customer input data

int main()
{
	//login function call
	login();
	//arrays filling function calls
	rooms_fill();
	customer_name_fill();
	customer_phone_fill();
	customer_cnic_fill();

menu:
	char input;
	system("cls");
	main_menu(input);
	switch (input)
	{
	case '1':
		system("cls");
		add_reservation();
		goto menu;
		break;
	case '2':
		system("cls");
		view_reservation();
		goto menu;
		break;
	case '3':
		system("cls");
		edit_reservation();
		goto menu;
		break;
	case '4':
		system("cls");	
		delete_reservation();
		goto menu;
		break;
	case '5':
		system("cls");
		exit(0);
		break;
	default:
		system("cls");
		cout << "\n\n\n\t\t\t\tWRONG INPUT\n\n\n";
		goto menu;
	}
	getch();
	return 0;
}

void stars()
{
	for (int i = 0; i < 120; i++)
	{
		cout << "*";
	}
}

void welcome()
{
	stars();
	cout << "\n";
	cout << setw(73) << " HOTEL RESERVATION SYSTEM";
	cout << "\n\n";
	stars();
	cout << "\n\n";
}

void login()
{
	do 
	{
		ifstream username_file("C:\\Users\\Extreme Sys\\Desktop\\semester project\\saved username.txt");
		ifstream password_file("C:\\Users\\Extreme Sys\\Desktop\\semester project\\saved password.txt");
		//welcome print function call
		welcome();

		cout << "Enter username :\t";
		getline(cin, username);
		cout << "Enter password :\t";
		getline(cin, password);		
		if (username_file.is_open())
		{
			for (int i = 0; getline(username_file, saved_username); i++)
			{
				if (username == saved_username)
				{
					username_flag = 1;
					u_index = i;
					break;
				}
				else
				{
						username_flag = 0;
				}
			}
		}
		username_file.close();
		if (password_file.is_open()) 
		{
			for (int i = 0; getline(password_file, saved_password); i++)
			{
				p_index = i;
				if (password == saved_password&&p_index==u_index)
				{
					password_flag = 1;
					break;
				}
				else
				{
					password_flag = 0;
				}
			}
		}
		password_file.close();
		if (username_flag == 1 && password_flag == 1)
		{
			cout << "LOGGED IN SUCCESSFULLY\n\n";
		}		
		else if(username_flag != 1 || password_flag != 1 || u_index != p_index)
		{
			cout << "You Entered wrong username or password\n\n";
		}		
		getch();
		system("cls");
	} while ((password_flag != 1 || username_flag != 1) && (p_index != u_index));
}

void main_menu(char &input)
{
	stars();
	cout << "\n";
	cout << setw(63) << "MAIN MENU";
	cout << "\n\n";
	stars();
	cout << "\n\n";
	cout << "\t\tPRESS \"1\" TO DO RESERVATION\n\n";
	cout << "\t\tPRESS \"2\" TO CHECK RESERVATION\n\n";
	cout << "\t\tPRESS \"3\" TO EDIT RESERVATION\n\n";
	cout << "\t\tPRESS \"4\" TO DELETE RESERVATION\n\n";
	cout << "\t\tPRESS \"5\" TO EXIT\n\n";
	cout << "\n\n\t\tEnter your choice . . .\t";
	cin >> input;
	
}


//input files for arrays filling


void rooms_fill()
{
	ifstream rooms("C:\\Users\\Extreme Sys\\Desktop\\semester project\\rooms.txt");
	string input;
	if (rooms.is_open()) 
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; rooms >> input; j++)
			{
				if (input != "")
				{
					hotel[i][j] = input;
				}
				else
				{
					break;
				}
			}
		}
		rooms.close();
	}
	else
	{
		cout << "\n\nERROR!!! C:\\Users\\Extreme Sys\\Desktop\\semester project\\rooms.txt FILE NOT FOUND!!!!\n\n";
	}
}

void customer_name_fill()
{
	ifstream customer_name("C:\\Users\\Extreme Sys\\Desktop\\semester project\\customer name.txt");	
	string input;
	if (customer_name.is_open())
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; getline(customer_name, input); j++)
			{
				if (input != "")
				{
					c_names[i][j] = input;
				}
				else
				{
					break;
				}
			}
		}
		customer_name.close();
	}
	else
	{
		cout << "\n\nERROR!!! C:\\Users\\Extreme Sys\\Desktop\\semester project\\customer name.txt FILE NOT FOUND!!!!\n\n";
	}
}

void customer_phone_fill()
{
	ifstream customer_phone("C:\\Users\\Extreme Sys\\Desktop\\semester project\\customer phone.txt");
	string input;
	if (customer_phone.is_open()) 
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; getline(customer_phone, input); j++)
			{
				if (input != "")
				{
					c_phone[i][j] = input;
				}
				else
				{
					break;
				}
			}
		}
		customer_phone.close();
	}
	else
	{
		cout << "\n\nERROR!!! C:\\Users\\Extreme Sys\\Desktop\\semester project\\customer phone.txt FILE NOT FOUND!!!!\n\n";
	}
}

void customer_cnic_fill()
{
	ifstream customer_cnic("C:\\Users\\Extreme Sys\\Desktop\\semester project\\customer cnic.txt");
	string input;
	if (customer_cnic.is_open()) 
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; getline(customer_cnic, input); j++)
			{
				if (input != "")
				{
					c_cnic[i][j] = input;
				}
				else
				{
					break;
				}
			}
		}
		customer_cnic.close();
	}
	else
	{
		cout << "\n\nERROR!!! C:\\Users\\Extreme Sys\\Desktop\\semester project\\customer cnic.txt FILE NOT FOUND!!!!\n\n";
	}
}

//******************************************************************************* End of input files *******************************************************************************

// User File output
void rooms_outstream()
{
	ofstream rooms("C:\\Users\\Extreme Sys\\Desktop\\semester project\\rooms.txt");
	if (rooms.is_open())
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				rooms << hotel[i][j] << endl;
			}
		}
		rooms << endl;
	}
}
void customer_name_outstream()
{
	ofstream customer_name("C:\\Users\\Extreme Sys\\Desktop\\semester project\\customer name.txt");
	if (customer_name.is_open())
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				customer_name << c_names[i][j] << endl;
			}
			customer_name << endl;
		}
		customer_name.close();
	}
}

void customer_phone_outstream()
{
	ofstream customer_phone("C:\\Users\\Extreme Sys\\Desktop\\semester project\\customer phone.txt");
	if (customer_phone.is_open())
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				customer_phone << c_phone[i][j] << endl;;
			}
			customer_phone << endl;
		}
		customer_phone.close();
	}
}

void customer_cnic_outstream()
{
	ofstream customer_cnic("C:\\Users\\Extreme Sys\\Desktop\\semester project\\customer cnic.txt");
	if (customer_cnic.is_open())
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				customer_cnic << c_cnic[i][j] << endl;;
			}
			customer_cnic << endl;
		}
		customer_cnic.close();
	}
}
//******************************************************************************* End of output files *******************************************************************************

int floor_input()
{
	int floor;
	do
	{
		cout << "Enter Floor Number :\t";
		cin >> floor;
		floor = floor - 1;		//if user wants to enter data to ground floor then for array it should be 0 when user enters 1
		if (floor < 0 || floor > 29)
		{
			cout << "\n\nError!!! Wrong input. . .Try Again!!!\n\n";
		}
	} while (floor < 0 || floor > 29);
	return floor;
}

int room_input()
{
	int room;
	do
	{
		cout << "Enter Room Number :\t";
		cin >> room;
		room = room - 1;	//if user wants to enter data to ground room then for array it should be 0 when user enters 1
		if (room < 0 || room > 29)
		{
			cout << "\n\nError!!! Wrong input. . .Try Again!!!\n\n";
		}
	} while (room < 0 || room > 29);
	return room;
}

void add_reservation()
{
	int floor, room;
	bool check = false;
	do 
	{
		floor = floor_input();
		room = room_input();
		if (hotel[floor][room] == "0")
		{
			cin.ignore();
			cout << "\n\n\nEnter Customer Name :\t";
			getline(cin, c_names[floor][room]);
			cout << "Enter Customer Phone No :\t";
			getline(cin, c_phone[floor][room]);
			cout << "Enter Customer CNIC :\t";
			getline(cin, c_cnic[floor][room]);
			cout << "\n\n\nEntered data is . . .\n\n";
			print_data(floor, room);
			cout << "\n\nData Saved successfully . . .\n";
			cout << "Press any key to return main menu . . .\n";
			getch();
			hotel[floor][room] = "X";
			rooms_outstream();
			customer_name_outstream();
			customer_phone_outstream();
			customer_cnic_outstream();
			check = true;
		}
		else
		{
			cout << "\n\nThe Room is already reserved\n\n";
		}
	} while (check != true);
}

void view_reservation()
{
	int floor, room;
	floor = floor_input();
	room = room_input();
	if (hotel[floor][room] == "0")
	{
		cout << "\n\n\nThe room is not reserved\n\n";
		cout << "Press any key to return main menu . . .\n";
		getch();
	}
	else
	{
		print_data(floor, room);
		cout << "Press any key to return main menu . . .\n";
		getch();
	}
}

void edit_reservation_menu(char &input)
{
	cout << "\n\n";
	cout << "\t\tPRESS \"1\" To change customer name\n\n";
	cout << "\t\tPRESS \"2\" To change customer phone no\n\n";
	cout << "\t\tPRESS \"3\" To change customer CNIC no\n\n";
	cout << "\t\tPRESS \"4\" TO change all customer data\n\n";
	cout << "\n\n\t\tEnter your choice . . .\t";
	cin >> input;
}

void edit_reservation()
{
menu:
	stars();
	cout << "\n";
	cout << setw(63) << "EDIT RESERVATION MENU";
	cout << "\n\n";
	stars();
	int floor = floor_input();
	int room = room_input();
	char input;
	if (hotel[floor][room] == "X")
	{

		cout << "\n\n";
		cout << "OLDER DATA IS . . .\n\n";
		print_data(floor, room);
		edit_reservation_menu(input);
		cin.ignore();
		switch (input)
		{
		case '1':
			cout << "Enter customer name to change :\t";
			getline(cin, c_names[floor][room]);
			break;
		case '2':
			cout << "Enter customer phone no to change :\t";
			getline(cin, c_phone[floor][room]);
			break;
		case '3':
			cout << "Enter customer CNIC to change :\t";
			getline(cin, c_cnic[floor][room]);
			break;
		case '4':
			cout << "Enter customer name to change :\t";
			getline(cin, c_names[floor][room]);
			cout << "Enter customer phone no to change :\t";
			getline(cin, c_phone[floor][room]);
			cout << "Enter customer CNIC to change :\t";
			getline(cin, c_cnic[floor][room]);
			break;
		default:
			cout << "Wrong Input Enter Again . . .\n\n";
			getch();
			system("cls");
			goto menu;
		}
		customer_name_outstream();
		customer_phone_outstream();
		customer_cnic_outstream();
		cout << "\n\nDATA UPDATED SUCCESSFULLY\n";
	}
	else
	{
		cout << "\n\nThe room is not reserved . . .\n\n";
	}
	cout << "\n\nPress any key to return main menu . . .\n";
	getch();
}

void delete_reservation()
{
	int floor = floor_input();
	int room = room_input();
	char input;

	if (hotel[floor][room] == "X")
	{
		print_data(floor, room);
		do
		{
			cout << "\n\nAre you sure you want to delete data [Y/n] . . .\t";
			cin >> input;
			if (input == 'y' || input == 'Y')
			{
				hotel[floor][room] = "0";
				c_names[floor][room] = "0";
				c_phone[floor][room] = "0";
				c_cnic[floor][room] = "0";
				rooms_outstream();
				customer_name_outstream();
				customer_phone_outstream();
				customer_cnic_outstream();
				cout << "\n\nDATA ERASED SUCCESSFULLY . . .\n\n";
			}
			else if (input == 'n' || input == 'N')
			{
				cout << "\n\nDATA NOT ERASED . . .\n\n";
			}
			else
			{
				cout << "ERROR!!! Wrong Input . . .Try Again . . .\n\n";
			}
		} while (input != 'y' && input != 'Y' && input != 'n' && input != 'N');
		cout << "\n\nPress any key to return main menu . . .\n";
		getch();
	}
	else
	{
		cout << "\n\nThe Room is not reserved\n\n";
		cout << "\n\nPress any key to return main menu . . .\n";
		getch();
	}
}

void print_data(int floor,int room)
{
	cout << "Customer name :\t" << c_names[floor][room] << endl;
	cout << "Customer Phone :\t" << c_phone[floor][room] << endl;
	cout << "Customer CNIC :\t" << c_cnic[floor][room] << endl;
}
