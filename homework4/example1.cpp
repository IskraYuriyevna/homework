#include<iostream>

int main(){
    char str1[50],str2[50],ch;
    //std::cin >> str1;
    std::cin.get(str1,49);//function get() read string until "\n" but don't including "\n".
    std::cin.get(ch);//read "\n" on the tile of str1, or the next line will not be able to work.
    std::cin.getline(str2,49);//getline() read string until "\n" ,and including "\n".
    std::cout << "str1 = " << str1 << std::endl;
    std::cout << "str2 = " << str2 << std::endl;
    return 0;
}