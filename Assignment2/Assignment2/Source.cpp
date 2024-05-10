#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
void signup();
void login();
void fillarray(string array[10][11], string file);
void Bookroom(string array[10][11], string time[11], string file, string text, string random, string uname, string choice);
string checkroom(string array[10][11], string time[11],string &choice);
void mainpage(string random);
void registration(string uname, string user[5][1000], string pass, string name, string phone, string identification, int turn,string random);
void readtext(string user[5][1000], string uname, string pass, string name, string phone, string identification, int & turn, string random);
void checkuserroom(string uname, string file,string random);
void unbooking(string uname, string random,string array[10][11],string time[11] ,string file, string dayname);


int main() {
	string number = "0";
	while (number != "4") {

		string user[5][1000];
		string time[11] = { "11a.m.-12p.m.","12p.m.-1p.m.","1p.m.-2p.m.","2p.m.-3p.m.","3p.m.-4p.m.","4p.m.-5p.m.","5p.m.-6p.m.","6p.m.-7p.m.","7p.m.-8p.m.","8p.m.-9p.m.","9p.m.-10p.m." };
		string choice;
		string Tuesday[10][11];
		string Wednesday[10][11];
		string Thursday[10][11];
		string Friday[10][11];
		string Saturday[10][11];
		string Sunday[10][11];
		string name, uname, pass, phone, identification, random, day;
		int turn = 0;
		//Fill days array from text file
		fillarray(Tuesday, "Tuesday.txt");
		fillarray(Wednesday, "Wednesday.txt");
		fillarray(Thursday, "Thursday.txt");
		fillarray(Friday, "Friday.txt");
		fillarray(Saturday, "Saturday.txt");
		fillarray(Sunday, "Sunday.txt");
		//Fill user array from text file 
		readtext(user, uname, pass, name, phone,identification, turn, random);
		cout << "                           Welcome to JJS Karakoke      3.Log In |2.Sign Up" << endl;
		cout << "   __    ________________________________________________________" << endl;
		cout << "  /  \\  |          ______             ______     ______________  |" << endl;
		cout << "  \\__/  |         |      |           |      |   |              | |" << endl;
		cout << "  |  |  |         |      |           |      |   |              | |" << endl;
		cout << "  |__|  |         |      |           |      |   |      ________| |" << endl;
		cout << "  |__|  |         |      |           |      |   |     |________  |" << endl;
		cout << "   ||   |         |      |           |      |   |              | |" << endl;
		cout << "___/    |  _______|      |    ______ |      |   |              | |" << endl;
		cout << "        | |      ||      |   |      ||      |   |__________    | |" << endl;
		cout << "        | |      ||      |   |      ||      |    __________|   | |" << endl;
		cout << "        | |              |   |              |   |              | |" << endl;
		cout << "        | |              |   |              |   |              | |" << endl;
		cout << "        | |______________|   |______________|   |______________| |" << endl;
		cout << "        |________________________________________________________|" << endl << endl;
		cout << "                         1.JJS karaoke Main page              " << endl;
		cout << " Want to know anything about us? Pay a visit to our main web page and we" << endl;
		cout << "             will tell you everything you want to know." << endl << endl << endl << endl;
		cout << "                                4.Exit" << endl << endl << "Please select the number options:";
		cin >> number;

		//Display main webpage
		if (number == "1") {
			mainpage(random);
		}
		//Registration Process
		else if (number == "2") {
			registration(uname,user,pass, name,phone,identification,turn,random);

		}//Log in
		else if (number == "3") {
			system("cls");
			cin.ignore();
			while (number == "3") {
				login();
				cout << "Username:";
				getline(cin, uname);
				int i;
				//check whether the username enter by the user existed or not 
				for (i = 0; i <= turn; i++) {
					//prevent user put ENTER input to bypass the username login
					if (uname == "") {
						system("cls");
						login();
						cout << " Username doesn't exist." << endl;
						cout << " Username:";
						getline(cin, uname);
						i = -1;
					}
					//If username enter by user is in the system,skip to log in password
					else if (user[0][i] == uname) {
						break;
					}
					//If user enter exit,skip login username
					else if  (uname == "Exit") {
						break;
					}
					//If user enter Account Recovery,allow user to input their information and get back their accont information
					else if (uname == "Account Recovery") {
						system("cls");
							cout << "Account Recovery"<<endl <<endl;
							cout << "Enter your information and we will help you to find your account."<< endl << endl;
							cout << "Type in your real name:";
							getline(cin, name);

							cout << endl<< "Type in your mobile phone number:";
		

							getline(cin, phone);

							cout << endl<<"Type in your Identification number(IC):";
	

							getline(cin, identification);

						for (int x = 0; x <= turn; x++) {
							if (user[2][x] == name && user[3][x] == phone && user[4][x] == identification) {
								cout << endl <<"Your username is " << user[0][x] << endl;
								cout << "Your password is " << user[1][x] << endl;
								cout << "Enter any key to continue.";
								cin >> random;
								system("cls");
								login();
								cout << "Username:";
								cin.ignore();
								getline(cin, uname);
								i = -1;
								break;
								

							}
							//If the system did not detect any accont have these information,display wrong entered information
							else if (x == turn) {
								cout << "Your entered information is wrong." <<endl;
								cout << "Enter any key to continue.";
								cin >> random;
								system("cls");
								login();
								cout << "Username:";
								cin.ignore();
								getline(cin, uname);
								i = -1;
								
								
							
							}

						}
					}
					//If system read all of the username in the system and didnt find the username enter by user in the system,display username doens't exit.
					else if (i == turn) {	
						system("cls");
						login();
						cout << " Username doesn't exist." << endl;
						cout << " Username:";
						getline(cin, uname);
						i = -1;
					}

				}
				//If user enter exit,exit the login process
				if (uname == "Exit") {
					system("cls");
					break;
				}

				//Login password
				cout << "Enter your password:";
				getline(cin, pass);
				//If password enter by user is correct with the username
				if (user[1][i] == pass) {
					string option = "0";
					//Login successful
					while (option != "4") {
						system("cls");
						//Choices
						cout << "                    JJS Karaoke                               " << uname << "|4.Logout" <<endl;
						cout << "         ______             ______     ______________" << endl;
						cout << "        |      |           |      |   |              |" << endl;
						cout << "        |      |           |      |   |              |" << endl;
						cout << "        |      |           |      |   |      ________|" << endl;
						cout << "        |      |           |      |   |     |________" << endl;
						cout << "        |      |           |      |   |              |" << endl;
						cout << " _______|      |    ______ |      |   |              |" << endl;
						cout << "|      ||      |   |      ||      |   |__________    |" << endl;
						cout << "|      ||      |   |      ||      |    __________|   |" << endl;
						cout << "|              |   |              |   |              |" << endl;
						cout << "|              |   |              |   |              |" << endl;
						cout << "|______________|   |______________|   |______________|" << endl << endl;
						cout << "1.Book a room" << endl << "2.Unbooking" << endl << "3.Account info" << endl << endl;
						cout << "Please select your option by number:";
						cin >> option;
						cin.ignore();
						//Booking
						if (option == "1") {
							system("cls");
							cout << "Do you want to book a room at which day?" << endl << "1.Tuesday" << endl << "2.Wednesday" << endl << "3.Thursday" << endl << "4.Friday" << endl << "5.Saturday" << endl << "6.Sunday" << endl << endl << "Select your choices by number:";
							//choose whichday to book
							string whichday;
							cin >> whichday;
							cin.ignore();
							while (option == "1") {
								//Tuesday
								if (whichday == "1") {
									//check room on tuesday
									checkroom(Tuesday, time,choice); 
									//if user decide to cancel the booking process,skip the bookin
									if (choice == "N") {
										break;
									}
									//Booking process
									Bookroom(Tuesday, time, "Tuesday.txt", "Tuesday", random, uname, choice);
									break;

								}//Tuesday
								else if (whichday == "2") {
									//check room on Wednesday
									checkroom(Wednesday, time,choice);
									//if user decide to cancel the booking process,skip the bookin
									if (choice == "N") {
										break;
									}
									//Booking process
									Bookroom(Wednesday, time, "Wednesday.txt", "Wednesday", random, uname, choice);
									break;
								}
								else if (whichday == "3") {
									//check room on Thursday
									checkroom(Thursday, time,choice);
									//if user decide to cancel the booking process,skip the bookin
									if (choice == "N") {
										break;
									}
									//Booking process
									Bookroom(Thursday, time, "Thursday.txt", "Thursday", random, uname, choice);
									break;
								}

								else if (whichday == "4") {
									//check room on Friday
									checkroom(Friday, time,choice);
									//if user decide to cancel the booking process,skip the bookin
									if (choice == "N") {
										break;
									}
									//Booking process
									Bookroom(Friday, time, "Friday.txt", "Friday", random, uname, choice);
									break;
								}

								else if (whichday == "5") {
									//check room on Saturday
									checkroom(Saturday, time,choice);
									//if user decide to cancel the booking process,skip the bookin
									if (choice == "N") {
										break;
									}
									//Booking process
									Bookroom(Saturday, time, "Saturday.txt", "Saturday", random, uname, choice);
									break;
								}
								else if (whichday == "6") {
									//check room on Sunday
									checkroom(Sunday, time,choice);
									//if user decide to cancel the booking process,skip the bookin
									if (choice == "N") {
										break;
									}
									//Booking process
									Bookroom(Sunday, time, "Sunday.txt", "Sunday", random, uname, choice);
									break;
								}//if user enter invalid day,display please enter a correct day
								else {
									cout << "Please enter a correct day by number:";
									cin >> whichday;


								}


							}

						}
						else if (option == "2") {
							//Check user booking in every day
							system("cls");
							checkuserroom(uname, "Tuesday.txt", random);
							checkuserroom(uname, "Wednesday.txt", random);
							checkuserroom(uname, "Thursday.txt", random);
							checkuserroom(uname, "Friday.txt", random);
							checkuserroom(uname, "Saturday.txt", random);
							checkuserroom(uname, "Sunday.txt", random);
							cout << "1.Tuesday" << endl;
							cout << "2.Wednesday" << endl;
							cout << "3.Thursday" << endl;
							cout << "4.Friday" << endl;
							cout << "5.Saturday" << endl;
							cout << "6.Sunday" << endl;
							cout << "Do you want to cancel which day of booking？:";
							string day;
							cin >> day;
							//Unbooking day
							if (day == "1") {
								unbooking(uname, random, Tuesday, time, "Tuesday.txt", "Tuesday");


							}
							else if (day == "2") {
								unbooking(uname, random,Wednesday, time, "Wednesday.txt", "Wednesday");

							}
							else if (day == "3") {
								unbooking(uname, random, Thursday, time, "Thursday.txt", "Thursday");

							}
							else if (day == "4") {
								unbooking(uname, random, Friday, time, "Friday.txt", "Friday");
							}
							else if (day == "5") {
								unbooking(uname, random, Saturday, time, "Saturday", "Saturday");
							}
							else if (day == "6") {
								unbooking(uname, random,Sunday, time, "Sunday.txt", "Sunday");

							}
							else {
								cout << "Press enter valid input" << endl;
								cout << "Enter any key to continue" << endl;
								cin >> random;
							}
						}
						else if (option == "3") {
						system("cls");
						int y;
						//find username in user
						for (y = 0; y <= turn; y++) {
							if (user[0][y] == uname) {
								break;
							}


						}
						cout << "Username:" << user[0][y] << endl;
						cout << "Password:" << user[1][y] << endl;
						cout << "Your name:" << user[2][y] << endl;
						cout << "Your mobile phone number" << user[3][y] << endl;
						cout << "Your identification number" << user[4][y] << endl;
						cout << "Your booking order:" << endl;
						checkuserroom(uname, "Tuesday.txt", random);
						checkuserroom(uname, "Wednesday.txt", random);
						checkuserroom(uname, "Thursday.txt", random);
						checkuserroom(uname, "Friday.txt", random);
						checkuserroom(uname, "Saturday.txt", random);
						checkuserroom(uname, "Sunday.txt", random);
						cout << " Enter any key to continue";
						cin >> random;

						
}
						else if (option == "4") {
							system("cls");
							break;
						}
						//If user enter invalid option,display invalid input
						else {
							system("cls");
							cout << "Invalid Input" << endl;
						}

					}
				}
				//If user enter wrong password,display wrong password
				else if (user[1][i] != pass) {
					system("cls");	
					cout << "Wrong Password!" << endl << "Please enter your username and password again." << endl;
				}

			}
		}
		//Exit program
		else if (number =="4"){
		system("cls");
		cout << "Program exited" <<endl;
}
        //If user enter invalid option,display please enter a valid option
		else{
		system("cls");
		cout << "PLease enter a valid option" <<endl;
}
	}
	system("pause");
	return 0;
}

								
void fillarray(string array[10][11], string file) {
	ifstream fill;
	string time;
	string day;
	string book;
	string room;
	//open file
	fill.open(file);
	//read which day is it in the file
	getline(fill, day);
	//read 10 rooms
	for (int i = 0; i <= 9; i++) {
		getline(fill, room);
		//read 11 hours
		for (int j = 0; j <= 10; j++) {
			getline(fill, time);
			//Booking information of the room
			getline(fill, book);
			array[i][j] = book;
		}

	}
		

}

