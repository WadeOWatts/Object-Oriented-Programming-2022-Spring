#include<iostream>
#include<iomanip>
using namespace std;


//=========================== Class ===========================//

//Abstract Class Mtx
template<class T>
class Mtx{
    public:
        virtual T& operator()(int i, int j) = 0;
        virtual void showMatrix() = 0;
        virtual ~Mtx(){}

};

// n x n full matrix
template<class T>
class FullMatrix : public Mtx<T>{
    public:
        FullMatrix(int n);
        virtual T& operator()(int i, int j);
        //void output();
        virtual void showMatrix();
    private:
        T **matrix;
        int dim;
};

// n x n Symmetric Matrix
template<class T>
class SymmetricMatrix : public Mtx<T>{
    public:
        SymmetricMatrix(int n);
        virtual T& operator()(int i, int j);
        //void output();

        virtual void showMatrix();
     //   int getdim();
    protected:
        T **matrix;
        int dim;
        T **p;
};

// n x n Upper Triangle Matrix
template<class T>
class UpperTriMatrix: public SymmetricMatrix<T>{
    public:
        UpperTriMatrix(int n):SymmetricMatrix<T>(n){}
        virtual T& operator()(int i, int j);
        virtual void showMatrix();
        //virtual T& operator()(int i, int j);
	//	int getdim();
   //     void getm();


    private:
        T **matrix;
        int dim;



};

// n x n Lower Triangle Matrix
template<class T>
class LowTriMatrix : public SymmetricMatrix<T>{
    public:
        LowTriMatrix(int n): SymmetricMatrix<T>(n){}
        virtual T& operator()(int i, int j);
        virtual void showMatrix();
    private:
        T **matrix;
        int dim;


};

//===========================Class Definition===========================//
template<class T>
FullMatrix<T>::FullMatrix(int n){
    dim = n;
    matrix = new T* [dim];

    for(int i = 0; i < dim; ++i)
        matrix[i] = new T[dim];

    for(int i = 0; i < dim; ++i)
        for(int j = 0; j < dim; ++j)
            matrix[i][j] = 0;
}
template<class T>
T& FullMatrix<T>::operator()(int i, int j){
    // boundary checking
    if(i >= dim || j >= dim){
        cout << "error : matrix boundary check violation" << endl;
        exit(-1);
    }
    return matrix[i][j];
}
template<class T>
void FullMatrix<T>::showMatrix()
{
    for(int i = 0;i < (this->dim);i++)
    {
        for(int j = 0;j < (this->dim);j++)
        {
            cout << left  << setw(5) << (this->matrix[i][j]) << " ";
        }
        cout << endl;
    }

}



//--------------Definition of SymmetricMatrix--------------//
template<class T>
SymmetricMatrix<T>::SymmetricMatrix(int n){
    dim = n;
	matrix = new T *[dim];
	p = new T *[dim];

    for (int i = 0; i < dim; ++i){
        matrix[i] = new T[i+1];
        p[i] = new T[i+1];
    }

    for (int i = 0; i < dim; ++i){
        for (int j = 0; j <= i; ++j){
            matrix[i][j] = 0;
            p[i][j] = 0;
        }
    }
}
template<class T>
T& SymmetricMatrix<T>::operator()(int i, int j){
    // boundary checking
    if(i >= dim || j >= dim){
        cout << "error : matrix boundary check violation" << endl;
        exit(-1);
    }
    if (i>=j)
        return this->matrix[i][j];
    else
        return this->matrix[j][i];
}


template<class T>
void SymmetricMatrix<T>::showMatrix()
{

    for(int i = 0;i < (this-> dim);i++)
    {

        for(int j = 0;j <= i;j++)
        {
            cout<< left  << setw(5) << this->matrix[i][j] << " ";
        }
        for(int j = i+1;j < (this->dim) ;j++)
        {
            cout<< left  << setw(5) << this->matrix[j][i] << " ";
        }
        cout << endl;
    }

}/*
template<class T>
int SymmetricMatrix<T>::getdim()
{
    return dim;
}*/


//--------------Definition of UpperTriMatrix--------------//

