#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class VecException {
private:
    char *comment;
public:
    VecException(const char *error) {
        if (error == nullptr) {
            comment = nullptr;
        } else {
            comment = new char[strlen(error) + 1];
            strcpy(comment, error);
        }
    }

    char *getComment() const {
        return comment;
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
};

Vec::Vec(int l, const double *v_ptr) {
    if (l <= 0) throw VecException("length error");
    v = new double[l];
    for (int i = 0; i < l; i++) v[i] = (v_ptr != nullptr ? v_ptr[i] : 0.0);
    len = l;
}

Vec::Vec(const Vec &ob) {
    if (ob.len <= 0) throw VecException("length error");
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
    if (coord < 0 || coord >= len) throw VecException("coordinate error in set()");
    if (coord >= 0 && coord < len) v[coord] = arg;
}

double Vec::get(int coord) const {
    if (coord < 0 || coord >= len) throw VecException("coordinate error in get()");
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
//
//void error() {
//    double y1[3] = {1, 2, 3};
//    double y2[5] = {2, 1, 0, 5, 7};
//    Vec x(3, y1), y(5, y2), z(4);
//    Vec u = x;
//    x.get(1);
//    y.print();
//    x.print();
//    z.print();
//    u.print();
//}

int main() {
    try {
        error();
    } catch (VecException &vex) {
        cerr << "Exception: " << vex.getComment() << endl;
    } catch (...) {
        cerr << "Exception: unknown error" << endl;
    }
    return 0;
}
