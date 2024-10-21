#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Organism
{
	public:
		Organism();
		virtual void move(int,int) = 0;
		void setstep(bool);
		void setpos(int,int);
		int getstep();
		int getposi();
		int getposj();
	protected:
		int step;
		int posi;
		int posj;
};

class Ant: public Organism
{
	public:
		Ant();
		virtual void move(int,int);
	private:

};

class Doodlebug: public Organism
{
	public:
		Doodlebug();
		virtual void move(int,int);
		void setstarvestep(bool);
		int getss();
	private:
		int starvestep;
};

void createCell(char[][20],istream&,vector<Ant*>&,vector<Doodlebug*>&);
void doodlebugEat(char[][20],vector<Ant*>&,vector<Doodlebug*>&);
void doodlebugEatWay(char cell[][20],int i,int j,int f,vector<Ant*>& a,vector<Doodlebug*>& d);
void doodlebugMove(char[][20],vector<Doodlebug*>&,int);
void antMove(char[][20],vector<Ant*>&,int);
void DoodlebugDie(char[][20],vector<Doodlebug*>&);
void DoodlebugBreed(char[][20],vector<Doodlebug*>&);
void AntBreed(char[][20],vector<Ant*>&);


int main()
{
	ifstream inp1,inp2;
	ofstream oup;

	inp1.open("input_1.txt");
	inp2.open("input_2.txt");
	oup.open("output.txt");

	vector<Ant*> a;
	vector<Doodlebug*> d;

	char cell[20][20];

	createCell(cell,inp1,a,d);

	int re;
	inp2 >> re;

	for(int i = 0; i < re;i++)
	{
		int am,dm;
		inp2 >> dm >> am;
		doodlebugEat(cell,a,d);

		doodlebugMove(cell,d,dm);

		DoodlebugDie(cell,d);

		DoodlebugBreed(cell,d);//done

		antMove(cell,a,am);

		AntBreed(cell,a);

		for(int j = 0;j < 20;j++)
        {
            for(int k = 0;k < 20;k++)
            {
                if(cell[j][k] == 't')
                    cell[j][k] = 'x';
                else if(cell[j][k] == 'e')
                    cell[j][k] = 'o';
                else
                    continue;
            }
        }

        
	}

	for(int j = 0;j < 20;j++)
	{
		for(int k = 0; k < 20;k++)
			oup << cell[j][k] << " ";

		oup <<  endl;
	}

	inp1.close();
	inp2.close();
	oup.close();
	return 0;
}

void createCell(char cell[][20],istream& inp1,vector<Ant*>& a,vector<Doodlebug*>& d)
{
	for(int i = 0; i < 20;i++)
	{
		for(int j = 0;j < 20;j++){
			inp1 >> cell[i][j];
//			cout << "a.size() = " << a.size() << " d.size() = " << d.size() << endl;
			if(cell[i][j] == 'o')
			{
				Ant* ac = new Ant;
				a.push_back(ac);
				ac -> setpos(i,j);
			}
			else if(cell[i][j] == 'x')
			{
				Doodlebug* dc = new Doodlebug;
				d.push_back(dc);
				dc -> setpos(i,j);
			}
			else
				continue;
		}
	}
}
void doodlebugEat(char cell[][20],vector<Ant*>& a,vector<Doodlebug*>& d)
{
	for(int i = 0;i < 20;i++)
		{
			for(int j = 0; j < 20;j++)
			{
				if(cell[i][j] == 'x')
				{
					if(i != 0 && cell[i-1][j] == 'o')
						doodlebugEatWay(cell,i,j,0,a,d);
					else if(j != 19 && cell[i][j+1] == 'o')
						doodlebugEatWay(cell,i,j,1,a,d);
					else if(i != 19 && cell[i+1][j] == 'o')
						doodlebugEatWay(cell,i,j,2,a,d);
					else if(j != 0 && cell[i][j-1] == 'o')
						doodlebugEatWay(cell,i,j,3,a,d);
                    else
                        continue;
				}
				else
					continue;
			}
		}
}

