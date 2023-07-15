#include "example.h"

#include <bind.h>

using namespace emscripten;


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


EMSCRIPTEN_BINDINGS(ExampleBridge) {
    function("bugra_a", &bugra_a);

    class_<BugraClass>("BugraClass")
        .smart_ptr_constructor("BugraClass", &std::make_shared<BugraClass, int>)
        .function("deneme", &BugraClass::deneme)
        .property("b", &BugraClass::getB, &BugraClass::setB)
        ;

    class_<Bugra2Class, emscripten::base<BugraClass>>("Bugra2Class")
        .smart_ptr_constructor("Bugra2Class", &std::make_shared<Bugra2Class, int>)
        ;

    class_<Bugra3Class>("Bugra3Class")
        .class_function("waav", &Bugra3Class::waav)
        .class_function("oo", &Bugra3Class::oo)
        ;
}
