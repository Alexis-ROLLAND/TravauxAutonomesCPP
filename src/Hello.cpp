#include "Hello.hpp"

//----------------------------------------------------------------------------
void    Hello::SayHello() const noexcept{
    std::printf("Bonjour, je suis %s.\n",this->getNom().c_str());
}

