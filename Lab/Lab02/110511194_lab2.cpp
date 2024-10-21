#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argc,char **argv)
{
	ifstream inFile;
	ofstream oup;

	inFile.open(argv[1]);
	oup.open(argv[2]);

	if(inFile.fail())
    {
        exit(1);
    }


	oup << setw(12) << " ";

    string s1;

	while(!inFile.eof())
	{
		getline(inFile,s1);
		while(!inFile.eof())
        {
            stringstream ss(s1);
            string temp;
            vector<string> temp1;

            while(ss >> temp)
			{
                if(temp == ".model")
                {
                    ss >> temp;
                    oup << left << setw(12) << temp << " ";
                }
            }

            getline(inFile,s1);
        }
	}


	inFile.close();
	inFile.open(argv[1]);

	oup << endl << setw(12) << left << "vth0";



	while(!inFile.eof())
	{
		getline(inFile,s1);
		while(!inFile.eof())
        {
            stringstream ss(s1);
            string temp;
            vector<string> temp1;

            while(ss >> temp)
            {
                if(temp == "+vth0")
                {
                    ss >> temp;
                    ss >> temp;
                    oup << left << setw(12) << temp << " ";
                }
            }

            getline(inFile,s1);
        }
	}



	oup << endl;

	inFile.close();
	inFile.open(argv[1]);

	oup << left << setw(12) << "u0";


	while(!inFile.eof())
	{
		getline(inFile,s1);
		while(!inFile.eof())
        {
            stringstream ss(s1);
            string temp;
            vector<string> temp1;

            while(ss >> temp)
            {
                if(temp == "u0")
                {
                    ss >> temp;
                    ss >> temp;
                    oup << left << setw(12) << temp << " ";
                }
            }

            getline(inFile,s1);
        }
	}



	oup << endl;
	inFile.close();
	inFile.open(argv[1]);

	oup << left <<  setw(12) << "ub";

	while(!inFile.eof())
	{
		getline(inFile,s1);
		while(!inFile.eof())
        {
            stringstream ss(s1);
            string temp;
            vector<string> temp1;

            while(ss >> temp)
            {
                if(temp == "ub")
                {
                    ss >> temp;
                    ss >> temp;
                    oup << left << setw(12) << temp << " ";
                }
            }

            getline(inFile,s1);
        }
	}

	inFile.close();
	oup.close();

	return 0;
}
