#include "example.h"

int bugra_a(int a) {
  return 8;
}

BugraClass::BugraClass(int b) {
    this->b = b;
}
int BugraClass::deneme(int a) {
    return a * b;
}
int BugraClass::getB() const {
    return this->b;
}
void BugraClass::setB(int b_) {
    this->b = b_;
}


int Bugra3Class::waav(std::shared_ptr<BugraClass>& b, int a) {
    return b->deneme(a);
}
int Bugra3Class::oo(int d) {
    return d * 2;
}
