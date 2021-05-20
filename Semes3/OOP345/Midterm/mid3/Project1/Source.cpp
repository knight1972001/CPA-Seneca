#include<iostream>
#include <iostream>
#include<string>

using namespace std;

template<typename T>
void add(T* t1, T* t2, T* t3, size_t size) {
    for (size_t i = 0; i < size; i++) {
        t3[i] = t1[i] + t2[i];
    }
}

template<>
void add<std::string>(std::string* t1, std::string* t2, std::string* t3, size_t size) {
    for (size_t i = 0; i < size; i++) {
        t3[i] = t1[i] + " " + t2[i];
    }
}


int main()
{
    std::string s[]{ "yes", "no", "who", "when", "why" },
        t[]{ "yes", "no", "who", "when", "why" },
        u[5]{};

    int a[]{ 1, 2, 3, 4, 5 },
        b[]{ 5, 4, 3, 2, 1 },
        c[5];

    double d[]{ 1.1, 2.2, 3.3, 4.4, 2.2 },
        e[]{ 1.1, 2.2, 3.3, 4.4, 2.2 },
        f[5];

    add(s, t, u, 5);
    for (auto& e : u)
        std::cout << e << '|';
    std::cout << std::endl;
    add(a, b, c, sizeof a / sizeof(int));
    for (auto& e : c)
        std::cout << e << ' ';
    std::cout << std::endl;
    add(d, e, f, sizeof d / sizeof(double));
    for (auto& e : f)
        std::cout << e << ' ';
    std::cout << std::endl;
}

//
//template <typename T>
//size_t find(T* arr, T element, size_t size) {
//    for (size_t i = 0; i < size; i++) {
//        if (arr[i] == element) {
//            return i;
//        }
//    }
//    return -1;
//}
////specialization for std::string
//template <>
//size_t find<std::string>(std::string* strArr, std::string str, size_t size) {
//    for (size_t i = 0; i < size; i++) {
//        if (strArr[i][0] == str[0]) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//
//
//
//int main()
//{
//    std::string str[]{ "yes", "no", "who", "when", "why" };
//    int a[]{ 1, 2, 3, 4, 5 };
//    double b[]{ 1.1, 2.2, 3.3, 4.4, 5.5 };
//
//    auto idx = find(str, std::string("who"), 5);
//    std::cout << str[idx] << std::endl;
//
//    idx = find(a, 5, sizeof a / sizeof(int));
//    std::cout << a[idx] << std::endl;
//
//    idx = find(b, 2.2, sizeof b / sizeof(double));
//    std::cout << b[idx] << std::endl;
//}