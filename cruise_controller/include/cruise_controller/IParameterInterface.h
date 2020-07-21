#include <string>
#include <iostream>

namespace cruise_controller
{
    template<typename M>
    class ICalculatorInterface
    {
        public:
        virtual M calculate(M,float,float)=0;
    }

}
