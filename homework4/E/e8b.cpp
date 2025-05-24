#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

class mstring {
private:
    char* string_;
    int length_;

public:
    mstring() {
        string_ = new char[1];
        string_[0] = '\0';
        length_ = 0;
    }

    mstring(const char* str) {
        if (str == nullptr) {
            string_ = new char[1];
            string_[0] = '\0';
            length_ = 0;
        } else {
            length_ = strlen(str);
            string_ = new char[length_ + 1];
            strcpy(string_, str);
        }
    }

    mstring(const mstring& ob) {
        length_ = ob.length_;
        string_ = new char[length_ + 1];
        strcpy(string_, ob.string_);
    }

    ~mstring() {
        delete[] string_;
    }

    int length() const { return length_; }
    bool isempty() const { return (length_ == 0); }
    void print() const { cout << string_ << endl; }

    void add(char c) {
        char* temp = new char[length_ + 2];
        strcpy(temp, string_);
        temp[length_] = c;
        temp[length_ + 1] = '\0';
        delete[] string_;
        string_ = temp;
        length_++;
    }

    void add(const char* str) {
        if (str != nullptr) {
            int str_len = strlen(str);
            char* temp = new char[length_ + str_len + 1];
            strcpy(temp, string_);
            strcpy(temp + length_, str);
            delete[] string_;
            string_ = temp;
            length_ += str_len;
        }
    }

    void insert(char c, int i) {
        if (i < 0 || i > length_) return;
        char* temp = new char[length_ + 2];
        strncpy(temp, string_, i);
        temp[i] = c;
        strcpy(temp + i + 1, string_ + i);
        delete[] string_;
        string_ = temp;
        length_++;
    }

    void insert(const char* str, int i) {
        if (str == nullptr || i < 0 || i > length_) return;
        int str_len = strlen(str);
        char* temp = new char[length_ + str_len + 1];
        strncpy(temp, string_, i);
        strcpy(temp + i, str);
        strcpy(temp + i + str_len, string_ + i);
        delete[] string_;
        string_ = temp;
        length_ += str_len;
    }

    void del(int i) {
        if (i < 0 || i >= length_) return;
        char* temp = new char[length_];
        strncpy(temp, string_, i);
        strcpy(temp + i, string_ + i + 1);
        delete[] string_;
        string_ = temp;
        length_--;
    }

    void del(int i, int j) {
        if (i < 0 || j >= length_ || i > j) return;
        int del_len = j - i + 1;
        char* temp = new char[length_ - del_len + 1];
        strncpy(temp, string_, i);
        strcpy(temp + i, string_ + j + 1);
        delete[] string_;
        string_ = temp;
        length_ -= del_len;
    }

    int search(const char* str) const {
        if (str == nullptr) return -1;
        const char* found = strstr(string_, str);
        if (found == nullptr) return -1;
        return found - string_;
    }