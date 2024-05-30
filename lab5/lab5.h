#ifndef LAB5_H 
#define LAB5_H 
#include<iostream> 


template <typename T>
class CStack {
private:
    T* data;
    int n;
public:
    CStack() : n(0), data(nullptr) {}
    CStack(int size, T* arr) : n(size) {
        T* data = new T[n];
        for (int i = 0; i < n; i++) {
            data[i] = arr[i];
        }
    }
    ~CStack() {
        if (data != nullptr) {
            delete[] data;
        }
    }

    void get() {
        std::cout << "stack = ";
        for (int i = 0; i < n; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
    int getn() {
        return n;
    }
    T* getdata() {
        return data;
    }
    void push(T newvalue) {
        n++;
        T* data1 = new T[n];
        for (int i = 0; i < n - 1; i++) {
            data1[i] = data[i];
        }
        data1[n - 1] = newvalue;
        delete[] data;
        data = data1;
    }
    void pop() {
        if (n == 0) { return; }
        n--;
        T* data1 = new T[n];
        for (int i = 0; i < n; i++) {
            data1[i] = data[i];
        }
        delete[] data;
        data = data1;
    }

    bool operator==(const CStack<T>& other) const {
        if (n != other.n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!(data[i] == other.data[i])) {
                return false;
            }
        }
        return true;
    }

    CStack<T>& operator=(const CStack<T>& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        n = other.n;
        data = new T[n];
        for (int i = 0; i < n; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

};


template <typename T>
int FindElementInArray(T* arr, int n, T find) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == find)return i;
    }
    return n;
}

class CRectangle {
private:
    double a, b;
public:
    CRectangle(const CRectangle& other) : a(other.a), b(other.b) {}
    CRectangle(CRectangle&& other) noexcept : a(std::move(other.a)), b(std::move(other.b)) {}
    CRectangle(double ab, double ba) : a(ab), b(ba) {}
    CRectangle() : a(0), b(0) {}
    ~CRectangle() {}

    bool operator==(const CRectangle& other) const {
        if (a != other.a) {
            return false;
        }
        if (b != other.b) {
            return false;
        }
        return true;
    }

    CRectangle& operator=(CRectangle&& other) noexcept {
        if (this != &other) {
            a = std::move(other.a);
            b = std::move(other.b);
        }
        return *this;
    }

    CRectangle& operator=(const CRectangle& other) {
        if (this != &other) {
            a = other.a;
            b = other.b;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const CRectangle& d) {
        os << " { " << d.a << ", " << d.b << "} ";
        return os;
    }

};


#endif