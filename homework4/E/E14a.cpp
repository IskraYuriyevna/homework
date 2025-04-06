#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class VecException {
private:
    char *comment;
    int len1, len2, index;
    int errType;
public:
    VecException(const char *error, int type) { //0
        if (error == nullptr) {
            comment = nullptr;
        } else {
            comment = new char[strlen(error) + 1];
            strcpy(comment, error);
            errType = type;
        }
    }

    VecException(int l1, int l2, const char *error, int type) { //1
        if (error == nullptr) {
            comment = nullptr;
        } else {
            comment = new char[strlen(error) + 1];
            strcpy(comment, error);
            len1 = l1;
            len2 = l2;
            errType = type;
        }
    }

    VecException(int id, const char *error, int type) { //2
        if (error == nullptr) {
            comment = nullptr;
        } else {
            comment = new char[strlen(error) + 1];
            strcpy(comment, error);
            index = id;
            errType = type;
        }
    }

    char *getComment() const {
        return comment;
    }

    int getLen1() const {
        return len1;
    }

    int getLen2() const {
        return len2;
    }

    int getIndex() const {
        return index;
    }

    int getType() const {
        return errType;
    }

    ~VecException() {
        delete[] comment;
    }
};

class Vec {
private:
    double *v;
    int len;
public:
    Vec(int l, const double *v_ptr = nullptr);

    Vec(const Vec &ob);

    ~Vec();

    void set(double arg, int coord);

    double get(int coord) const;

    double euc_norm() const;

    double max_norm() const;

    void print() const;

    // +
    Vec operator+(const Vec &op) const;

    // -
    Vec operator-(const Vec &op) const;

    // *
    Vec operator*(double a) const;

    friend Vec operator*(double a, const Vec &op);

    // =
    const Vec &operator=(const Vec &op);

    // ==
    bool operator==(const Vec &op) const;

    // []
    double &operator[](int index);

    // <<
    friend ostream &operator<<(ostream &os, const Vec &op);
};

bool Vec::operator==(const Vec &op) const {
    if (len != op.len) return false;
    for (int i = 0; i < len; i++) {
        if (v[i] != op.v[i]) return false;
    }
    return true;
}

double &Vec::operator[](int index) {
    if (index < 0 || index >= len) throw VecException(index, "incorrect indexing: ", 2);
    return v[index];
}

Vec Vec::operator+(const Vec &op) const {
    if (len != op.len) throw VecException(len, op.len, "addition of vectors of different lengths: ", 1);
    Vec tmp(len);
    for (int i = 0; i < len; i++) tmp.v[i] = v[i] + op.v[i];
    return tmp;
}

Vec Vec::operator-(const Vec &op) const {
    if (len != op.len) throw VecException(len, op.len, "subtraction of vectors of different lengths: ", 1);
    Vec tmp(len);
    for (int i = 0; i < len; i++) tmp.v[i] = v[i] - op.v[i];
    return tmp;
}

Vec Vec::operator*(double a) const {
    Vec tmp(len);
    for (int i = 0; i < len; i++) tmp.v[i] = v[i] * a;
    return tmp;
}

Vec operator*(double a, const Vec &op) {
    Vec tmp(op.len);
    for (int i = 0; i < op.len; i++) tmp.v[i] = a * op.v[i];
    return tmp;
}

const Vec &Vec::operator=(const Vec &op) {
    if (this == &op) return *this;
    delete[] v;
    len = op.len;
    v = new double[len];
    for (int i = 0; i < len; i++) v[i] = op.v[i];
    return *this;
}

ostream &operator<<(ostream &os, const Vec &op) {
    os << "(";
    for (int i = 0; i < op.len; i++) {
        if (i) os << ",";
        os << op.v[i];
    }
    os << ")";
    return os;
}

Vec::Vec(int l, const double *v_ptr) {
    if (l <= 0) throw VecException("length error", 0);
    v = new double[l];
    for (int i = 0; i < l; i++) v[i] = (v_ptr != nullptr ? v_ptr[i] : 0.0);
    len = l;
}

Vec::Vec(const Vec &ob) {
    if (ob.len <= 0) throw VecException("length error", 0);
    v = new double[ob.len];
    for (int i = 0; i < ob.len; i++) v[i] = (ob.v != nullptr ? ob.v[i] : 0.0);
    len = ob.len;
}

Vec::~Vec() {
    if (v != nullptr) {
        delete[] v;
        v = nullptr;
    }
}

void Vec::set(double arg, int coord) {
    if (coord < 0 || coord >= len) throw VecException("coordinate error in set()", 0);
    if (coord >= 0 && coord < len) v[coord] = arg;
}

double Vec::get(int coord) const {
    if (coord < 0 || coord >= len) throw VecException("coordinate error in get()", 0);
    if (coord >= 0 && coord < len) return v[coord];
    return 0.0;
}

double Vec::euc_norm() const {
    double sum = 0.0;
    for (int i = 0; i < len; i++) sum += (v[i] * v[i]);
    return sqrt(sum);
}

double Vec::max_norm() const {
    double max = fabs(v[0]);
    for (int i = 1; i < len; i++) if (max < fabs(v[i])) max = fabs(v[i]);
    return max;
}

void Vec::print() const {
    cout << "(";
    for (int i = 0; i < len; i++) {
        if (i) cout << ",";
        cout << v[i];
    }
    cout << ")" << endl;
}

//void error() {
//    Vec v1(3), v2(5), v3(4);
//    v3 = v1 + v2;
//}
//void error()
//{
//    Vec v(5);
//    double a = v[7];
//}
int main() {
    try {
        error();
    } catch (VecException &vex) {
        if (vex.getType() == 0) {
            cerr << "Exception: " << vex.getComment() << endl;
        } else if (vex.getType() == 1) {
            cerr << "Exception: " << vex.getComment() << vex.getLen1() << " " << vex.getLen2() << endl;
        } else if (vex.getType() == 2) {
            cerr << "Exception: " << vex.getComment() << vex.getIndex() << endl;
        }
    } catch (...) {
        cerr << "Exception: unknown error" << endl;
    }
    return 0;
}