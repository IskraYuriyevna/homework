#include <exception>
#include<iostream>
#include<fstream>// file
#include<cstring>//C string
#include<string>//C++ string
using namespace std;

class Exception{
    public:
        Exception(const char* comment) : comment_(comment){}
        Exception(const Exception& other){comment_=other.comment_;}
        ~Exception(){}
        const string GetComment() const {return comment_;}
    private:
        string comment_;
};

class FileException : public Exception
{
    public:
        FileException(const char* filename,const char* comment) : Exception(comment){filename_ = strdup(filename);}
        FileException(const FileException& other) : Exception(other){filename_=strdup(other.filename_);}
        ~FileException(){delete[] filename_;}
        char* GetFilename() const {return filename_;}
    private:
        char* strdup(const char* str) const;
        char *filename_;
};

char* FileException::strdup(const char* str)const
{
    char * res = new char[strlen(str)+1];
    strcpy(res,str);
    return res;
}

class FileErrCodeException: public FileException
{
    public:
        FileErrCodeException(const char* filename,const char* comment):FileException(filename,comment),err_code_(errno){}
        FileErrCodeException(const FileErrCodeException& other) : FileException(other),err_code_(other.err_code_){}
        int GetErrCode() const {return err_code_;}
    private:
        int err_code_;
};

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
    if (count==0)
        throw FileException(filename,"is empty");
    return count;
}

int main(int argc, char** argv)
{
    int count_symb;
    try{
        if (argc<2)
        {
            throw Exception("no filename");
        }
            count_symb = count_symbols(argv[1]);
    }
    catch(FileErrCodeException& ex)
    {
        cerr << "Exception: " << ex.GetComment() << " " << ex.GetFilename() << " Error code: " << strerror(ex.GetErrCode()) << endl;
        return 2;
    }
    catch(FileException& ex)
    {
        cerr << "Exception: " << ex.GetFilename() << " " << ex.GetComment() << endl;
        return 3;
    }
    catch(Exception& ex){
        cerr << "Exception: " << ex.GetComment() << endl;
        return 4;
    }
    catch(...)
    {
        cerr <<  "Unknown error" << endl;
        return 2;
    }
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