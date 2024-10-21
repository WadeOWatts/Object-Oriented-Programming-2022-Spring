#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

class BasicTicket
{
	public:
		void getinfo(string,string,string,string,string);
		int getprice(string);
		int getprice1();
		friend ostream& operator <<(ostream& outs, const BasicTicket b);
	protected:
		string name;
		string dcity;
		string acity;
		string flightnum;
		int tprice;
};

class PremiumTicket: public BasicTicket
{
	public:
		void getinfo(string,string,string,string,string,string);
		int getprice(string);
		friend ostream& operator <<(ostream& outs,const PremiumTicket p);
	private:
		string seatnum;
};

int sum(vector<BasicTicket*>,int);

int main(int argc,char **argv)
{
	ifstream inp;
	inp.open(argv[1],ios::in);

	int n;
	inp >> n;
	string s,ind[n][7],tempind[7*n];
	char tempc;
	getline(inp,s);
	getline(inp,s);

	BasicTicket b[n];
	PremiumTicket p[n];

	int i = 0;
	while(inp >> tempc)
	{
		if(tempc == ':')
		{
			inp.get(tempc);
			getline(inp,s);
			istringstream ss(s);
			ss >> tempind[i];
			
			i++;
		}
		else
			continue;
	}

	for(int i = 0,k = 0; i < n;i++)
	{
		for(int j = 0;j < 7;j++)
		{
			ind[i][j] = tempind[k];
			k++;
		}
	}
	
	int bi = 0,pi = 0;

	for(int i = 0; i < n ;i++)
	{
		if(ind[i][5] == "Basic")
		{
			b[bi].getinfo(ind[i][0],ind[i][1],ind[i][2],ind[i][3],ind[i][6]);
			bi++;
		}
		else
		{
			p[pi].getinfo(ind[i][0],ind[i][1],ind[i][2],ind[i][3],ind[i][4],ind[i][6]);
			pi++;
		}
	}

	vector<BasicTicket*> v1,v2;
	for(int i = 0;i < bi;i++)
	{
		v1.push_back(&b[i]);
	}
	for(int i = 0;i < pi;i++)
		v2.push_back(&p[i]);
	
	cout << "Basic:" << endl;
	cout << sum(v1,bi) << endl;
	cout << endl;
	cout << "Premium:" << endl;
	cout << sum(v2,pi) << endl;

	return 0;
}

int sum(vector<BasicTicket*> v,int n)
{
	int sum = 0;
	for(int i = 0; i < n;i++)
	{
		sum = sum + v[i]->getprice1();
	}

	return sum;
}

void BasicTicket::getinfo(string a,string b,string c,string d,string f)
{
	name = a;
	dcity = b;
	acity = c;
	flightnum = d;
	tprice = getprice(f);
}
void PremiumTicket::getinfo(string a,string b,string c,string d,string e,string f)
{
	name = a;
	dcity = b;
	acity = c;
	flightnum = d;
	seatnum = e;
	tprice = getprice(f);
}
int BasicTicket::getprice1()
{
	return tprice;
}

int BasicTicket::getprice(string f)
{
	return atoi(f.c_str());
}

int PremiumTicket::getprice(string f)
{
	int i = atoi(f.c_str());
	return 1.1 * i;
}

ostream& operator <<(ostream& outs, const BasicTicket b)
{
	cout << b.name << endl;
	cout << b.dcity << endl;
	cout << b.acity << endl;
	cout << b.flightnum << endl;
	cout << b.tprice << endl;
}

ostream& operator <<(ostream& outs, const PremiumTicket p)
{
	cout << p.name << endl;
	cout << p.dcity << endl;
	cout << p.acity << endl;
	cout << p.flightnum << endl;
	cout << p.seatnum << endl;
	cout << p.tprice << endl;
}