void Bookroom(string array[10][11], string time[11], string file, string text, string random, string uname ,string choice) {
	ofstream updatefile;
	cout << endl << "Which room do you want to book:";
	int room;
	cin >> room;
	//Only allow room 1-10
	while (10 < room || room <= 0) {
		system("cls");
		cout << "We have only TEN room." << endl;
		cout << "Enter any key to continue." << endl;
		cin >> random;
		checkroom(array, time, choice);
		if (choice == "N") {
			return;
		}
		cout << "Please select room 1-10:";
		cin >> room;

	}
	cout << "For example ,if you would like to book 3p.m.-4p.m.,type 15 first" <<endl;
	cout << "From what time would you like to book a room:";
	int time1, time2, time3 = 0;
	cin >> time1;
	cout << "For example ,if you would like to book 3p.m.-4p.m.,type 16 second"<<endl;
	cout << "At what time would you like to book the room until:";
	cin >> time2;
	// Only allow time from 1100-2200
	while (21 < time1 || time1 < 11 || 22 < time2 || time2 < 12) {
		system("cls");
		cout << " We only operate from 1100-2200." << endl;
		cout << "Enter any key to continue." << endl;
		cin >> random;
		checkroom(array, time, choice);
		if (choice == "N") {
			return;
		}
		cout << "You have choose Room " << room + 1 << "." << endl;
		cout << "For example ,if you would like to book 3p.m.-4p.m.,type '15' first" <<endl;
		cout << "From what time would you like to book a room:";
		cin >> time1;
		cout << "For example ,if you would like to book 3p.m.-4p.m.,type '16' second" <<endl;
		cout << "At what time would you like to book the room until:";
		cin >> time2;

	}
	//change the format of time so it can apply to array
	time3 = time1;
	time1 = time1 - 11;
	time2 = time2 - 12;
	for (time1; time1 <= time2; time1++) {
		//If a room is filled
		if (array[room - 1][time1] != "OK") {
			system("cls");
			cout << "Please choose another time,someone has book the room in your chosen time." << endl;
			cout << "Enter any key to continue." << endl;
			cin >> random;
			checkroom(array, time, choice);
			if (choice == "N") {
				return;
			}
			cout << "Which room do you want to book:";
			cin >> room;
			//Only allow room 1-10
			while (10 < room || room <= 0) {
				system("cls");
				cout << "We have only TEN room." << endl;
				cout << "Enter any key to continue." << endl;
				cin >> random;
				checkroom(array, time, choice);
				if (choice == "N") {
					return;
				}
				cout << "Please select room 1-10:";
				cin >> room;

			}
			cout << "For example ,if you would like to book 3p.m.-4p.m.,type '15' first"<<endl;
			cout << "From what time would you like to book a room:";
			cin >> time1;
			cout << "For example ,if you would like to book 3p.m.-4p.m.,type '16' second"<<endl;
			cout << "At what time would you like to book the room until:";
			cin >> time2;
			//Only allow user key in 1100-2200
			while (21 < time1 || time1 < 11 || 22 < time2 || time2 < 12) {
				system("cls");
				cout << " We only operate from 1100-2200." << endl;
				cout << "Enter any key to continue." << endl;
				cin >> random;
				checkroom(array, time, choice);
				if (choice == "N") {
					return;
				}
				cout << "You have choose Room " << room + 1 << "." << endl;
				cout << "For example ,if you would like to book 3p.m.-4p.m.,type '15' first"<<endl;
				cout << "From what time would you like to book a room:";
				cin >> time1;
				cout << "For example ,if you would like to book 3p.m.-4p.m.,type '16' second"<<endl;
				cout << "At what time would you like to book the room until:";
				cin >> time2;
			
			}
			//change the format of time so it can apply to the array
			time3 = time1;
			time1 = time1 - 12;
			time2 = time2 - 12;


		}
	}
	//Confirm booking
	string booking;
	cout << text << "(" << time1 + 10 << "00-" << time2 + 12 << "00)" << "Room" << room << endl;
	cout << "Do you want to confirm your booking?(Y/N):" <<endl;
	cin >> booking;
	//If no,cancel booking
	if (booking == "N") {
		system("cls");
		updatefile.close();
		return;
	}
	time1 = time3;
	time3 = time3 - 11;
	//Enter booking information into the array
	for (time3; time3 <= time2; time3++) {
		array[room - 1][time3] = uname;


	}
	//Enter booking information into the text file
	updatefile.open(file);
	updatefile << text << endl;
	for (int i = 0; i <= 9; i++) {
		updatefile << "Room" << i + 1 << endl;
		for (int j = 0; j <= 10; j++) {
			updatefile << time[j] << '\n' << array[i][j] << endl;

		}
	}
	updatefile.close();

	cout << "Book Succesfully!" << text <<"(" << time1 << "00-" << time2 + 12 << "00)" << "Room" << room << endl << "Press any key to continue";
	cin >> random;
}

