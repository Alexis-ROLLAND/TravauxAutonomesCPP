#include "Hello.hpp"

//----------------------------------------------------------------------------
void    Hello::SayHello() const noexcept{
    // std::printf("Bonjour, je suis %s.\n",this->getNom().c_str());    /** Before C++23 */
    std::println("Bonjour, je suis {0:}.",this->getNom().c_str());      /** With C++23 fully enabled */
}



