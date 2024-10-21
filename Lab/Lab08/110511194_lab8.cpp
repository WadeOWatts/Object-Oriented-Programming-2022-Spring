#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

int vectorial(int);

class freshman;
class sophomore;
class junior;
class student;

class sls{
	public:
		sls();
		void getvalue(istream&);
		void getvector(string);
		void getwinner(student&);
		void getwinner();
		void showwinner();
		bool friend compare1(sls&,freshman&);
		bool friend compare2(sls&,sophomore&);
		bool friend compare3(sls&,junior&);
		bool size1();
		bool fon();
		bool son();
		bool jon();
		void output();
		int getcal();
		int getele();
		int getpro();
		int getvlsi();
		string getname();

	private:
		string name;
		string grade;
		int cal;
		int ele;
		int pro;
		int vlsi;
		int lim;
		vector<string> award;
		vector<student*> winner;
};

class student{
	public:
		student();
		void getname(string);
		void getgrade(char);
		char getgrade();
		void getscho(int);
		string getname();
		int getscho();
		void outputscho();
		void bonus();
	protected:
		string name;
		int scholarship;
		char grade;
	
};

class freshman: public student{
	public:
		void getcal(int);
		int getcal();
		void output();
		int getavg();
	protected:
		int calculus;
		vector<freshman*> top3;
};

class sophomore: public freshman{
	public: 
		void getele(int);
		void getpro(int);
		int getele();
		int getpro();
		void output();
		int getavg();
	protected:
		int electronics;
		int probability;
};

class junior: public sophomore{
	public:
		void getvlsi(int);
		int getvlsi();
		void output();
		int getavg();
	protected:
		int VLSI;
};



