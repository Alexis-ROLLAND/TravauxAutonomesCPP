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
#include <print>

constexpr       std::string DEFAULT_NAME{"Inconnu"};

class Hello{
    private:
        std::string Nom{DEFAULT_NAME};         /**< Name to be used by default   */

    public:
        /**
         * Rule of 7 (6? 0?): 
         *      Use default versions for default Ctor, Copy Ctor, Move Ctor, 
         *      copy operator, move operator and Dtor.
         * 
         *      Rule : If you have to define one of these Ctor/Operators/Dtor, 
         *              you'll have to define all of them.
         */
        Hello() = default;                              /**< Default Ctor is explicitely defaulted      */
        Hello(const Hello&) = default;                  /**< Copy Ctor is explicitely defaulted         */
        Hello(Hello&&) = default;                       /**< Move Ctor is explicitely defaulted         */
        Hello& operator=(const Hello&) = default;       /**< Copy Operator is explicitely defaulted     */
        Hello& operator=(Hello&&) = default;            /**< Move Operator is explicitely defaulted     */
        virtual ~Hello() = default;                     /**< Dtor is explicitely the defaulted one      */
        
        explicit Hello(std::string _Nom): Nom{_Nom}{};     /**< Ctor with param (std::string)           */

        [[nodiscard]] std::string getNom() const noexcept {return this->Nom;};    /**< getter for the name - No setter   */
        void    SayHello() const noexcept;              /**< Makes the object say Hello i'm... */
};




#endif  /*  __HELLO_HPP__ */

