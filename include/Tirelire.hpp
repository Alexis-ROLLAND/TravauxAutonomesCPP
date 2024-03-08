/**
 *	@file	
 * 	@brief 	
 * 	@author	Alexis ROLLAND
 * 	@date	2024-03
 * 
 */

/** Code Guards : empêche les inclusions multiples - Idem C */
#ifndef __TIRELIRE_HPP__
#define __TIRELIRE_HPP__

#include <iostream>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <algorithm>

class Tirelire{
    public:
        enum class Piece : uint8_t {
            ONECENT = 1,
            TWOCENTS = 2,
            FIVECENTS = 5,
            TENCENTS = 10,
            TWENTYCENTS = 20,
            FIFTYCENTS = 50,
            ONEEURO = 100,
            TWOEUROS = 200
        };        		
    private:
        std::vector<Piece> Vault{};
        [[nodiscard]] bool isCoinValid(Piece Coin) noexcept;

    public:
        Tirelire() = default;
        virtual ~Tirelire() = default;

        [[nodiscard]]   bool    estVide() noexcept {return this->Vault.empty();};
        [[nodiscard]]   int     getNbCoins() noexcept {return this->Vault.size();};    
        void    Add(Piece Coin);
        
        [[nodiscard]]   unsigned int    getTotal() noexcept;  
        [[nodiscard]]   unsigned int    countCoins(Piece CoinType) noexcept {return  std::count (this->Vault.begin(), this->Vault.end(), CoinType);};  
        void    retrieve(Piece CoinType);

        void    dump();
};




#endif  /*  __TIRELIRE_HPP__ */
