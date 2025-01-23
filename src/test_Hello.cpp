
#include <print>
#include "Hello.hpp"


int main(){
    std::println("-- Test classe Hello --");  /** Affichage */

    /** Test Default Ctor - Standard object */
    Hello Inconnu{};
    Inconnu.SayHello();

    /** Test Default Ctor - const object */
    const Hello constInconnu{};
    constInconnu.SayHello();

    /** Test standard Ctor - Standard object */
    Hello Toto{"Toto"};
    Toto.SayHello();

    /** Test standard Ctor - const object */
    const Hello constToto{"Toto const"};
    constToto.SayHello();

    /** test Copy Ctor */
    Hello   TwinToto{Toto};
    TwinToto.SayHello();

    /** test copy Operator   */
    Hello   SecondTwinToto = Toto;
    SecondTwinToto.SayHello();

    /** test move Ctor  */
    Hello   SurvivingToto{std::move(Toto)};
    SurvivingToto.SayHello();
    Toto.SayHello();        /** Toto is no longer usable  */

    /** test move operator  */
    Hello SecondSurvivor = std::move(TwinToto);     /** Cannot use Toto anymore, but we have remaining twins :) */
    SecondSurvivor.SayHello();
    TwinToto.SayHello();                            /** TwinToto is no longer available     */

    return 0;
}

