#include <iostream>
#include <string.h>

using namespace std;

//CURS 2 -----------------------------------------------------

//all member functions recieve a ref to the class
class Pers {
    // default access is private
    //methods by the current class

    //childred have access to protected
    
    // all methods can access public

    // alocarea in place la definire plaseaza alocarea acelor variabile in fata constructorului
protected:
    const int marca = 100;
public:
    char nume[50] = "Anonim";
private:
    double salariu = 3500;
public:
    //Pers(){}

    // Pers( int m, const char* n, double s){
    //     marca = m;
    //     //unsafe, if not in electron compiler use strcpy_s
    //     strcpy(nume, n);
    //     salariu = s;
    // }

    //will have conflit with Pers(){}, just remove it
    //if one has default value, all of them need it| aka python better 
    Pers( int m = 200, const char* n ="Noname", double s = 0.0) : marca(m), salariu(s)
    {
        strcpy(nume,n); 
    }
    //apelul marca(m) si salariu(s) apeleaza constructorul tipilui variabilei.

    // ostream & operator <<(ostream &ost, Pers &p) has too many params. It has 3,
    // because it implicitly recieves p from being declared in the class Pers
    
    //friend says it's an independent function from the class
    // and has access rights to all objects of this class
    friend ostream& operator<<(ostream &ost, Pers &p){
        ost << "\n" << p.marca << " " << p.nume << " " << p.salariu << " lei";
    }

    void display(){
        // cout is an obj.
        //printf(" \n %d %s %lf", marca , nume ,salariu);
        cout << "\n" << marca << " " << nume << " " << salariu << " lei";
    }

};

//CURS 2 ---------------------------------------------
int main(){
    Pers p, p2(10, "Hello", 2500);

    p.display();
    cout << endl << p << p2;

    getchar();

    /*
    explicatie Pers : marca(m)
    apelam un constructor de int 

    Ex: int x(10), y=20;

    distinctie dintre initializare si atribuire
    */

   /*
   p2(...) diferit de p2 = Pers(...)
     1                         2
    1. se aloca pe stiva
    2. se aloca drept constanta

 */
}
//CURS 2 -------------------------------------------------