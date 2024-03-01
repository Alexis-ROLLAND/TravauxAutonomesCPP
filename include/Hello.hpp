/**
 *	@file	Hello.hpp
 * 	@brief 	Hello class header file
 * 	@author	Alexis ROLLAND
 * 	@date	2024-03
 * 
 */

/** Code Guards : empêche les inclusions multiples - Idem C */
#ifndef __HELLO_HPP__
#define __HELLO_HPP__

#include <string>

class Hello{
    public:
        		
    private:
        std::string Nom{"Inconnu"};

        std::string getNom() const noexcept {return this->Nom;};
    public:
        Hello() = default;
        virtual ~Hello() = default;

        explicit Hello(std::string Nom):Nom{Nom}{};

        void    SayHello() const noexcept;
};




#endif  /*  __HELLO_HPP__ */
