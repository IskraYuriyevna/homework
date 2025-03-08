#include<iostream>
#include<fstream>
using namespace std;

int count_symbols(const char* filename)
{
    ifstream fin(filename);
    if(!fin.is_open()){
        cerr << "Cant open file " << filename << endl;
        return -1;
    }
    int count = 0;
    while(fin.get() && !fin.eof()){
        count++;
    }
    fin.close();
    return count++;
}

int main(int argc, char** argv)
{
    if (argc<2)
    {
        cerr << "Use: " << argv[0] << "filename " << endl;
        return 1;
    }
    int count_symb;

    count_symb = count_symbols(argv[1]);
    if (count_symb == -1) return 2;
    cout << "File " << argv[1] << " contains " << count_symb << " symbols " << endl; 
    ostream fout("result.txt");
    if(!fout.is_open())
    {
        cerr << "Can't open file result.txt" << endl;
        return 3;
    }
    fout << "File " << argv[1] << " contains " << count_symb << "symbols" << endl;
    fout.close();
    return 0;
}

try