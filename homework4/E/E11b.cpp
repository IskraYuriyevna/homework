#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdexcept>

class Vec {
    size_t size;
    double* data;

public:
    // 构造函数
    Vec(size_t n, const double* arr = nullptr) : size(n), data(new double[n]) {
        if (arr) {
            std::copy(arr, arr + n, data);
        } else {
            std::fill(data, data + n, 0.0);
        }
    }

    // 拷贝构造函数
    Vec(const Vec& other) : size(other.size), data(new double[other.size]) {
        std::copy(other.data, other.data + size, data);
    }

    // 析构函数
    ~Vec() {
        delete[] data;
    }

    // 赋值运算符
    Vec& operator=(const Vec& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new double[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    // 向量加法
    Vec operator+(const Vec& other) const {
        check_size(other);
        Vec result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // 向量减法
    Vec operator-(const Vec& other) const {
        check_size(other);
        Vec result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // 标量乘法（右乘）
    Vec operator*(double scalar) const {
        Vec result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    // 标量乘法（左乘）
    friend Vec operator*(double scalar, const Vec& vec) {
        return vec * scalar;
    }

    // 相等比较
    bool operator==(const Vec& other) const {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    // 输出流
    friend std::ostream& operator<<(std::ostream& os, const Vec& vec) {
        os << "(";
        for (size_t i = 0; i < vec.size; ++i) {
            os << vec.data[i];
            if (i < vec.size - 1) os << ",";
        }
        os << ")";
        return os;
    }

    // 下标访问
    double& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // const下标访问
    const double& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // 设置元素值
    void set(double value, size_t index) {
        if (index < size) data[index] = value;
    }

    // 获取元素值
    double get(size_t index) const {
        return index < size ? data[index] : 0.0;
    }

    // 欧几里得范数
    double euc_norm() const {
        double sum = 0.0;
        for (size_t i = 0; i < size; ++i) {
            sum += data[i] * data[i];
        }
        return std::sqrt(sum);
    }

    // 最大范数
    double max_norm() const {
        if (size == 0) return 0.0;
        double max = std::fabs(data[0]);
        for (size_t i = 1; i < size; ++i) {
            max = std::max(max, std::fabs(data[i]));
        }
        return max;
    }

    // 打印向量
    void print() const {
        std::cout << *this << std::endl;
    }

    // 获取向量大小
    size_t get_size() const { return size; }

private:
    void check_size(const Vec& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vector sizes don't match");
        }
    }
};