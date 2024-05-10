#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {

	int number;
	ifstream userfile;
	string name,username, pass, phone, identification;
	userfile.open("user.txt");
	int turn = 0;










	cout << "Welcome to JJS Karakoke!!" << endl << "1.JJS karaoke Main page" << endl << "2.Register" << endl << "3.Login" << endl << endl << "Please select the number options:";
	cin >> number;
	if (number == 1) {
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
		cout << "       /        _____016123456789________ \\       " << endl;
		cout << "      /        /                     \\      \\      " << endl;
		cout << "     _|________|_                   _|_______|_     " << endl;
		cout << "    |____________|                 |___________|   " << endl;
	}
	if (number == 2) {
		cout << "Please enter username";
		cin >> name;
		while (!userfile.eof()) {
			getline(userfile, username);
			getline(userfile, pass);
			getline(userfile, phone);
			getline(userfile, identification);
			while (username == name)
				cout << "Username existed";
		}


	}
}