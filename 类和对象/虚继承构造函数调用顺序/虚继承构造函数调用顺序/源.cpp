#include<iostream >

using namespace std;

class BASEA{

public: BASEA() { cout << "This is BASEA class!\n"; }

};

class BASEB{

public: BASEB() { cout << "This is BASEB class!\n"; }

};

class DERIVEA: public BASEB, virtual public BASEA{

public: DERIVEA() { cout << "This is DERIVEA class!\n"; }

};

class DERIVEB: public BASEB, virtual public BASEA{

public: DERIVEB() { cout << "This is DERIVEB class!\n"; }

};

class TOPDERIV: virtual public DERIVEB, virtual public DERIVEA{

public: TOPDERIV() { cout << "This is TOPDERIV class!\n"; }

};

int main()

{

    TOPDERIV topobj;

    return 0;

}