int main()
{
	ifstream inp1,inp2;
	inp1.open("input1.txt");
	inp2.open("input2.txt");

	int t1;
	string temp;
	inp1 >> t1;
	getline(inp1,temp);

	vector<freshman*> vf;
	vector<sophomore*> vs;
	vector<junior*> vj;

	int fi = 0,si = 0, ji = 0;
	

	
	for(int i = 0;i < t1;i++)
	{
		string s,ss1,ss2,ss3,st,s1,s2;
		getline(inp1,s);
		istringstream ss(s);
		ss >> s1 >> s2;
		
		if(s2 == "F"){
			freshman* fm = new freshman;
			
			vf.push_back(fm);
			vf[fi]->getname(s1);
			vf[fi]->getgrade('F');

			getline(inp1,s);
			istringstream ssf(s);
			ssf >> s1 >> s2;
			vf[fi]->getcal(atoi(s2.c_str()));
			fi++;
		}
		else if(s2 == "S"){
			sophomore* sm = new sophomore;
			vs.push_back(sm);
			vs[si]->getname(s1);
			vs[si]->getgrade('S');

			getline(inp1,s);
			getline(inp1,ss1);
			getline(inp1,ss2);
			st = s + " " + ss1 + " " + ss2;
			istringstream sss(st);
			

			for(int j = 0;j < 3;j++)
			{
				sss >> s1 >> s2;
				
				if(s1 == "C")
					vs[si]->getcal(atoi(s2.c_str()));
				else if(s1 == "E")
					vs[si]->getele(atoi(s2.c_str()));
				else
					vs[si]->getpro(atoi(s2.c_str()));
			}
			si++;

		}
		else{
			junior* jr = new junior;
			vj.push_back(jr);
			vj[ji]->getname(s1);
			vj[ji]->getgrade('J');

			getline(inp1,s);
			getline(inp1,ss1);
			getline(inp1,ss2);
			getline(inp1,ss3);
			st = s + " " + ss1 + " " + ss2 + " " + ss3;
			istringstream ssj(st);

			
			for(int j = 0;j < 4;j++)
			{
				ssj >> s1 >> s2;
				
				if(s1 == "C")
					vj[ji]->getcal(atoi(s2.c_str()));
				else if(s1 == "E")
					vj[ji]->getele(atoi(s2.c_str()));
				else if(s1 == "P")
					vj[ji]->getpro(atoi(s2.c_str()));
				else
					vj[ji]->getvlsi(atoi(s2.c_str()));
			}
			ji++;
		}

	}
	inp1.close();



	int line;
	inp2 >> line;

	sls schol[line];

	for(int i = 0;i < line;i++)
		schol[i].getvalue(inp2);

	for(int i = 0; i < fi;i++)
	{
		for(int j = 0; j < line;j++)
		{
			if(schol[j].fon())
			{
				if(compare1(schol[j],*vf[i]))
				{
					vf[i]->getscho(200);
					schol[j].getvector(vf[i]->getname());
					student* temp = vf[i];
					 
					schol[j].getwinner(*temp);
				}
				else
					continue;
			}
			else
				continue;
		}
	}

	for(int i = 0; i < si;i++)
	{
		int a = 0;
		for(int j = 0;j < line;j++)
		{
				
				if(schol[j].fon())
				{
					freshman* temp = vs[i];
					if(compare1(schol[j],*temp))
					{
						a++;
						schol[j].getvector(vs[i]->getname());
						student* winname = &(*vs[i]);
						
						schol[j].getwinner(*winname);
					}
					else
						continue;
				}
				else if(schol[j].son())
				{
				
						if(compare2(schol[j],*vs[i]))
						{
							a++;
							schol[j].getvector(vs[i]->getname());
							student* winname = &(*vs[i]);
							
							schol[j].getwinner(*winname);
						}
						else
							continue;
				}
				else
					continue;
		
		}
		vs[i]->getscho( 200 * vectorial(a));
	}

			
	for(int i = 0; i < ji;i++)
	{
		int a = 0;
		for(int j = 0;j < line;j++)
		{	
			if(schol[j].fon())
			{
				freshman* temp = vj[i];
				if(compare1(schol[j],*temp))
				{
					a++;
					schol[j].getvector(vj[i]->getname());
					student* winname = vj[i];

					 
					schol[j].getwinner(*winname);
				}
				else
					continue;
			}
			else if(schol[j].son())
			{
				sophomore* temp = vj[i];
				if(compare2(schol[j],*temp))
				{
					a++;
					schol[j].getvector(vj[i]->getname());
					student* winname = vj[i];
					

					
					schol[j].getwinner(*winname);
					 
				}
				else
					continue;
    	     	}
			else			
			{
				if(compare3(schol[j],*vj[i]))
				{
					a++;
					schol[j].getvector(vj[i]->getname());
					student* winname = vj[i];

					 
					schol[j].getwinner(*winname);
				}
				else
					continue;				
			}
		}
		vj[i]->getscho( 200 * vectorial(a));
	}


	for(int i = 0; i < line;i++)
	{
		cout << schol[i].getname() << ": ";
		schol[i].output();
	}
	

	 cout << "----------------------------------" << endl;
	
	for(int i = 0; i < line;i++){
		schol[i].getwinner();
		
	}
	
	vector<freshman*> ctop3;
	for(int i = 0; i < 3;i++)
		ctop3.push_back(NULL);
	
	int c1 = 0,c2 = 0,c3 = 0;
	for(int i = 0;i < fi;i++)
	{
		if(vf[i]->getcal() > c1)
		{
			c3 = c2;
			c2 = c1;
			c1 = vf[i]->getcal();
			ctop3[2] = ctop3[1];
			ctop3[1] = ctop3[0];
			ctop3[0] = vf[i];
		}
		else if(vf[i]->getcal() > c2)
		{
			c3 = c2;
			c2 = vf[i]->getcal();
			ctop3[2] = ctop3[1];
			ctop3[1] = vf[i];
		}
		else if(vf[i]->getcal() > c3)
		{
			c3 = vf[i]->getcal();
			ctop3[2] = vf[i];
		}
		else
			continue;
	}

	for(int i = 0;i < si;i++)
	{
		freshman* temp = vs[i];
		if(temp->getcal() > c1)
		{
			c3 = c2;
			c2 = c1;
			c1 = temp->getcal();
			ctop3[2] = ctop3[1];
			ctop3[1] = ctop3[0];
			ctop3[0] = temp;
		}
		else if(temp->getcal() > c2)
		{
			c3 = c2;
			c2 = temp->getcal();
			ctop3[2] = ctop3[1];
			ctop3[1] = temp;
		}
		else if(temp->getcal() > c3)
		{
			c3 = vf[i]->getcal();
			ctop3[2] = temp;
		}
		else
			continue;
	}
	for(int i = 0;i < ji;i++)
	{
		freshman* temp = vj[i];
		if(temp->getcal() > c1)
		{
			c3 = c2;
			c2 = c1;
			c1 = temp->getcal();
			ctop3[2] = ctop3[1];
			ctop3[1] = ctop3[0];
			ctop3[0] = temp;
		}
		else if(temp->getcal() > c2)
		{
			c3 = c2;
			c2 = temp->getcal();
			ctop3[2] = ctop3[1];
			ctop3[1] = temp;
		}
		else if(temp->getcal() > c3)
		{
			c3 = temp->getcal();
			ctop3[2] = temp;
		}
		else
			continue;
	}

	ctop3[0]->getscho(350);
	ctop3[1]->getscho(250);
	ctop3[2]->getscho(150);
//------------------------------------------------------
	vector<sophomore*> etop3;
	for(int i = 0; i < 3;i++)
		etop3.push_back(NULL);
	
	int e1 = 0,e2 = 0,e3 = 0;
	for(int i = 0;i < si;i++)
	{
		if(vs[i]->getele() > e1)
		{
			e3 = e2;
			e2 = e1;
			e1 = vs[i]->getele();
			etop3[2] = etop3[1];
			etop3[1] = etop3[0];
			etop3[0] = vs[i];
		}
		else if(vs[i]->getele() > e2)
		{
			e3 = e2;
			e2 = vs[i]->getele();
			etop3[2] = etop3[1];
			etop3[1] = vs[i];
		}
		else if(vs[i]->getele() > e3)
		{
			e3 = vs[i]->getele();
			etop3[2] = vs[i];
		}
		else
			continue;
	}
	for(int i = 0;i < ji;i++)
	{
		sophomore* temp = vj[i];
		if(temp->getele() > e1)
		{
			e3 = e2;
			e2 = e1;
			e1 = temp->getele();
			etop3[2] = etop3[1];
			etop3[1] = etop3[0];
			etop3[0] = temp;
		}
		else if(temp->getele() > e2)
		{
			e3 = e2;
			e2 = temp->getele();
			etop3[2] = etop3[1];
			etop3[1] = temp;
		}
		else if(temp->getele() > e3)
		{
			e3 = temp->getele();
			etop3[2] = temp;
		}
		else
			continue;
	}

	etop3[0]->getscho(350);
	etop3[1]->getscho(250);
	etop3[2]->getscho(150);
//-------------------------------------------------------

	vector<sophomore*> ptop3;
	for(int i = 0; i < 3;i++)
		ptop3.push_back(NULL);
	
	int p1 = 0,p2 = 0,p3 = 0;
	for(int i = 0;i < si;i++)
	{
		sophomore* temp = vs[i];
		if(temp->getpro() > p1)
		{
			p3 = p2;
			p2 = p1;
			p1 = temp->getpro();
			ptop3[2] = ptop3[1];
			ptop3[1] = ptop3[0];
			ptop3[0] = temp;
		}
		else if(temp->getpro() > p2)
		{
			p3 = p2;
			p2 = temp->getpro();
			ptop3[2] = ptop3[1];
			ptop3[1] = temp;
		}
		else if(temp->getpro() > p3)
		{
			p3 = vs[i]->getpro();
			ptop3[2] = temp;
		}
		else
			continue;
	}
	for(int i = 0;i < ji;i++)
	{
		sophomore* temp = vj[i];
		if(temp->getpro() > p1)
		{
			p3 = p2;
			p2 = p1;
			p1 = temp->getpro();
			ptop3[2] = ptop3[1];
			ptop3[1] = ptop3[0];
			ptop3[0] = temp;
		}
		else if(temp->getpro() > p2)
		{
			p3 = p2;
			p2 = temp->getpro();
			ptop3[2] = ptop3[1];
			ptop3[1] = temp;
		}
		else if(temp->getpro() > p3)
		{
			p3 = temp->getpro();
			ptop3[2] = temp;
		}
		else
			continue;
	}

	ptop3[0]->getscho(350);
	ptop3[1]->getscho(250);
	ptop3[2]->getscho(150);
//------------------------------------------------------------------
	vector<junior*> vtop3;
	for(int i = 0; i < 3;i++)
		vtop3.push_back(NULL);
	
	int v1 = 0,v2 = 0,v3 = 0;
	for(int i = 0;i < ji;i++)
	{
		junior* temp = vj[i];
		if(temp->getvlsi() > v1)
		{
			v3 = v2;
			v2 = v1;
			v1 = temp->getvlsi();
			vtop3[2] = vtop3[1];
			vtop3[1] = vtop3[0];
			vtop3[0] = temp;
		}
		else if(temp->getvlsi() > v2)
		{
			v3 = v2;
			v2 = temp->getvlsi();
			vtop3[2] = vtop3[1];
			vtop3[1] = temp;
		}
		else if(temp->getvlsi() > v3)
		{
			v3 = vj[i]->getvlsi();
			vtop3[2] = temp;
		}
		else
			continue;
	}

	vtop3[0]->getscho(350);
	vtop3[1]->getscho(250);
	vtop3[2]->getscho(150);
//------------------------------------

	freshman* fhs;
	for(int i = 0,max = 0; i < fi;i++)
	{
		if(vf[i]->getavg() > max)
		{
			max = vf[i]->getavg();
			fhs = vf[i];
		}
	}
	fhs->bonus();

	sophomore* shs;
	for(int i = 0,max = 0;i < si;i++)
	{
		if(vs[i]->getavg() > max)
		{
			max = vs[i]->getavg();
			shs = vs[i];
		}
	}
	shs -> bonus();

	junior* jhs;
	for(int i = 0,max = 0;i < ji;i++)
	{
		if(vj[i]->getavg() > max)
		{
			max = vj[i]->getavg();
			jhs = vj[i];
		}
	}
	jhs -> bonus();

	student* bob[fi+si+ji];
	for(int i = 0; i < fi;i++)
	{
		student* temp = vf[i];
		bob[i] = temp;
	}
	for(int i = fi,j = 0;i < fi + si;i++,j++)
	{
		student* temp = vs[j];
		bob[i] = temp;
	}
	for(int i = fi+si,j = 0; i < fi+si+ji ;i++,j++)
	{
		student* temp = vj[j];
		bob[i] = temp;
	}

	for(int i = fi+si+ji-1;i>0;i--)
	{
		for(int j = 0; j < i;j++)
		{
			if(bob[j]->getscho() > bob[j+1]->getscho())
			{
				student* temp = bob[j+1];
				bob[j+1] = bob[j];
				bob[j] = temp;
			}
		}
	}

	for(int i = fi+si+ji-1;i >= 0;i--)
	{
		cout << left << setw(7) << bob[i]->getname() << " ";
		cout << left << setw(7) << bob[i]->getgrade() << ": $" << bob[i]->getscho() << endl;
	}
	
	inp2.close();

	return 0;
}

