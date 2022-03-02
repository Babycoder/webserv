#include "utils.hpp"


class example{

    private :
       int _a = 10;
        int _b = 20;
    public:
        example(){};
        example(int a, int b){
            _a = a;
            _b = b;
        }
        ~example();
        int geta(){return _a;}
        int getb(){return _b;}
};



int     main()
{

    example *obj = new example(0, 0);

    std::cout << obj->geta() << std::endl << obj->getb() << std::endl;
    return 0;
}