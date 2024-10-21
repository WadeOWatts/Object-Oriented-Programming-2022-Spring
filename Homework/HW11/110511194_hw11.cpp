#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include<iomanip>

using namespace std;

int main()
{
    ifstream inp;
    ofstream oup;
    inp.open("input.txt");
    oup.open("output.txt");

    map<string,double> rating;
    map<string,int> avg;
    map<string,double>::iterator p;
    map<string,int>::iterator q;

    int line,times;
    double rate;
    inp >> line;
    string name,rt;
    getline(inp,name);
    for(int i = 0;i < line;i++)
    {
        getline(inp,name);
		name.pop_back();
        getline(inp,rt);
        rate = atoi(rt.c_str());

        if(rating.find(name) == rating.end())
        {
            rating[name] = rate;
            avg[name] = 1;
        }
        else
        {
            rating[name] += rate;
            avg[name] ++;
        }
    }
    for(p = rating.begin(),q = avg.begin();p != rating.end();p++,q++)
    {
        if(q->second == 1)
        {
            oup << p->first << ": " << q->second << " review, average of " << (p->second)/(q->second) << " / 5" << endl;
        }
        else{
            oup << p->first << ": " << q->second << " reviews, average of " << setprecision(2) << (p->second)*1.0/(q->second) << " / 5" << endl;
        }
    }

    inp.close();
    oup.close();

    return 0;
}
