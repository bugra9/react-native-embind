#include "example.h"

#include <bind.h>

using namespace emscripten;

Example::Example(int b) {
    this->b = b;
}

int Example::deneme(int a) {
    return a * b;
}

int Example::sValue() {
    return 4;
}

int Example::getB() const {
    return this->b;
}

void Example::setB(int b_) {
    this->b = b_;
}

EMSCRIPTEN_BINDINGS(ExampleBridge) {

}