void doodlebugEatWay(char cell[][20],int i,int j,int f,vector<Ant*>& a,vector<Doodlebug*>& d)
{
	int ii,jj;
	if(f == 0){
		ii = i-1;
		jj = j;
	}
	else if(f == 1){
		ii = i;
		jj = j + 1;
	}
	else if(f == 2){
		ii = i+1;
		jj = j;
	}
	else if(f == 3){
		ii = i;
		jj = j-1;
	}


	cell[i][j] = '1';
	cell[ii][jj] = 't';//doodlebug after eating called 't'
	for(int k = 0; k < d.size();k++)
	{
		if(d[k]->getposi() == i && d[k]->getposj() == j)
		{
			d[k] -> setpos(ii,jj);
			d[k]->setstarvestep(true);
			break;
		}
		else
			continue;
	}
	for(int k = 0; k < a.size();k++)
	{
		if(a[k]->getposi() == ii && a[k]->getposj() == jj)
		{
			delete a[k];
			a[k] = NULL;
			a.erase(a.begin()+k);
			break;
		}
		else
			continue;
	}
}
void doodlebugMove(char cell[][20],vector<Doodlebug*>& d,int dm)
{


	for(int i = 0; i < 20;i++)
	{
		for(int j = 0; j < 20;j++)
		{

			if(cell[i][j] == 'x')
			{

				int ii,jj;
				if(dm == 0){
					ii = i-1;
					jj = j;
				}
				else if(dm == 1){
					ii = i;
					jj = j + 1;
				}
				else if(dm == 2){
					ii = i+1;
					jj = j;
				}
				else if(dm == 3){
					ii = i;
					jj = j-1;
				}

				if(dm == 0 && (i != 0))
				{

					if(cell[ii][jj] == '1'){
						cell[ii][jj] = 't';
						cell[i][j] = '1';
						for(int k = 0; k < d.size();k++)
						{
							if(d[k]->getposi() == i && d[k]->getposj() == j){
								d[k]->move(ii,jj);
                                d[k]->setstarvestep(false);

                                break;
							}
							else
								continue;
						}
					}
					else
						continue;
				}
				else if(j != 19 && dm == 1){
					if(cell[ii][jj] == '1'){
						cell[ii][jj] = 't';
						cell[i][j] = '1';
						for(int k = 0; k < d.size();k++)
						{
							if(d[k]->getposi() == i && d[k]->getposj() == j){
								d[k]->move(ii,jj);
                                d[k]->setstarvestep(false);

								break;

							}
							else
								continue;
						}
					}
					else
						continue;
				}
				else if(i != 19 && dm == 2){
					if(cell[ii][jj] == '1'){
						cell[ii][jj] = 't';
						cell[i][j] = '1';
						for(int k = 0; k < d.size();k++)
						{
							if(d[k]->getposi() == i && d[k]->getposj() == j){
								d[k]->move(ii,jj);
                                d[k]->setstarvestep(false);

                                break;
							}
							else
								continue;
						}
					}
					else
						continue;
				}
				else if(j != 0 && dm == 3){
					if(cell[ii][jj] == '1'){
						cell[ii][jj] = 't';
						cell[i][j] = '1';
						for(int k = 0; k < d.size();k++)
						{
							if(d[k]->getposi() == i && d[k]->getposj() == j){
								d[k]->move(ii,jj);
                                d[k]->setstarvestep(false);

                                break;
							}
							else
								continue;
						}
					}
					else
						continue;
				}
				else
					continue;
			}
			else
				continue;
		}
	}
	for(int i = 0;i < 20;i++)
    {
        for(int j = 0;j < 20;j++)
        {
            if(cell[i][j] == 'x'){
                for(int k = 0;k < d.size();k++)
                {
                    if(d[k]->getposi()==i && d[k]->getposj() == j)
                    {
                        d[k]->setstarvestep(false);
                        break;
                    }
                }
                cell[i][j] = 't';
            }
        }
    }
	for(int i = 0;i < 20;i++)
    {
        for(int j = 0;j < 20;j++)
        {
            if(cell[i][j] == 't')
            {
                for(int k = 0;k < d.size();k++)
                {
                    if(d[k]->getposi() == i && d[k]->getposj() == j){
                        d[k] ->setstep(true);
                        break;
                    }
                }
            }
        }
    }
}
void antMove(char cell[][20],vector<Ant*>& d,int dm)
{
	for(int i = 0; i < 20;i++)
	{
		for(int j = 0; j < 20;j++)
		{
//			cout << i << ' ' << j << endl;
			if(cell[i][j] == 'o')
			{
//				cout << i << ' ' << j << endl;
				int ii,jj;
				if(dm == 0){
					ii = i-1;
					jj = j;
				}
				else if(dm == 1){
					ii = i;
					jj = j + 1;
				}
				else if(dm == 2){
					ii = i+1;
					jj = j;
				}
				else{
					ii = i;
					jj = j-1;
				}

				if(dm == 0 && (i != 0))
				{
//					cout << "test238" << endl;
					if(cell[ii][jj] == '1'){
						cell[ii][jj] = 'o';
						cell[i][j] = 'e';//ant moved
						for(int k = 0; k < d.size();k++)
						{
							if(d[k]->getposi() == i && d[k]->getposj() == j){
								d[k]->move(ii,jj);



							}
							else
								continue;
						}
					}
					else
						continue;
				}
				else if(j != 19 && dm == 1){
					if(cell[ii][jj] == '1'){
						cell[ii][jj] = 'e';
						cell[i][j] = '1';
						for(int k = 0; k < d.size();k++)
						{
							if(d[k]->getposi() == i && d[k]->getposj() == j){
								d[k]->move(ii,jj);



							}
							else
								continue;
						}
					}
					else
						continue;
				}
				else if(i != 19 && dm == 2){
					if(cell[ii][jj] == '1'){
						cell[ii][jj] = 'e';
						cell[i][j] = '1';
						for(int k = 0; k < d.size();k++)
						{
							if(d[k]->getposi() == i && d[k]->getposj() == j){
								d[k]->move(ii,jj);



							}
							else
								continue;
						}
					}
					else
						continue;
				}
				else if(j != 0 && dm == 3){
					if(cell[ii][jj] == '1'){
						cell[ii][jj] = 'e';
						cell[i][j] = '1';
						for(int k = 0; k < d.size();k++)
						{
							if(d[k]->getposi() == i && d[k]->getposj() == j){
								d[k]->move(ii,jj);



							}
							else
								continue;
						}
					}
					else
						continue;
				}
				else
					continue;
			}
			else
				continue;
		}
	}
	for(int i = 0;i < 20;i++)
    {
        for(int j = 0;j < 20;j++)
        {
            if(cell[i][j] == 'o')
                cell[i][j] = 'e';
        }
    }
    for(int i = 0;i < 20;i++)
    {
        for(int j = 0;j < 20 ;j++)
        {
            if(cell[i][j] == 'e'){
                for(int k = 0;k < d.size();k++)
                {
                    if(d[k]->getposi()==i && d[k]->getposj() == j){
                        d[k] ->setstep(true);
                        break;
                    }
                }

            }

        }
    }
}

