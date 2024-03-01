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
        std::string Nom{"Inconnu"}; /**< Name to be used*/

    public:
        Hello() = default;                              /**< Default Ctor is defaulted      */
        virtual ~Hello() = default;                     /**< Dtor is the defaulted one      */

        explicit Hello(std::string Nom):Nom{Nom}{};     /**< Ctor with param (std::string) */

        std::string getNom() const noexcept {return this->Nom;};    /**< getter for the name - No setter   */
        void    SayHello() const noexcept;              /**< Makes the object say Hello i'm... */
};




#endif  /*  __HELLO_HPP__ */
