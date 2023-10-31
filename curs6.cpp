// #include <iostream>
// using namespace std;


//supraincarcare prin functie independenta
// class Pers{
//     int varsta = 20;    
//     friend ostream & operator<<(ostream& ost, Pers & p){
//         ost << p.varsta;
//         return ost;
//     }
//     friend const Pers operator++(Pers& p, int){
//         Pers aux; aux = p;
//         p.varsta++;
//         return aux;
//     }

//     friend const Pers& operator++(Pers& p){
//         p.varsta++;
//         return p;
//     }
// public:
//     Pers(){

//     }
// };

// int main(){
//     Pers p1; Pers p2;
//     ++p1;
//     cout << p1;
//     operator++(p1);
//     cout << p1;
//     operator++(p1,1);

//     operator++(p2, 1); cout << p2;

//     return 0;
// }

#include <iostream>
using namespace std;

class Pers {
    int varsta = 20;
    friend ostream& operator<<(ostream& ost, Pers& p ){
        ost << p.varsta;
        return ost;
    }
    public:
    const Pers* operator++(int){
        this->varsta++;
        return this;

    }
};