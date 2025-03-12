#include<iostream>
#include<fstream>// file
#include<cstring>//C string
#include<string>//C++ string
using namespace std;

class FileException{
    public:
        FileException(const char* filename,const char*comment);
        FileException(const FileException& other);
        ~FileException(){delete[] filename_;}
        char* GetFilename() const {return filename_;}
        string GetComment() const {return comment_;}
        int GetErrCode() const {return err_code_;}
    private:
        char* strdup(const char *str) const;
        char* filename_;//C-style
        string comment_;//c++-style
        int err_code_;
};

FileException::FileException(const FileException& other)
{
    filename_ = strdup( other.filename_);
    comment_ = other.comment_;
    err_code_ = other.err_code_;
}

char* FileException::strdup(const char* str)const
{
    char * res = new char[strlen(str)+1];
    strcpy(res,str);
    return res;
}

FileException::FileException(const char *filename,const char *comment)
{
    filename_ = strdup(filename);
    comment_ = comment;
    err_code_ = errno;

}

int count_symbols(const char* filename)
{
    ifstream fin(filename);
    if(!fin.is_open()){
        throw FileException(filename,"Can't open file");
        return -1;
    }
    int count = 0;
    while(fin.get() && !fin.eof()){
        count++;
    }
    fin.close();
    return count;
}

int main(int argc, char** argv)
{
    if (argc<2)
    {
        cerr << "Use: " << argv[0] << "filename " << endl;
        return 1;
    }
    int count_symb;
    try{
        count_symb = count_symbols(argv[1]);
    }
    catch(FileException& ex)
    {
        cerr << "Exception: " << ex.GetComment() << " " << ex.GetFilename() << " Error code: " << strerror(ex.GetErrCode()) << endl;
        return 2;
    }
    catch(...)
    {
        cerr <<  "Unknown error" << endl;
        return 2;
    }
    // count_symb = count_symbols(argv[1]);
    // if (count_symb == -1) return 2;
    cout << "File " << argv[1] << " contains " << count_symb << " symbols " << endl; 
    ofstream fout("result.txt");
    if(!fout.is_open())
    {
        cerr << "Can't open file result.txt" << endl;
        return 3;
    }
    fout << "File " << argv[1] << " contains " << count_symb << " symbols " << endl;
    fout.close();
    return 0;
}
