

// TO DO: deleteRepeats() template function

int main(){
    int size;

    char a[10];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'a';
    a[3] = 'c';
    a[4] = 'e';
    a[5] = 'e';
    a[6] = 'g';
    a[7] = 'e';
    size = 8;
    deleteRepeats(a, size);
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << "\n";

    int b[10];    
    b[0] = 1;
    b[1] = 1;
    b[2] = 5;
    b[3] = 9;
    b[4] = 1;
    size = 5;
    deleteRepeats(b, size);
    for(int i = 0; i < size; i++)
        cout << b[i] << " ";
    cout << "\n";

    return 0;
}