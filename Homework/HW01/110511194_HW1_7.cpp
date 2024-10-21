#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int ANSWERS = 8;
const int NUMBER_OF_CHAPTERS = 17;

void firstans(int);

ifstream inp;
ofstream oup;


int main()
{


    if(inp.fail())
    {
        cout << "fail\n";
        exit(1);
    }

	string s, t, y;
	int Count = 0, a = 0;

	while(1)
    {

        getline(cin, s);
        int k = s.size();

        for(int i = 0; i < k; i++)
        {
            if(isalpha(s.at(i)))
                Count++;
            else
                continue;
        }

        a = Count % ANSWERS;
        inp.open("answer_file.txt");
        if(a == 0)
        {
            firstans(Count);
        }
        else
        {

            for(int i = 0; i < a; i++)
            {
                getline(inp , y);
            }
            getline(inp,t);

            cout << t << endl;
        }
        Count = 0;

        inp.close();
   }

	inp.close();

	return 0;
}

void firstans(int c)
{
    string r;

    getline(inp,r,'#');
    cout << r << (c % NUMBER_OF_CHAPTERS + 1) << endl;
}
