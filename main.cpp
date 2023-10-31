#include <iostream>
#include <string>
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
    static int nrPers;
public:
    string nume = "Anonim";
    int nrJoburi = 0;
    double * pVenituri = nullptr;
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
    Pers( const char* n ="Noname", double s = 0.0, int nrJ=0, double * pV = nullptr) 
    : marca(++nrPers), salariu(s)
    {
        nume = n;
        if(nrJ >0){
            nrJoburi = nrJ;
            pVenituri = new double[nrJoburi];
            for (int i = 0; i <nrJoburi; i++){
                pVenituri[i] = pV[i];
            }
        }
    }//if one has default value, all of them need it| aka python better 
    
    
    /* CURS 1-3
    Pers( int m = 200, const char* n ="Noname", double s = 0.0) : marca(m), salariu(s)
    {
        nume = n;
    }*/
    //apelul marca(m) si salariu(s) apeleaza constructorul tipilui variabilei.

    // ostream & operator <<(ostream &ost, Pers &p) has too many params. It has 3,
    // because it implicitly recieves p from being declared in the class Pers
    
    //friend says it's an independent function from the class
    // and has access rights to all objects of this class
    friend ostream& operator<<(ostream &ost, Pers &p){
        ost << "\n" << p.marca << " " << p.nume << " " << p.salariu << " lei";
        ost << "\n\tVenituri:";
        for (int i = 0; i <p.nrJoburi; i++){
                ost << p.pVenituri[i] << " ";
            }
        return ost;
    }
    void display(){
        // cout is an obj.
        //printf(" \n %d %s %lf", marca , nume ,salariu);
        cout << "\n" << marca << " " << nume << " " << salariu << " lei";
    }

    ~Pers(){
        if(nrJoburi > 0){
            delete pVenituri;
        }
    }

    static int getNrPers(){
        return nrPers;
    }

    Pers(const Pers& src) 
    :marca(++nrPers), salariu(src.salariu), nume(src.nume)
    {
        nrJoburi =src.nrJoburi;
    
    }
    int getMarca(){
        return marca;
    }
    void setNume(const char* pn){
        if(strlen(pn) < 49){
            nume = pn;
        }
        else cerr << "\n Numele depaseste capacitatea (49).";
    }

};

// //CURS 2 ---------------------------------------------
// int main(){

//     int x(10), y =20 ,&py = y, *px = &x;
//     Pers p, p2(10, "Hello", 2500), p3 = p2;
//     //echivalent cu un pointer dereferit
//     //bun doar pt usurarea scrierii
//     //proces referinte: ref ->(deref automat adresa) valoarea din y
//     py =7;
//     // process pointer: pointer -> adr ->(prin deref) valoare x
//     cout << *px;




//     p.display();
//     cout << endl << p << p2;

//     getchar();

//     /*
//     explicatie Pers : marca(m)
//     apelam un constructor de int 

//     Ex: int x(10), y=20;

//     distinctie dintre initializare si atribuire
//     */

//    /*
//    p2(...) diferit de p2 = Pers(...)
//      1                         2
//     1. se aloca pe stiva
//     2. se aloca drept constanta

//  */
// }
// //CURS 2 -------------------------------------------------

//CURS 3 ---------------------------------------------
/*int main(){

    int x(10), y =20 ,&py = y, *px = &x;
    Pers p, p2(10, "Hello", 2500), p3 = p2;
    
    //echivalent cu un pointer dereferit
    //bun doar pt usurarea scrierii
    //proces referinte: ref ->(deref automat adresa) valoarea din y
    py =7;
    // process pointer: pointer -> adr ->(prin deref) valoare x
    cout << *px;

    //{} forteaza durata de viata a var declarate in interior
    //Ex:
    // {
    //     Pers p10 = new Pers(100, "Exemplu", 12.0);
    // }np = p10;
    // codul nu va rula pt ca p10 nu e definit( a fost distrus)
    {
        Pers p10 = Pers(100, "Nume", 12.0);
        Pers vectPers[15]{Pers(110, "Hello"), Pers(120, "I'm Andrew" ,32.2), p2};
        
        //
        strcpy(vectPers[2].nume, "Modificat");
        // se distruge doar pointerul pp, nu si obiectul nou
        //obiectul este alocat pe heap si prin aceasta declarare cauzam memory leak
        Pers *pp = new Pers(5000, "5k", 5000);
        //adaugam delete ca sa oprim problema
        delete pp;

        Pers* vectPointerPers[15]{ new Pers(110, "Hello"), new Pers(120, "I'm Andrew" ,32.2)};

        cout << "\n din  VectPointeri " << /* optiuni: vpp[1]->nume | (*vectPointerPers[1]).nume  *(*(*vectPointerPers+1)).nume; 
        
    } 


    //optiuni mutare val intr-o var
    // Ex: p15 <- p5

    //necesita overload la op  = in clasa pers
    //p15 = p5; 

    //Apelam constructorul pers
    //Pers p15(p5);

    //

    p.display();
    cout << endl << p << p2;
    getchar();



}
*/
//CURS 3 _________________________________________________


//CURS 4 -------------------------------------------------

/*
INFORMATII DESPRE STATIC 
 -> static e folosit pentru variabile asociate cu clasa, dar care cotin detalii despre mai mult decat un obiect
 -> static nu este alocat de catre clasa
 -> aplicarea modificatorului static pe o metoda o face sa nu aiba acces la pointerul this
 -> :: operator de "rezolutie"
*/

int Pers::nrPers = 0;

int main(){
    int x(10), y =20;
    Pers p1, p2("Dutu Carmen", 5000);
    cout << endl << p1;
    Pers::getNrPers();
    double pV[] = {8500 ,5700, 6900};
    Pers p4("Patrulescu Ion", 4000, 3, pV);
    cout << p4;
    return 0;
}


//CURS 4 _________________________________________________