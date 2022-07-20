#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int number1, number2;
    ifstream m("in.txt");
    if(!m.is_open())
    {
        cout << "Файл не открывается"; return 0;
    }
    m >> number1;
    number1;
    int* ms1 = static_cast<int*>(malloc(number1 * sizeof(int)));
    for(int i=0; i<number1; ++i)
    {
        m >> ms1[i];
        cout << ms1[i];
    }
    cout << "\n";
    m >> number2;
    number2;
    int* ms2 = static_cast<int*>(malloc(number2 * sizeof(int)));
    for (int i = 0; i < number2; ++i)
    {
        m >> ms2[i];
        cout << ms2[i];
    }
    cout << "\n";
    ofstream j("out.txt");
        j << number2<<endl<<ms2[number2-1]<<" ";
        for(int i=0; i<number2-1; i++)
        {
            j << ms2[i] << " ";
        }
        
        j <<endl<< number1 << endl << ms1[number1 - 1]<<" ";
        for (int i = 0; i < number1 - 1; ++i)
        {
            j << ms1[i] << " ";
        }
       
    free(ms1);
    free(ms2);
    j.close();
}