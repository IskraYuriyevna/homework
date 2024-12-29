//这个实例以读写模式打开一个文件，向文件afile.dat写入用户的信息之后，程序从文件读取信息，并且将其输出到屏幕上：

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char data[100];

    //以写模式打开文件
    ofstream outfile; //定义写文件outfile
    outfile.open("afile.dat");

    cout << "Writeing to the file" << endl;
    cout << "Enter your name:";
    cin.getline(data,100);
    //可以包含三个参数:接收字符串的变量，接收字符个数，结束字符

    //向文件写入用户输入的数据
    outfile << data << endl;

    cout<<"Enter your age: ";
    cin >> data;
    cin.ignore();
    //包含两个参数，数值型和字符型，跳过前n个字符或某个字符之前的所有内容
    //如果没有写，那么默认是EOF之前的所有字符

    //再次向文件写入用户输入的数据
    outfile << data << endl;

    //关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("afile.dat");

    cout << "Reading from the file" << endl;
    infile >> data;

    //在屏幕上打印数据
    cout << data << endl;

    //再次从文件写入数据并显示在屏幕上
    infile >> data;
    cout << data << endl;

    //关闭打开的文件
    infile.close();

    return 0;
}