string checkroom(string array[10][11], string time[11],string &choice) {
	//Display all of the room information
	//Room information
	for (int i = 0; i <= 9; i++) {
		cout << "Room" << i + 1 << endl;
		//Room information at different hours
		for (int j = 0; j <= 10; j++) {
			cout << time[j] << ":";
			cout << array[i][j] << endl;


		}

	}
	cout << " Do you wish to continue the booking process?(Y/N):";
	cin >> choice;
	while (choice != "Y" && choice != "N") {
		cout << "Press enter a valid option:";
		cin >> choice;
		}
	return choice;

}

void mainpage(string random) {
	//All the information of the karaoke
	system("cls");
	cout << "         ______             ______     ______________" << endl;
	cout << "        |      |           |      |   |              |" << endl;
	cout << "        |      |           |      |   |              |" << endl;
	cout << "        |      |           |      |   |      ________|" << endl;
	cout << "        |      |           |      |   |     |________" << endl;
	cout << "        |      |           |      |   |              |" << endl;
	cout << " _______|      |    ______ |      |   |              |" << endl;
	cout << "|      ||      |   |      ||      |   |__________    |" << endl;
	cout << "|      ||      |   |      ||      |    __________|   |" << endl;
	cout << "|              |   |              |   |              |" << endl;
	cout << "|              |   |              |   |              |" << endl;
	cout << "|______________|   |______________|   |______________|" << endl << endl;

	cout << "Welcome to the JJS Karaoke Webpage!!!" << endl << "We are the JJS Karaoke and we are dedicated to give our customer the best singing experience!" << endl << "We welcome all of you to visit our outlet." << endl << endl << endl;

	cout << "            _________               " << endl;
	cout << "           /         \\              " << endl;
	cout << "          /___________\\             " << endl;
	cout << "          |           |             " << endl;
	cout << "          |           |             " << endl;
	cout << "           \\_________/              " << endl;
	cout << "           |_________|              " << endl;
	cout << "             |     |                " << endl;
	cout << "             |     |                " << endl;
	cout << "             |  _  |                " << endl;
	cout << "             | |_| |                " << endl;
	cout << "             |     |                " << endl;
	cout << "             |_____|         ___    " << endl;
	cout << "              |___|        /     \\  " << endl;
	cout << "                |        /        \\ " << endl;
	cout << "                |       /           " << endl;
	cout << "                \\______/             " << endl << endl << endl;

	cout << "Our outlet is at Kampar!Come visit us when you are free~" << endl << endl;
	cout << "        Operation hours:11 A.M.- 10 P.M." << endl;
	cout << "                 Monday:OFF                      " << endl;
	cout << "                Tuesday:ON                       " << endl;
	cout << "              Wednesday:ON                      " << endl;
	cout << "               Thursday:ON                       " << endl;
	cout << "                 Friday:ON                       " << endl;
	cout << "               Saturday:ON                       " << endl;
	cout << "                 Sunday:ON                      " << endl << endl << endl;
	cout << "          _______________________________          " << endl;
	cout << "         /  Want to know more about us?  \\         " << endl;
	cout << "        /            Calls us at!         \\        " << endl;
	cout << "       /        _____016123456789____      \\       " << endl;
	cout << "      /        /                     \\      \\      " << endl;
	cout << "     _|________|_                   _|_______|_     " << endl;
	cout << "    |____________|                 |___________|   " << endl;
	cout << "Enter any key to continue";
	cin >> random;
	system("cls");
}

