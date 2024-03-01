
#include <iostream>
#include "Hello.hpp"


int main(){
    std::cout << "-- Test classe Hello --\n";  /** Affichage */

    Hello Inconnu{};
    Inconnu.SayHello();

    const Hello constInconnu{};
    constInconnu.SayHello();

    Hello Toto{"Toto"};
    Toto.SayHello();
    
    return 0;
}

