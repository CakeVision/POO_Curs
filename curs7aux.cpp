#include <iostream>
using namespace std;

class Stud{
    float media = 10;
public:
    string nume = "Popescu";
    Stud(string n, float m): nume(n), media(m){}
    friend ostream& operator<<(ostream& ost, Stud& s){
        ost << s.nume << "are media: " << s.media;
        return ost;
    }
    operator float(){
        return media;
    }

};

int main(){
    Stud s1("Unu", 10);
    float m; m = s1;
    cout << m;
    return 0;
}