void student::getname(string s)
{
	name = s;
}
void student::getscho(int c)
{
	scholarship = scholarship + c;
}
void freshman::getcal(int c)
{
	calculus = c;
}
void sophomore::getele(int c)
{
	electronics = c;
}
void sophomore::getpro(int c)
{
	probability = c;
}
void junior::getvlsi(int c)
{
	VLSI = c;
}
sls::sls()
{
	cal = 0;
	ele = 0;
	pro = 0;
	vlsi = 0;
}
void sls::getvalue(istream& inp2)
{
	string n,g,l,temp;
	inp2 >> n >> g >> l;
	getline(inp2,temp);
	lim = atoi(l.c_str());
	name = n;
	grade = g;
	for(int i = 0;i < lim;i++)
	{
		string t;
		getline(inp2,t);
		
		string s1,s2;

		istringstream ss(t);
		ss >> s1 >> s2;

		if(s1 == "C")
			cal = atoi(s2.c_str());
		else if(s1 == "E")
			ele = atoi(s2.c_str());
		else if(s1 == "P")
			pro = atoi(s2.c_str());
		else
			vlsi = atoi(s2.c_str());
	}
}

void sls::showwinner()
{
	for(int i = 0;i < winner.size();i++)
	{
		cout << winner[i]->getname() << endl;
	}
	cout << endl;
}