void registration(string uname,string user[5][1000],string pass,string name,string phone,string identification,int turn,string random) {
	        ofstream outuserfile;
	        outuserfile.open("User.txt", ios::app);
			system("cls");
			signup();
			cout << "Username:";
			cin.ignore();
			getline(cin, uname);
			for (int i = 0; i <= turn; i++) {
				//check for existed username
				while (uname == user[0][i]) {
					system("cls");
					signup();
					cout << "Username existed" << endl;
					cout << "Username:";
					getline(cin, uname);
					i = 0;
				}
				//Exit username not allowed
				if (uname == "Exit") {
					break;
				}
				//Account Recovery and OK username not allowed
				else if (uname == "Account Recovery" || uname == "OK" ) {
					system("cls");
					signup();
					cout << "Username Invalid" <<endl;
					cout << "Username:";
					getline(cin, uname);
					i = -1;

				}


			}
			//If user decide to exit registration process,exit
			if (uname == "Exit") {
				system("cls");
				outuserfile.close();
				return ;
			}

			cout << endl << "Password:";
			getline(cin, pass);
			cout << endl <<"   ____";
			cout << endl <<"  /    \\";
			cout << endl <<"  |    |";
			cout << endl <<"  |    |";
			cout << endl <<"  |    |  *Please ensure the entered information is correct." ;
			cout << endl <<"  |    |   The information below is essential for account recovery in case you lose your account.";
			cout << endl <<"  |    |";
			cout << endl <<"  |    |";
			cout << endl <<"  \\____/     ";
			cout << endl <<"    __";
			cout << endl <<"   /  \\";
			cout << endl <<"   \\__/";


			
			cout << endl << "Your name:";
			getline(cin, name);
			cout << endl << "Your mobile phone number:";
			getline(cin, phone);
			cout << endl << "Your identity card(IC) number:";
			getline(cin, identification);
			//Fill text file with the information
			outuserfile << uname << endl << pass << endl << name << endl << phone << endl << identification << endl;
			system("cls");
			cout  << "                                                                    /\\                                       " << endl;
			cout  << "                                                                   /  \\                                      " << endl;
			cout  << "                                                                  /    \\                                      " << endl;
			cout  << "                                                                 /      \\                                      " << endl;
			cout  << "                                                                /        \\                                      " << endl;
			cout  << "                                                               /          \\                                      " << endl;
			cout  << "                                                              /           /                                    " << endl;
			cout  << "                                                             /           /                                    " << endl;
			cout  << "                                                 /\\         /           /                                      " << endl;
			cout <<  "                                                /  \\       /           /                                      " << endl;
			cout <<  "                                               /    \\     /           /                                      " << endl;
			cout <<  "                                              /      \\   /           /                                      " << endl;
			cout <<  "                                             /        \\ /           /                                      " << endl;
			cout <<  "                                            /                      /                                      " << endl;
			cout <<  "                                           /                      /                                      " << endl;
			cout <<  "                                           \\                     /                                      " << endl;
			cout <<  "                                            \\                   /                                      " << endl;
			cout <<  "                                             \\                 /                                      " << endl;
			cout <<  "                                              \\               /                                      " << endl;
			cout <<  "                                               \\             /                                      " << endl;
			cout <<  "                                                \\           /                                      " << endl;
			cout <<  "                                                 \\         /                                      " << endl;
			cout <<  "                                                  \\       /                                      " << endl;
			cout <<  "                                                   \\     /                                      " << endl;
			cout <<  "                                                    \\   /                                      " << endl;
			cout <<  "                                                     \\ /                                      " << endl;



			cout << endl << "Register succesful!" << endl << "Thank you for becoming a member of JJS Karaoke,we hope you enjoy being our member." << endl;
			cout << "Enter any key to continue";
			cin >> random;
			system("cls");
			outuserfile.close();
}
					
