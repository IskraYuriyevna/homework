#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

class Exception{ //	异常基类
    private:
		string comment_; 
	public:
		Exception(const char * comment) : comment_(comment){}
		Exception(const Exception & other) {comment_=other.comment_;}
		~Exception(){}//没有用虚函数,为什么？
		const string GetComment() const { return comment_; }
};

class FileException: public Exception 
//公有继承，保持基类的权限状态不变，private成员不可访问
//若为保护继承或私有继承，基类中的成员将变成保护或私有成员，原私有成员依然不可访问
{
    private:
        char* filename_; ///文件名(深拷贝)
        char * strdup(const char * str ) const; //复制C字符串
    public:
        FileException(const char * filename,const char * comment) : Exception(comment) { filename_ = strdup(filename); }
	    FileException(const FileException & other) : Exception(other) { filename_ = strdup(other.filename_); }
        ~FileException(){ delete[] filename_; } // 释放文件名的内存
        char* GetFilename() const { return filename_; } 
};

char* FileException::strdup(const char* str)const
{
    char * res = new char[strlen(str)+1];
    strcpy(res,str);
    return res;
}

class FileErrCodeException : public FileException
// 公有继承FileException ，添加错误码
{
	private:
		int err_code_;
	public:
		FileErrCodeException(const char * filename, const char * comment) : FileException(filename,comment), err_code_(errno){}
		//此处errno从哪里来？
        FileErrCodeException(const FileErrCodeException & other) : FileException(other), err_code_(other.err_code_){}
		int GetErrCode() const { return err_code_; }
};

int count_symbols(const char* filename){

    ifstream fin(filename);
    if(!fin.is_open()) throw FileErrCodeException(filename,"Can't open file");

    int count = 0;
    while(fin.get() && !fin.eof()) count++;//逐个字符读取并计数

    fin.close();
    if(count==0) throw FileException(filename,"is empty");

    return count;
}

int main(int argc, char** argv)
{
    int count_symb;

    try{
        if (argc<2) throw Exception("no filename");
        count_symb = count_symbols(argv[1]);
    }
    catch(FileErrCodeException & ex)
    {
        cerr << "Exception: " << ex.GetComment() << " " << ex.GetFilename() << " Error code: " << strerror(ex.GetErrCode()) << endl;
        return 2;
    }
    catch(FileException & ex)
    {
	    cerr << "Exception: " << ex.GetFilename() << " " << ex.GetComment() << endl;
	    return 3;
    }
    catch(Exception & ex)
    {
	    cerr << "Exception: " << ex.GetComment() << endl;
	    return 4;
    }
    catch(...)
    {
        cerr <<  "Unknown error" << endl;
        return 5;
    }

    cout << "File " << argv[1] << " contains " << count_symb << " symbols " << endl; 
    ofstream fout("result.txt");//输出结果到文件
    if(!fout.is_open()){ cerr << "Can't open file result.txt" << endl; return 3; }
    fout << "File " << argv[1] << " contains " << count_symb << " symbols " << endl;
    fout.close();

    return 0;
}

