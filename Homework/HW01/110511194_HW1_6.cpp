#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void newLine();
void firstans(int&);

ifstream inp;
ofstream oup;

int main()
{

	inp.open("answer_file.txt");

    if(inp.fail())
    {
        cout << "fail\n";
        exit(1);
    }

	string s = "Hello world!";
	char t;
	int c = 18;

	cin >> t;
	newLine();
	firstans(c);

    cin >> t;
    newLine();

	while(1)
    {
        if(!inp.eof())
        {
            getline(inp,s);
            cout << s << endl;

            cin >> t;
            newLine();
        }
        else
        {
            inp.close();
            inp.open("answer_file.txt");

            firstans(c);

            cin >> t;
            newLine();
        }
    }

	inp.close();

	return 0;
}

void newLine()
{
    char symbol;
    do
    {
        cin.get(symbol);
    }while(symbol != '\n');
}

void firstans(int& c)
{
    string s;
    if(c == 0)
    {
        c = 18;
    }

    getline(inp,s,'#');
    cout << s << c << endl;
    getline(inp,s);
    c--;
}