void sls::getvector(string s)
{
	award.push_back(s);
}

void sls::output()
{
	for(int i = 0;i < award.size();i++)
	{
		cout << award[i] << " ";
	}
	cout << endl;
}

bool sls::fon()
{
	if(grade == "F")
		return 1;
	else
		return 0;
}
bool sls::son()
{
	if(grade == "S")
		return 1;
	else
		return 0;
}
bool sls::jon()
{
	if(grade == "J")
		return 1;
	else
		return 0;
}

int sls::getcal()
{
	return cal;
}
int sls::getele()
{
	return ele;
}
int sls::getpro()
{
	return pro;
}
int sls::getvlsi()
{
	return vlsi;
}

string sls::getname()
{
	return name;
}

void sls::getwinner(student& s)
{
	winner.push_back(&s);
}
bool sls::size1()
{
	if(winner.size() == 1)
		return 1;
	else
		return 0;
}
void sls::getwinner()
{
	if(award.size() == 1)
		winner[0]->getscho(100);
}

student::student():scholarship (0){
	
}

void student::outputscho()
{
	cout << name << ": " << scholarship << endl;
}

int vectorial(int n)
{
	if( n == 0)
		return 0;
	else
		return( n + vectorial(n-1));
}
string student::getname()
{
	return name;
}
int freshman::getcal()
{
	return calculus;
}
int student::getscho()
{
	return scholarship;
}
int sophomore::getele()
{
	return electronics;
}
int sophomore::getpro()
{
	return probability;
}
int junior::getvlsi()
{
	return VLSI;
}

