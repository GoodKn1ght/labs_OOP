#include"lab4.h" 
#include<math.h> 

void plus1(int** d, int k) {
    int* f = new int[k + 1];
    for (int i = 0; i < k; i++) {
        f[i] = (*d)[i];
    }
    delete[] * d;
    *d = f;
}

CMultiSet::CMultiSet(int a, int* ads) {
    n = a;
    address = new int[n];
    for (int i = 0; i < n; ++i) {
        address[i] = ads[i];
    }
}
CMultiSet::CMultiSet(int d) {
    n = d;
    address = (int*)new int[n];
}
CMultiSet::CMultiSet(CMultiSet& other) : n(other.n) {
    address = new int[n];
    for (int i = 0; i < n; ++i) {
        address[i] = other.address[i];
    }
}

CMultiSet::CMultiSet(CMultiSet&& other) noexcept :n(0), address(nullptr) {
    n = other.n;
    address = other.address;
    other.n = 0;
    other.address = nullptr;
}

CMultiSet::~CMultiSet() {
    delete[] address;
    address = nullptr;
    n = 0;
}


void CMultiSet::set(int p) {
    n = p;
}

void CMultiSet::setA(int* p) {
    address = new int[n];
    for (int i = 0; i < n; ++i) {
        address[i] = p[i];
    }
}

int* CMultiSet::getA() {
    return address;
}


int CMultiSet::findN(int k) {
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (address[i] == k)p++;
    }
    return p;
}

int CMultiSet::power() {
    return n;
}

int CMultiSet::max() {
    int p = address[0];
    for (int i = 1; i < n; i++) {
        if (address[i] > p)p = address[i];
    }
    return p;
}

int CMultiSet::min() {
    int p = address[0];
    for (int i = 1; i < n; i++) {
        if (address[i] < p)p = address[i];
    }
    return p;
}

void CMultiSet::add(int a) {
    int* ptr = new int[n + 1];
    for (int i = 0; i < n; i++) {
        ptr[i] = address[i];
    }
    ptr[n] = a;
    delete[] address;
    address = ptr;
    n++;
}

void CMultiSet::dele() {
    int* ptr = (int*) new int[n - 1];
    for (int i = 0; i < n - 1; i++) {
        ptr[i] = address[i];
    }
    delete[] address;
    address = ptr;
    n--;
}

CMultiSet CMultiSet::operator+(CMultiSet a) {
    int k = 0;
    int* newone = (int*)new int[a.n + n];
    for (int i = 0; i < a.n + n; i++) {
        if (i < n) {
            newone[i] = address[i];
            k++;
        }
        else {
            newone[k] = a.address[i - n];
            k++;
        }
    }
    return CMultiSet(k, newone);
}

CMultiSet CMultiSet::operator-(CMultiSet a) {
    CMultiSet f = *this / a;
    CMultiSet d = *this + a;
    int k = 0;
    int* newone = nullptr;
    for (int i = 0; i < d.n; i++) {
        int yes = 0;
        for (int j = 0; j < f.n; j++) {
            if (d.address[i] == f.address[j]) {
                yes = 1;
                break;
            }
        }
        if (!yes) {
            plus1(&newone, k);
            newone[k] = d.address[i];
            k++;
        }
    }
    return CMultiSet(k, newone);
}


CMultiSet CMultiSet::operator/(CMultiSet a) {
    int k = 0;
    int* newone = NULL;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a.n; j++) {
            if (address[i] == a.address[j]) {
                plus1(&newone, k);
                newone[k] = address[i];
                k++;
            }
        }
    }
    return CMultiSet(k, newone);
}

std::istream& operator>>(std::istream& in, CMultiSet& a) {
    for (int i = 0; i < a.n; i++) {
        in >> a.address[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const CMultiSet& a) {
    out << "ur massive = { ";
    for (int i = 0; i < a.n; i++) {
        out << a.address[i];
        if (i != a.n - 1) {
            out << ", ";
        }
    }
    out << " }\n";
    return out;
}

CMultiSet& CMultiSet::operator=(const CMultiSet& other) {
    if (this != &other) {
        delete[] address;
        n = other.n;
        address = new int[n];
        for (int i = 0; i < n; ++i) {
            address[i] = other.address[i];
        }
    }
    return *this;
}

CMultiSet& CMultiSet::operator=(CMultiSet&& other) noexcept {
    if (this != &other) {
        delete[] address;
        n = other.n;
        address = other.address;
        other.n = 0;
        other.address = nullptr;
    }
    return *this;
}