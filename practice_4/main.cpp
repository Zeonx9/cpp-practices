
#define B

#ifdef A
#include <iostream>
#include "Vec3d.h"

int main() {
    Vec3d a(1, 2, 3), b(4, 5, 6);
    std::cout   << "a: " << a
                << "\nb: " << b
                << "\na+b: " << a + b
                << "\na * (-0.6) " << a * -0.6
                << "\na * b" << a * b
                << "\na & b" << (a & b) << "\n";
}
#endif

#ifdef B
#include <iostream>
#include "DynArray.h"

int main() {
    DynArray a {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << a << "\n";
    if (a.getSize() > 3) {
        DynArray b = a;
        b.append(-10);
        std::cout << b << "\n";
        std::cout << DynArray::getCountObjects() << "\n";
    }
    std::cout << DynArray::getCountObjects() << "\n";

}
#endif
