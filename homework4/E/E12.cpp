#include<iostream>
#include<fstream>// file
#include<cstring>//C string
#include<string>//C++ string
using namespace std;

class FileException{ ///自定义的文件异常类
    public:
        FileException(const char* filename,const char*comment);
        FileException(const FileException& other);//拷贝构造函数
        ~FileException(){delete[] filename_;}
        char* GetFilename() const {return filename_;}
        string GetComment() const {return comment_;}
        int GetErrCode() const {return err_code_;}
    private:
        char* strdup(const char *str) const;// 复制c字符串
        char* filename_;//C-style string
        string comment_;//c++-style string
        int err_code_;//Error code
};

FileException::FileException(const FileException& other)
{
    filename_ = strdup( other.filename_);//深拷贝
    comment_ = other.comment_;//直接赋值，因为c++-string自动管理内存
    err_code_ = other.err_code_; 
}

char* FileException::strdup(const char* str)const
//动态分配内存并复制C字符串，需要析构的时候释放内存
{
    char * res = new char[strlen(str)+1];
    strcpy(res,str);
    return res;
}

FileException::FileException(const char *filename,const char *comment)
{
    filename_ = strdup(filename);
    comment_ = comment;
    err_code_ = errno; //保存全局错误码

}

int count_symbols(const char* filename)
//计数函数
{
    ifstream fin(filename);
    if(!fin.is_open()){//如果文件无法打开，抛出异常
        throw FileException(filename,"Can't open file");
        //throw其实可以抛出任何类型，例如基本类型，指针，引用等
        //但是异常对象需要被拷贝或移动构造初始化到异常存储区，禁止拷贝的对象无法抛出
        //抛出局部变量的指针会被销毁，导致展开时变成悬空指针，危险！
        //如果栈展开过程中，入析构函数中再次抛出异常，程序会直接终止，因此析构函数应保证不抛出异常。
        return -1;
    }
    int count = 0;
    while(fin.get() && !fin.eof()){ //逐字符读取，直到eof
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
    //异常处理块
    try{
        count_symb = count_symbols(argv[1]);
    }
    catch(FileException& ex)
    {
        cerr << "Exception: " << ex.GetComment() << " " << ex.GetFilename() << " Error code: " << strerror(ex.GetErrCode()) << endl;
        return 2;
    }
    catch(...)//处理未预见的错误
    {
        cerr <<  "Unknown error" << endl;
        return 2;
    }

    // count_symb = count_symbols(argv[1]);
    // if (count_symb == -1) return 2;
    cout << "File " << argv[1] << " contains " << count_symb << " symbols " << endl; 
    ofstream fout("result.txt"); //将结果输出到文件
    if(!fout.is_open())
    {//如果写入失败，返回错误码3
        cerr << "Can't open file result.txt" << endl;
        return 3;
    }
    fout << "File " << argv[1] << " contains " << count_symb << " symbols " << endl;
    fout.close();
    return 0;
}
