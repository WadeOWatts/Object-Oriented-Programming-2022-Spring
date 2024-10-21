#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inp;
    inp.open("weapons.txt");
    map<string,string> type;
    map<string,string> clas;
    map<string,int> phy;
    map<string,int> mag;
    map<string,bool> used;

    while(!inp.eof())
    {
        string a,b,c;
        char bl;
        int d,e;
        inp >> a >> b >> d >> e;
        getline(inp,c);
        c.pop_back();
        type[c] = a;
        clas[c] = b;
        phy[c] = d;
        mag[c] = e;
        used[c] = false;
    }

    map<string,string>::iterator iter1,p,s,t;
    map<string,int>::iterator iter2,q,r;
    map<string,bool>::iterator forbool;
    string target,clsf;
    bool Find = false;

    cin >> target;

    while(target != "EXIT")
    {
        Find = false;
        for(iter1 = type.begin();iter1 != type.end();iter1++)
        {
            if(iter1->second == target)
            {
                Find = true;

                for(p = clas.begin(); p != clas.end();p++)
                {
                    if(iter1->first == p->first)
                    {
                        clsf = p->second;
                        break;
                    }
                    else
                        continue;
                }
                break;
            }
            else
                continue;
        }


        if(Find == false)
        {
            cout << "No data" << endl;
        }
        else
        {
            int total = 0;
            vector<int> v;
            for(iter1 = type.begin();iter1 != type.end();iter1++)
            {
                if(iter1->second == target)
                {
                    if(clsf == "Magic")
                    {
                        for(iter2 = mag.begin();iter2 != mag.end();iter2++)
                        {
                            if(iter2->first == iter1->first)
                            {
                                v.push_back(iter2->second);
                                break;
                            }
                            else
                                continue;
                        }
                    }
                    else
                    {
                        for(iter2 = phy.begin();iter2 != phy.end();iter2++)
                        {
                            if(iter2->first == iter1->first)
                            {
                                v.push_back(iter2->second);
                                break;
                            }
                            else
                                continue;
                        }
                    }
                }
                else
                    continue;
            }

            sort(v.begin(),v.end());
            if(clsf == "Magic")
            {
                for(int i = 0;i < v.size();i++)
                {
                    for(iter2 = mag.begin();iter2 != mag.end();iter2++)
                    {
                        if(v[i] == iter2->second)
                        {
                            for(forbool = used.begin();forbool != used.end();forbool++)
                            {
                                if(forbool->first == iter2->first)
                                {
                                    if(forbool->second == false)
                                    {
                                        for(p = type.begin();p != type.end();p++)
                                        {
                                            if(iter2->first == p->first && p->second == target)
                                            {
                                                cout << p->second << " Magic ";
                                                for(q = phy.begin();q != phy.end();q++)
                                                {
                                                    if(iter2->first == q->first)
                                                    {
                                                        cout << q->second << " " << iter2->second << iter2->first << endl;
                                                        break;
                                                    }
                                                }
                                                break;
                                            }
                                        }

                                        forbool->second = true;
                                        break;
                                    }
                                    else
                                        continue;
                                }
                                else
                                    continue;
                            }

                        }
                        else
                            continue;
                    }
                }


            }
            else
            {
                for(int i = 0;i < v.size();i++)
                {
                    for(iter2 = phy.begin();iter2 != phy.end();iter2++)
                    {
                        if(v[i] == iter2->second)
                        {
                            for(forbool = used.begin();forbool != used.end();forbool++)
                            {
                                if(forbool->first == iter2->first)
                                {
                                    if(forbool->second == false)
                                    {
                                        for(p = type.begin();p != type.end();p++)
                                        {
                                            if(iter2->first == p->first && p->second == target)
                                            {
                                                cout << p->second << " Physical ";
                                                for(q = mag.begin();q != mag.end();q++)
                                                {
                                                    if(iter2->first == q->first)
                                                    {
                                                        cout << iter2->second << " " << q->second << iter2->first << endl;
                                                        break;
                                                    }
                                                }
                                                break;
                                            }
                                        }

                                        forbool->second = true;
                                        break;
                                    }
                                    else
                                        continue;
                                }
                                else
                                    continue;
                            }

                        }
                        else
                            continue;
                    }
                }

            }
            for(forbool = used.begin();forbool != used.end();forbool++)
                {
                    forbool->second = false;
                }
                cout << "Total: " << v.size() << endl;

        }
        cin >> target;
    }


    inp.close();
    return 0;
}
