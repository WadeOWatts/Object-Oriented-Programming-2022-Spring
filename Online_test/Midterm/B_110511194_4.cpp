#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class player
{
public:
    void input(string,int);
    void set_sal(double);
    int get_pick();
    void output();
private:
    string name;
    double salary;
    int pick;
};
class First_round_pick:public player
{
public:
    void inp_base();
    double get_bsal();
private:
    double Base_salary;
};
class Second_round_pick:public player
{
public:
    void inp_base();
    double get_bsal();
private:
    double Base_salary;
};
class Lottery_pick:public First_round_pick
{
public:
    void inp_lo();
    double get_lot();
private:
    double Lottery_magnification;

};
class Top_5_pick:public Lottery_pick
{
public:
    void inp_top();
    double get_top();
private:
    double Top_5_bonus;
};


int main()
{
    ifstream inp;
    inp.open("Input.txt");
    Top_5_pick t[5];
    Lottery_pick l[9];
    First_round_pick f[16];
    Second_round_pick s[30];

    for(int i = 1;i <= 5;i++)
    {
        int p;
        string n;
        inp >> p;
        getline(inp,n);
        n.pop_back();
        t[i-1].input(n,p);
        t[i-1].inp_base();
        t[i-1].inp_lo();
        t[i-1].inp_top();
    }
    for(int i = 6; i <= 14;i++)
    {
        int p;
        string n;
        inp >> p;
        getline(inp,n);
        n.pop_back();
        l[i-6].input(n,p);
        l[i-6].inp_base();
        l[i-6].inp_lo();
    }
    for(int i = 15;i <= 30;i++)
    {
        int p;
        string n;
        inp >> p;
        getline(inp,n);
        n.pop_back();
        f[i-15].input(n,p);
        f[i-15].inp_base();
    }
    for(int i = 31;i <= 60; i++)
    {
        int p;
        string n;
        inp >> p;
        getline(inp,n);
        n.pop_back();
        s[i-31].input(n,p);
        s[i-31].inp_base();
    }
    for(int i = 1;i <=5 ;i++)
    {
        t[i-1].set_sal(t[i-1].get_bsal() * (1 + t[i-1].get_lot()) + t[i-1].get_top());
        t[i-1].output();

    }
    for(int i = 6;i <=14 ;i++)
    {
        l[i-6].set_sal(l[i-6].get_bsal() * (1 + l[i-6].get_lot()));
        l[i-6].output();
    }
    for(int i = 15;i <=30 ;i++)
    {
        f[i-15].set_sal(f[i-15].get_bsal());
        f[i-15].output();
    }
    for(int i = 31;i <=60 ;i++)
    {
        s[i-31].set_sal(s[i-31].get_bsal());
        s[i-31].output();
    }










    inp.close();
    return 0;
}
void player::input(string n,int p)
{
    name = n;
    pick = p;
}
void First_round_pick::inp_base()
{
    Base_salary = 4 + 0.15 * (30 - get_pick());
}
void Second_round_pick::inp_base()
{
    Base_salary = 1.5 + 0.06 * (60 - get_pick());
}
void Lottery_pick::inp_lo()
{
    Lottery_magnification = 0.01 * (21 - get_pick());
}
void Top_5_pick::inp_top()
{
    Top_5_bonus = 6 - get_pick();
}
double Top_5_pick::get_top()
{
    return Top_5_bonus;
}
double First_round_pick::get_bsal()
{
    return Base_salary;
}
double Second_round_pick::get_bsal()
{
    return Base_salary;
}
double Lottery_pick::get_lot()
{
    return Lottery_magnification;
}
void player::set_sal(double s)
{
    salary = s;
}
int player::get_pick()
{
    return pick;
}
void player::output()
{
    cout << left <<setw(3) << pick << left <<setw(23) << name << salary << endl;
}
