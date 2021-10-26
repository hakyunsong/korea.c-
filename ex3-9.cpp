#include <iostream>
using namespace std;

class PrivateAccessError {
private:
    int a;
    void f();
    PrivateAccessError();
public:
    int b;
    PrivateAccessError(int x);
    void g();
};

PrivateAccessError::PrivateAccessError() {
    a = 1;
    b = 1;
}

PrivateAccessError::~PrivateAccessError(int x) {
    a = x;
    b = x;
}

void PrivateAccessError::f(){
    a = 5;
    b = 5;
}
void PrivateAccessError::g(){
    a=6;
    b=6; 
}
int main() {
    PrivateAccessError objA;  //privateAccessError()는  private이므로 main()에서 호출할수없다. 8번주목
    PrivateAccessError obgB(100);
    objB.a = 10; //a는 PrivateAccessError 클래스의 private 맴버이므로 main()에서 호출할수없다  6번주목
    objB.b = 20;
    objB.f(); //f()는 PrivateAccessError 클래스의 private 맴버이므로 main()에서 호출할수없다 7번주목
    objB.g();
}