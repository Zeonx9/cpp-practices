#define A

#ifdef A
#include <iostream>
int factorial(int n) {
    if (n < 2)
        return 1;
    int x = 1;
    for (int i = 2; i <= n; ++i)
        x *= i;
    return x;
}

int main() {
    int x;
    std::cin >> x;
    std::cout << factorial(x);
}
#endif

#ifdef B
#include <iostream>
#include <cmath>

int main() {
    long double a, b, c, D;
    std::cin >> a >> b >> c;

    if (a == 0 && b == 0) {
        std::cout << (c == 0 ? "Any real number\n" : "No solution\n");
        return 0;
    }
    if (a == 0) {
        std::cout << -c / b;
        return 0;
    }

    D = b * b - 4 * a * c;
    if (D < 0) {
        std::cout << "No real roots\n";
        return 0;
    }
    if (D == 0) {
        std::cout << - b / a / 2;
        return 0;
    }

    D = sqrtl(D);
    std::cout <<  (-b + D) / a / 2 << std::endl << (-b - D) / a / 2;
}
#endif

#ifdef C
#include <iostream>

bool isPrime(int x) {
    x = abs(x);
    if (x == 2 or x == 3)
        return true;
    if (x % 2 == 0 or x % 3 == 0 or x < 2)
        return false;

    int i = 5;
    while (i * i <= x) {
        if (x % i == 0 or x % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

int main() {
    for (int i = 0; i <= 100; ++i) {
        if (isPrime(i)) {
            std::cout << i << std::endl;
        }
    }
}
#endif

#ifdef D
#include <iostream>

void printBin(int x) {
    if (x < 2) {
        std::cout << x;
        return;
    }
    printBin(x / 2);
    std::cout << x % 2;
}

int main() {
    int n;
    std::cin >> n;
    printBin(n);
}
#endif

#ifdef F
#include <iostream>

int main() {
    double a, q, e;
    std::cin >> a >> q >> e;

    q *= q;
    auto res = 0.0, s = a;
    while (s > e) {
        res += s;
        s *= q;
    }

    std::cout << res;
}
#endif

#ifdef G
#include <iostream>

int main() {
    char c;
    std::cin >> c;
    std::cout << ('a' <= c and c <= 'z' or 'A' <= c and c <= 'Z' ? "Letter\n" : "Non-letter");
}
#endif