void DoodlebugDie(char cell[][20],vector<Doodlebug*>& d)
{
	for(int i = 0; i < d.size();i++)
	{
		if(d[i]->getss() >= 3)
		{
			cell[d[i]->getposi()][d[i]->getposj()] = '1';
			delete d[i];
			d[i] = NULL;
			d.erase(d.begin()+i);
		}

		else
			continue;
	}
}

/*else if(d[i]->getstep() >=8)
		{
			DoodlebugBreed(cell,d,i);
			d[i]->setstep(0);
		}
*/
void DoodlebugBreed(char cell[][20],vector<Doodlebug*>& d)
{
	for(int i = 0;i < d.size();i++)
    {

	    if(d[i]->getstep() >= 8)
        {
            int j = d[i]->getposi(),k = d[i]->getposj();

            if(j != 0 && cell[j-1][k] == '1')
            {
                cell[j-1][k] = 't';
                Doodlebug* dd = new Doodlebug;
                d.push_back(dd);
                dd->setpos(j-1,k);
            }
            else if(k != 19 && cell[j][k+1] == '1')
            {
                cell[j][k+1] = 't';
                Doodlebug* dd = new Doodlebug;
                d.push_back(dd);
                dd->setpos(j,k+1);
            }
            else if(j != 19 && cell[j+1][k] == '1')
            {
                cell[j+1][k] = 't';
                Doodlebug* dd = new Doodlebug;
                d.push_back(dd);
                dd->setpos(j+1,k);
            }
            else if(k != 0 && cell[j][k-1] == '1')
            {
                cell[j][k-1] = 't';
                Doodlebug* dd = new Doodlebug;
                d.push_back(dd);
                dd->setpos(j,k-1);
            }

            d[i]->setstep(false);
	    }

	}
}

void AntBreed(char cell[][20],vector<Ant*>& d)
{
	for(int i = 0; i < d.size();i++)
	{
		if(d[i]->getstep() >= 3)
		{
			int j = d[i]->getposi(),k = d[i]->getposj();

			if(j != 0 && cell[j-1][k] == '1')
			{
				cell[j-1][k] = 'e';
				Ant* dd = new Ant;
				d.push_back(dd);
				dd->setpos(j-1,k);
			}
			else if(k != 19 && cell[j][k+1] == '1')
			{
				cell[j][k+1] = 'e';
				Ant* dd = new Ant;
				d.push_back(dd);
				dd->setpos(j,k+1);
			}
			else if(j != 19 && cell[j+1][k] == '1')
			{
				cell[j+1][k] = 'e';
				Ant* dd = new Ant;
				d.push_back(dd);
				dd->setpos(j+1,k);
			}
			else if(k != 0 && cell[j][k-1] == '1')
			{
				cell[j][k-1] = 'e';
				Ant* dd = new Ant;
				d.push_back(dd);
				dd->setpos(j,k-1);
			}

			d[i]->setstep(false);
		}
		else
			continue;
	}
}

Organism::Organism()
{
	step = 0;
	posi = 0;
	posj = 0;
}
void Organism::setpos(int i,int j){
	posi = i;
	posj = j;
}

void Organism::move(int i,int j)
{
	posi = i;
	posj = j;
}

int Organism::getposi()
{
	return posi;
}
int Organism::getposj()
{
	return posj;
}
void Organism::setstep(bool i)
{
	if(i == true)
		step++;
	else
		step = 0;
}
int Organism::getstep()
{
	return step;
}
Ant::Ant()
{
    step = 0;
	posi = 0;
	posj = 0;
}
void Ant::move(int ii,int jj)
{
	posi = ii;
	posj = jj;
}
Doodlebug::Doodlebug()
{
    step = 0;
	posi = 0;
	posj = 0;
	starvestep = 0;

}
void Doodlebug::move(int ii,int jj)
{
	posi = ii;
	posj = jj;
}
void Doodlebug::setstarvestep(bool i)
{
	if(i == true)
		starvestep = 0;
	else
		starvestep++;
}
int Doodlebug::getss()
{
	return starvestep;
}