void readtext(string user [5][1000],string uname,string pass,string name,string phone,string identification,int & turn,string random) {
	ifstream inuserfile;
	inuserfile.open("User.txt");
	//Input textfile into Arrays
	//Day
	getline(inuserfile, random);
	while (!inuserfile.eof()) {
		//Username
		getline(inuserfile, uname);
		user[0][turn] = uname;
		//Password
		getline(inuserfile, pass);
		user[1][turn] = pass;
		//Realname
		getline(inuserfile, name);
		user[2][turn] = name;
		//Mobile phone number
		getline(inuserfile, phone);
		user[3][turn] = phone;
		//Identification
		getline(inuserfile, identification);
		user[4][turn] = identification;

		//how many user is in text file
		turn++;

	}
	inuserfile.close();
}
void signup(){
			cout << "Become one of our member and enjoy numerous benefits!    lready a member? Type 'Exit' at username and enter 3 to log in." << endl;
			cout << "It will only takes a minute." << endl << endl;
			cout << "               ____     _________      ______                                          _______          " << endl;
			cout << "              /             |         /         |\\     |              |         |     |       \\    " << endl;
			cout << "              |             |         |         | \\    |              |         |     |       |      " << endl;
			cout << "              \\___          |         |         |  \\   |              |         |     |_______/         " << endl;
			cout << "                  \\         |         |  ___    |   \\  |              |         |     |               " << endl;
			cout << "                  |         |         |     |   |    \\ |              |         |     |                " << endl;
			cout << "              ____/    _____|____     \\_____|   |     \\|              \\_________/     |                    " << endl << endl;
			cout << "                                                    ___________" << endl;
			cout << "                                                   |           |" << endl;
			cout << "                                                   |           |" << endl;
			cout << "                                                   |           |" << endl;
			cout << "                                                   |           |" << endl;
			cout << "                                                   |           |" << endl;
			cout << "                                              _____|           |___" << endl;
			cout << "                                              \\                   /  " << endl;
			cout << "                                               \\                 /  " << endl;
			cout << "                                                \\               /  " << endl;
			cout << "                                                 \\             /  " << endl;
			cout << "                                                  \\           /  " << endl;
			cout << "                                                   \\         /  " << endl;
			cout << "                                                    \\       /  " << endl;
			cout << "                                                     \\     /  " << endl;
			cout << "                                                      \\   /  " << endl;
			cout << "                                                       \\ /   " << endl;

}
void login() {
	cout << "Login to our applications to enjoy our services! Don't have an account? Type 'Exit' at username and enter 2 to Register." << endl;
	cout << "                                                        Forget account information? Type 'Account Recovery' at username." << endl << endl;
	cout << "                                ____        ______               ___________                                     " << endl;
	cout << "                  |            /    \\      /                          |          |\\     |         " << endl;
	cout << "                  |           |      |     |                          |          | \\    |               " << endl;
	cout << "                  |           |      |     |    __                    |          |  \\   |               " << endl;
	cout << "                  |           |      |     |      |                   |          |   \\  |                " << endl;
	cout << "                  |           |      |     |      |                   |          |    \\ |          " << endl;
	cout << "                  |______      \\____/      \\_____/              ______|____      |     \\|                     " << endl;
	cout << "                                                    ___________" << endl;
	cout << "                                                   |           |" << endl;
	cout << "                                                   |           |" << endl;
	cout << "                                                   |           |" << endl;
	cout << "                                                   |           |" << endl;
	cout << "                                                   |           |" << endl;
	cout << "                                              _____|           |___" << endl;
	cout << "                                              \\                   /  " << endl;
	cout << "                                               \\                 /  " << endl;
	cout << "                                                \\               /  " << endl;
	cout << "                                                 \\             /  " << endl;
	cout << "                                                  \\           /  " << endl;
	cout << "                                                   \\         /  " << endl;
	cout << "                                                    \\       /  " << endl;
	cout << "                                                     \\     /  " << endl;
	cout << "                                                      \\   /  " << endl;
	cout << "                                                       \\ /   " << endl;
}