void freshman::output()
{
	cout << name << " " << calculus << endl;
}
void sophomore::output()
{
	cout << name << " " << calculus << " " << electronics << " " << probability << endl;
}
void junior::output()
{
	cout << name << " " << calculus << " " << electronics << " " << probability << " " << VLSI << endl;
}



bool compare1(sls& a,freshman& b)
{
	if(b.getcal() >= a.getcal())
		return 1;
	else 
		return 0;
}
bool compare2(sls& a, sophomore& b)
{
	if(b.getcal() >= a.getcal() && b.getele() >= a.getele() && b.getpro() >= a.getpro())
		return 1;
	else
		return 0;
}
bool compare3(sls& a,junior& b)
{
	if(b.getcal() >= a.getcal() && b.getele() >= a.getele() && b.getpro() >= a.getpro() && b.getvlsi() >= a.getvlsi())
		return 1;
	else 
		return 0;
}
void student::bonus()
{
	scholarship = 1.3 * scholarship;
}
int freshman::getavg()
{
	return calculus;
}
int sophomore::getavg()
{
	int t;
	t = (calculus + electronics + probability) / 3;
	return t;
}
int junior::getavg()
{
	int t;
	t = (calculus + electronics + probability + VLSI) / 4;
	return t;
}
void student::getgrade(char c)
{
	grade = c;
}
char student::getgrade()
{
	return grade;
}