template<class T>
T& UpperTriMatrix<T>::operator()(int i, int j){
    // boundary checking

    if(i >= SymmetricMatrix<T>::dim || j >= SymmetricMatrix<T>::dim){
        cout << "error : matrix boundary check violation" << endl;
        exit(-1);
    }

//    T *p = new T;
  //  T** p = NULL;
    if(i <= j)
        return SymmetricMatrix<T>::matrix[j][i];
    else
        return SymmetricMatrix<T>::p[i][j];

}


template<class T>
void UpperTriMatrix<T>::showMatrix()
{

//    using ;

//	cout << UpperTriMatrix<T>::dim << endl;
    for(int i = 0; i <(SymmetricMatrix<T>::dim);i++)
    {
        for(int j =(SymmetricMatrix<T>::dim) - i;j < SymmetricMatrix<T>::dim ;j++)
        {
            cout<< left  << setw(5) << 0 << " ";
        }
		for(int j = i;j <(SymmetricMatrix<T>::dim) ;j++)
        {
            cout<< left  << setw(5) <<(SymmetricMatrix<T>::matrix[j][i]) << " ";
        }

        cout << endl;
    }
}



template<class T>
void LowTriMatrix<T>::showMatrix()
{
    for(int i = 0;i <(SymmetricMatrix<T>::dim);i++)
    {

        for(int j = 0;j <= i;j++)
        {
            cout<< left  << setw(5) <<(SymmetricMatrix<T>::matrix[i][j]) << " ";
        }
        for(int j = i+1;j <(SymmetricMatrix<T>::dim);j++)
        {
            cout<< left  << setw(5) << 0 << " ";
        }
        cout << endl;
    }
}
template<class T>
T& LowTriMatrix<T>::operator()(int i, int j){
    // boundary checking
    if(i >= SymmetricMatrix<T>::dim || j >= SymmetricMatrix<T>::dim){
        cout << "error : matrix boundary check violation" << endl;
        exit(-1);
    }
   // T** p = NULL;
//   T *p = new T;
    if (i>=j)
        return SymmetricMatrix<T>::matrix[i][j];
    else
        return SymmetricMatrix<T>::p[j][i];

}

/*
template<class T>
void UpperTriMatrix<T>::output()
{
    output();
}*/

//--------------Definition of LowTriMatrix--------------//
// ...


//===========================main function===========================//
int main(){
    FullMatrix<int> A(2);
    A(0,0) = 5; A(0,1) = 4; A(1,0) = 3; A(1,1) = 6;


    SymmetricMatrix<int> B(3);
    B(0,0) = 5; B(1,0) = 3; B(1,1) = 6;
    B(2,0) = 1; B(2,1) = 9; B(2,2) = 2;



    UpperTriMatrix<int> C(3);
    C(0,0) = 1; C(0,1) = 2; C(0,2) = 4;
    C(1,1) = 3; C(1,2) = 5; C(2,2) = 6;


    LowTriMatrix<double> D(3);
    D(0,0) = 9.1; D(1,0) = 8.3; D(2,0) = 7.1;
    D(1,1) = 6.2; D(2,1) = 5.5; D(2,2) = 4.2;

    UpperTriMatrix<double> E(3);
    E(0,0) = 1.3; E(1,0) = 2.2; E(2,0) = 4.7;
    E(1,1) = 3.5; E(2,1) = 5.9; E(2,2) = 6.1;

    LowTriMatrix<double> F(3);
    F(0,0) = 9.7; F(0,1) = 8.1; F(0,2) = 7.1;
    F(1,1) = 6.5; F(1,2) = 5.5; F(2,2) = 4.3;




    Mtx<int> *vecA[3];
    vecA[0] = &A; vecA[1] = &B; vecA[2] = &C;
    for (int i = 0; i < 3; ++i) {
        vecA[i]->showMatrix(); cout << endl;
    }

    Mtx<double> *vecB[3];
    vecB[0] = &D; vecB[1] = &E; vecB[2] = &F;
    for (int i = 0; i < 3; ++i) {
        vecB[i]->showMatrix(); cout << endl;
    }


    return 0;
}

