#include <iostream>
#include <fstream>
using namespace std;
void recording(int* mas, int size, ofstream& recording_in_file)
{
    for (int i = 0; i < size - 1; i++)
    {
        recording_in_file <<mas[i] << " ";
    }
}
void reading(int* mas, int size, ifstream& reading_file)
{
    for (int i = 0; i < size; i++)
    {
        reading_file >> mas[i];
        cout << mas[i];
    }
    cout << "\n";
}
int main()
{
    setlocale(LC_ALL, "Russian"); // На русский
    int number1, number2;
    ifstream reading_file("in.txt");
    if(!reading_file.is_open())
    {
        cout << "Файл не открывается"; return 1;
    }
    reading_file >> number1;
    int* ms1 = new int[number1];
    reading(ms1, number1, reading_file);
   
    reading_file >> number2;
    int* ms2 = new int[number2];
    reading(ms2, number2, reading_file);

    ofstream recording_in_file("out.txt");
    recording_in_file << number2<<endl<<ms2[number2-1]<<" ";
    recording(ms2, number2, recording_in_file);
    recording_in_file << endl << number1 << endl; 
    recording(ms1+1, number1, recording_in_file);
    recording_in_file<< ms1[0] << endl;
    delete[] ms1;
    delete[] ms2;
    recording_in_file.close();
    reading_file.close();
}