#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class student_data
{
public:
    student_data();
    void input(string,double,double);
    void output();
    string getname();
    void dstatus();
private:
    double height;
    double weight;
    string name;
    double bmi;
    string status;
};

int main()
{
    ifstream inp;
    inp.open("input1.txt");
    student_data stud[20];
    int i = 0;
    while(!inp.eof())
    {
        string n,temp1,temp2;
        double h,w;

        inp >> n >> h >> temp1 >> w >> temp2;
        stud[i].input(n,h,w);
        i++;
    }
    inp.close();
    inp.open("input2.txt");
    while(!inp.eof())
    {
        string n,temp1,temp2;
        double h,w;

        inp >> n >> h >> temp1 >> w >> temp2;
        stud[i].input(n,h,w);
        i++;
    }

    vector<string> v;
    for(int j = 0;j < 20;j++)
    {
        v.push_back(stud[j].getname());
    }
    sort(v.begin(),v.end());

    for(int j = 0;j < v.size();j++)
    {
        for(int k = 0;k < 20;k++)
        {
            if(v[j] == stud[k].getname())
            {
                stud[k].output();
                break;
            }
            else
                continue;
        }
    }




    return 0;
}

student_data::student_data()
{

}
void student_data::input(string n,double h,double w)
{
    name = n;
    height = h;
    weight = w;
    bmi = w / (0.0001 * h * h);
    dstatus();
}

string student_data::getname()
{
    return name;
}

void student_data::output()
{
    cout << left << setw(10) << name << setw(10) <<"Height:" << setw(10) <<height;
    cout << setw(10) <<"weight:" << setw(10) <<weight << setw(10) <<"BMI:" << setw(10) <<bmi << setw(10) <<status << endl;
}
void student_data::dstatus()
{
    if(bmi > 27)
        status = "overweight";
    else if(bmi < 17)
        status = "skinny";
    else
        status = "healthy";
}