void checkuserroom(string uname, string file,string random) {
	ifstream check;
	string time;
	string day;
	string book;
	string room;
	//open file
	check.open(file);
	//read which day is it in the file
	getline(check, day);
	//read 10 rooms
	for (int i = 0; i <= 9; i++) {
		getline(check, room);
		//read 11 hours
		for (int j = 0; j <= 10; j++) {
			getline(check, time);
			//Booking information of the room
			getline(check, book);
			if (book == uname) {
				cout << day << endl;
				cout << room << endl;
				cout << time << endl << endl;


		}
		
		
		}
	}

}

void unbooking(string uname,string random,string array[10][11],string time[11],string file,string dayname) {
		system("cls");
		checkuserroom(uname,file, random);
		int room;
		cout << "Which room of order would you like to cancel?";
		cin >> room;
		//Only allow room1-10
		while (10 < room || room <= 0) {
			system("cls");
			cout << "We have only TEN room." << endl;
			cout << "Enter any key to continue." << endl;
			cin >> random;
			checkuserroom(uname, file, random);
			cout << "Which room of order would you like to cancel?";
			cin >> room;
		}
		cout << "For example if you would like to cancel 1.00 p.m.- 2p.m.,type 13" << endl;
		cout << "At which hour would you like to cancel?:";
		int time0;
		cin >> time0;
		//Only allow 1100-2100
		while (21 < time0 || time0 < 11) {
			system("cls");
			cout << " We only operate from 1100-2200." << endl;
			cout << "Enter any key to continue." << endl;
			cin >> random;
			checkuserroom(uname, file, random);
			cout << "At what time would you like to cancel the room order:";
			cin >> time0;
		}
		time0 = time0 - 11;
		room = room - 1;
		if (array[room][time0] != uname) {
			cout << "You didn't book this room" << endl;
			cout << "Enter any key to continue";
			cin >> random;
			return;
		}
		array[room][time0] = "OK";
		cout << "Unbooking successful";
		ofstream updatefile;
		updatefile.open(file);
		updatefile << dayname << endl;
		for (int i = 0; i <= 9; i++) {
			updatefile << "Room" << i + 1 << endl;
			for (int j = 0; j <= 10; j++) {
				updatefile << time[j] << endl;
				updatefile << array[i][j] << endl;
			}
		}
		cout <<endl << "Enter any key to continue";
		cin >> random;
	}





