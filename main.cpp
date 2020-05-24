#include <iostream>
#include <string.h>
#include <math.h>
#include <typeinfo>

using namespace std;

//Declarari -----------------------

template <class Type>
class Pret;

template <class Type>
istream& operator>> (istream& in, Pret<Type>&);

template <class Type>
ostream& operator<< (ostream& out, const Pret<Type> &);

//---------------------------------

template <class Type>
class Pret
{
protected:
    Type pret;
    double km;
public:
    Pret();
    Pret (Type, double);
    Pret (const Pret<Type> &);
    virtual ~Pret() {};
    Type get_pret();
    virtual void citire (istream &);
    virtual void afisare (ostream &) const;
    void set_pret (Type p);
    double get_km();
    void set_km (double);
    Pret<Type> operator= (const Pret<Type> &);
    Pret<Type> operator+ (const Pret<Type> &);
    Pret<Type> operator* (const int &);
    friend istream& operator>> <Type> (istream& in, Pret<Type>&);
    friend ostream& operator<< <Type> (ostream& out, const Pret<Type> &);
};

template <class Type>
istream& operator>> (istream &in, Pret<Type>& P)
{
    P.citire (in);
    return in;
}

template <class Type>
ostream& operator<< (ostream &out, const Pret<Type> &P)
{
    P.afisare (out);
    return out;
}

template <class Type>
Pret<Type>::Pret(): pret (0), km (0) {}

template <class Type>
Pret<Type>::Pret (Type apret, double akm): pret (apret)
{
    try
    {
        if (akm < 0)
            throw akm;
        km = akm;
    }
    catch (double a)
    {
        cout << "Km nu poate avea o valoare negativa";
    }
}

template <class Type>
Pret<Type>::Pret (const Pret<Type> &p)
{
    pret = p.pret;
    km = p.km;
}

template <class Type>
Pret<Type> Pret<Type>::operator* (const int &p)
{
    try
    {
        if (p < 0)
            throw p;
    }
    catch (int p)
    {
        cout << "Nu pot inmulti cu un numar negati";
    }
    Pret<Type> Prod;
    Prod.pret = pret * p;
    Prod.km = km * p;
    return Prod;
}

template <class Type>
Pret<Type> Pret<Type>::operator= (const Pret<Type> &P)
{
    pret = P.pret;
    km = P.km;
    return *this;
}

template <class Type>
Pret<Type> Pret<Type>::operator+ (const Pret<Type> &P)
{
    Pret<Type> Suma;
    Suma.pret = pret + P.pret;
    Suma.km = km + P.km;
    return Suma;
}


template <class Type>
double Pret<Type>::get_km()
{
    return km;
}

template <class Type>
void Pret<Type>::set_km (double akm)
{
    try
    {
        if (akm < 0)
            throw akm;
        km = akm;
    }
    catch (double akm)
    {
        cout << "Numarul de km nu poate fi o valoare negativa" << endl;
    }
}

template <class Type>
Type Pret<Type>::get_pret()
{
    return pret;
}

template <class Type>
void Pret<Type>::set_pret (Type p)
{
    try
    {
        if (p < 0)
            throw p;
        pret = p;
    }
    catch (Type p)
    {
        cout << "Pretul nu poate fi o valoare negativa" << endl;
    }
}

template <class Type>
void Pret<Type>::citire (istream & in)
{
    Type p;
    cout << "Pret: ";
    in >> p;
    try
    {
        if (p < 0)
            throw p;
        pret = p;
    }
    catch (Type p)
    {
        cout << "Pretul nu poate fi o valoare negativa" << endl;
    }
}

template <class Type>
void Pret<Type>::afisare (ostream &out) const
{
    out << pret << endl;
}

template <class Type>
class Pret_Comanda_online: public Pret <Type>
{
public:
    ~Pret_Comanda_online() {};
    void citire (istream &);
    void afisare (ostream &) const;
    Pret_Comanda_online();
    Pret_Comanda_online (int, Type);
    Pret_Comanda_online (const Pret_Comanda_online &);
    Pret_Comanda_online<Type> operator= (const Pret_Comanda_online&);
};

template <class Type>
Pret_Comanda_online<Type>::Pret_Comanda_online(): Pret<Type>() {}

template <class Type>
Pret_Comanda_online<Type>::Pret_Comanda_online (int akm, Type p): Pret<Type> (p, akm) {}

template <class Type>
Pret_Comanda_online<Type>::Pret_Comanda_online (const Pret_Comanda_online<Type> & PC): Pret<Type> (PC) {}

template <class Type>
Pret_Comanda_online<Type> Pret_Comanda_online<Type>::operator= (const Pret_Comanda_online &PC)
{
    this->Pret<Type>::set_km (PC.km);
    Pret<Type>::set_pret (PC.Pret<Type>::pret);
    return *this;
}

template <class Type>
void Pret_Comanda_online<Type>::citire (istream & in)
{
    this->Pret<Type>::citire (in);
    cout << "Numar km: ";
    try
    {
        in >> this->Pret<Type>::km;
        if (this->Pret<Type>::km < 0)
            throw this->Pret<Type>::km;
    }
    catch (double a)
    {
        cout << "Numarul de km nu poate fi o valoare negativa";
    }
}

template <class Type>
void Pret_Comanda_online<Type>::afisare (ostream &out) const
{
    this->Pret<Type>::afisare (out);
}

template <class Type>
class Pret_Comanda_offline: public Pret<Type>
{
public:
    Pret_Comanda_offline();
    Pret_Comanda_offline (Pret<Type>);
    Pret_Comanda_offline (const Pret_Comanda_offline<Type>&);
    ~Pret_Comanda_offline() {};
    Pret_Comanda_offline<Type> operator= (const Pret_Comanda_offline<Type> &);
    void citire (istream &);
    void afisare (ostream &) const;
};

template <class Type>
Pret_Comanda_offline<Type>::Pret_Comanda_offline(): Pret<Type>() {}

template <class Type>
Pret_Comanda_offline<Type>::Pret_Comanda_offline (Pret<Type> p): Pret<Type> (p) {}

template <class Type>
Pret_Comanda_offline<Type>::Pret_Comanda_offline (const Pret_Comanda_offline<Type> &p): Pret<Type> (p) {}

template <class Type>
Pret_Comanda_offline<Type> Pret_Comanda_offline<Type>::operator= (const Pret_Comanda_offline<Type> &p)
{
    this->Pret<Type>::operator= (p);
}

template <class Type>
void Pret_Comanda_offline<Type>::citire ( istream & in)
{
    this->Pret<Type>::citire (in);
}

template <class Type>
void Pret_Comanda_offline<Type>::afisare (ostream &out) const
{
    this->Pret<Type>::afisare (out);
}

//Declarari-----------------
template <class Type>
class Ingrediente;

template <class Type>
istream& operator>> (istream& in, Ingrediente<Type> &I);

template <class Type>
ostream& operator<< (ostream& out, const Ingrediente<Type> &I);
//----------------------------

template <class Type>
class Ingrediente
{
    char *denumire;
    int cantitate;
    Pret <Type>pret_unitar;
public:
    Ingrediente();
    Ingrediente (char *, int, Pret<Type>);
    ~Ingrediente();
    Ingrediente (const Ingrediente<Type>&);
    Ingrediente operator= (const Ingrediente<Type>&);
    friend istream& operator>> <Type> (istream&, Ingrediente<Type> &);
    friend ostream& operator<< <Type> (ostream&, const Ingrediente<Type> &);
    Pret<Type> get_pret_unitar() const;
    int get_cantitate() const;
};

template <class Type>
Pret<Type> Ingrediente<Type>::get_pret_unitar() const
{
    return pret_unitar;
}

template <class Type>
int Ingrediente<Type>::get_cantitate() const
{
    return cantitate;
}

template <class Type>
Ingrediente<Type> Ingrediente<Type>::operator= (const Ingrediente<Type> &I)
{
    if (denumire != NULL)
        delete []denumire;
    denumire = new char[strlen (I.denumire) + 1];
    strcpy (denumire, I.denumire);
    cantitate = I.cantitate;
    pret_unitar = I.pret_unitar;
    return *this;
}

template <class Type>
Ingrediente<Type>::~Ingrediente()
{
    if (denumire != NULL)
        delete []denumire;
    cantitate = 0;
}

template <class Type>
Ingrediente<Type>::Ingrediente()
{
    denumire = NULL;
    cantitate = 0;
}


template <class Type>
Ingrediente<Type>::Ingrediente (const Ingrediente& I)
{
    denumire = new char[strlen (I.denumire) + 1];
    strcpy (denumire, I.denumire);
    cantitate = I.cantitate;
}

template <class Type>
Ingrediente<Type>::Ingrediente (char *adenumire, int acantitate, Pret<Type> apret_unitar): pret_unitar (apret_unitar)
{
    if (adenumire != NULL)
    {
        denumire = new char [strlen (adenumire) + 1];
        strcpy (denumire, adenumire);
    }
    try
    {
        if (acantitate < 0)
            throw acantitate;
    }
    catch (int a)
    {
        cout << "Cantitatea nu poate sa fie negativa";
    }
}

template <class Type>
istream& operator>> (istream& in, Ingrediente<Type> &I)
{
    cout << "Ingredient: " << endl;
    cout << "Denumire: ";
    if (I.denumire != NULL)
        delete []I.denumire;
    I.denumire = new char [50];
    in >> I.denumire;
    cout << "Cantitate: ";
    in >> I.cantitate;
    try
    {
        if (I.cantitate < 0)
            throw I.cantitate;
    }
    catch (int a)
    {
        cout << "Cantitea nu poate fi un numar negativ";
    }
    in >> I.pret_unitar;
    return in;
}

template <class Type>
ostream& operator<< (ostream &out, const Ingrediente<Type> &I)
{
    out << I.denumire << " " << I.cantitate << " ";
    out << I.pret_unitar;
    out << endl;
    return out;
}


class Produs
{
public:
    virtual void calcul() = 0;
};

//Declarare--------------------------

template <class Type>
class Pizza;

template <class Type>
istream& operator>> (istream&, Pizza<Type>&) ;

template <class Type>
ostream& operator<< (ostream&, const Pizza<Type> &);

//-----------------------------------

template <class Type>
class Pizza: public Produs
{
    char *tip_pizza;
    int nr_ingrediente;
    Ingrediente<Type> *I;
    Pret<Type> *pret;  ///Asta se calculeaza separat
    Pret<Type> manopera;
    bool Comanda;//1-online, 0-offline
public:
    Pizza (char *, int, Ingrediente<Type>*, Pret<Type>, Pret<Type>, bool);
    virtual ~Pizza();
    Pizza();
    Pizza (const Pizza<Type> &);
    void operator= (const Pizza<Type> &);
    virtual void citire (istream &);
    virtual void afisare (ostream&) const;
    void calcul();
    friend istream& operator>> <Type> (istream&, Pizza<Type>&) ;
    friend ostream& operator<< <Type> (ostream&, const Pizza<Type> &);
    Pret<Type>* get_Pret();
};

template <class Type>
Pret<Type>* Pizza<Type>::get_Pret()
{
    return pret;
}

template <class Type>
istream& operator>> (istream &in, Pizza<Type>& P)
{
    P.citire (in);
    return in;
}

template <class Type>
ostream& operator<< (ostream &out, const Pizza<Type> & P)
{
    P.afisare (out);
    return out;
}

template <class Type>
void Pizza<Type>::calcul()
{
    Pret<Type> *pret_toate_ingrediente = new Pret<Type>;
    int i;
    for (i = 0; i < nr_ingrediente; i++)
    {
        *pret_toate_ingrediente = I[i].get_pret_unitar() * I[i].get_cantitate() + *pret_toate_ingrediente;
    }
    *pret_toate_ingrediente = *pret_toate_ingrediente + manopera;
    if (Comanda == 1)
    {
        double km = (*pret).get_km();
        int nr_ori = floor (km / 10);
        double pret_total = (*pret_toate_ingrediente).get_pret();
        for (i = 1; i <= nr_ori; i++)
            pret_total = pret_total * 0.05 + pret_total;
        (*pret_toate_ingrediente).set_pret ((Type)pret_total);
        (*pret_toate_ingrediente).set_km (km);
        *pret = * ((Pret_Comanda_online<Type>*)pret_toate_ingrediente);
    }
    else
    {
        *pret = * ((Pret_Comanda_offline<Type>*)pret_toate_ingrediente);
    }
    delete pret_toate_ingrediente;
}

template <class Type>
Pizza<Type>::Pizza()
{
    tip_pizza = NULL;
    I = NULL;
    nr_ingrediente = 0;
    pret = NULL;
    manopera.set_pret (0);
    Comanda = 0;
}

template <class Type>
Pizza<Type>::Pizza (char *atip_pizza, int anr_ingrediente, Ingrediente<Type> *aI, Pret<Type> apret, Pret<Type> amanopera, bool aComanda): manopera (amanopera), Comanda (aComanda)
{
    try
    {
        if (anr_ingrediente < 0)
            throw anr_ingrediente;
        nr_ingrediente = anr_ingrediente;
    }
    catch (int a)
    {
        cout << "Numarul de ingrediente nu poate fi negativ";
    }
    if (atip_pizza != NULL)
    {
        tip_pizza = new char[strlen (atip_pizza) + 1];
        strcpy (tip_pizza, atip_pizza);
    }
    I = new Ingrediente<Type>[nr_ingrediente + 1];
    for (int i = 0; i < nr_ingrediente; i++)
        I[i] = aI[i];
    if (pret == NULL)
        pret = new Pret<Type>;
    *pret = apret;
    manopera = amanopera;
    Comanda = aComanda;
}

template <class Type>
Pizza<Type>::Pizza (const Pizza<Type> &P)
{
    tip_pizza = new char[strlen (P.tip_pizza) + 1];
    strcpy (tip_pizza, P.tip_pizza);
    nr_ingrediente = P.nr_ingrediente;
    I = new Ingrediente<Type>[nr_ingrediente + 1];
    for (int i = 0; i < nr_ingrediente; i++)
        I[i] = P.I[i];
    if (pret == NULL)
        pret = new Pret<Type>;
    *pret = P.pret;
    manopera = P.manopera;
    Comanda = P.Comanda;
}

template <class Type>
Pizza<Type>::~Pizza()
{
    if (tip_pizza != NULL)
        delete []tip_pizza;
    if (pret != NULL)
        delete pret;
    Comanda = 0;
    if (I != NULL)
        delete []I;
    nr_ingrediente = 0;
}

template <class Type>
void Pizza<Type>::operator= (const Pizza<Type> &P)
{
    if (tip_pizza != NULL)
        delete []tip_pizza;
    tip_pizza = new char[strlen (P.tip_pizza) + 1];
    strcpy (tip_pizza, P.tip_pizza);
    if (I != NULL)
        delete []I;
    nr_ingrediente = P.nr_ingrediente;
    I = new Ingrediente<Type>[nr_ingrediente + 1];
    for (int i = 0; i < nr_ingrediente; i++)
        I[i] = P.I[i];
    if (pret == NULL)
        pret = new Pret<Type>;
    *pret = *P.pret;
    manopera = P.manopera;
    Comanda = P.Comanda;
}

template <class Type>
void Pizza<Type>::citire (istream &in)
{
    if (tip_pizza != NULL)
        delete []tip_pizza;
    char s[100];
    cout << endl << "Tip pizza: ";
    in >> s;
    tip_pizza = new char[strlen (s) + 1];
    strcpy (tip_pizza, s);
    cout << "Numar ingrediente: ";
    try
    {
        in >> nr_ingrediente;
        if (nr_ingrediente < 0)
            throw nr_ingrediente;
    }
    catch (int a)
    {
        cout << "Numarul ingredientelor nu poate fi negativ";
    }
    I = new Ingrediente<Type>[nr_ingrediente + 1];
    for (int i = 0; i < nr_ingrediente; i++)
        in >> I[i];
    cout << "Pret manopera: ";
    manopera.citire (in);
    cout << "Tip comanda 1-online, 0-offline: ";
    in >> Comanda;
    if (Comanda == 1)
    {
        double km;
        cout << "Numar de km: ";
        in >> km;
        pret = new Pret_Comanda_online<Type>;
        (*pret).set_km (km);
    }
    else
    {
        pret = new Pret_Comanda_offline<Type>;
    }
    cout << endl;
}

template <class Type>
void Pizza<Type>::afisare (ostream &out) const
{
    out << tip_pizza << " ";
    (*pret).afisare (out);
}

template <class Type>
class Pizza_vegetariana: public Pizza<Type>
{
public:
    void citire (istream&);
    void afisare (ostream&);
};

template <class Type>
void Pizza_vegetariana<Type>::citire (istream &in)
{
    this->Pizza<Type>::citire (in);
}

template <class Type>
void Pizza_vegetariana<Type>::afisare (ostream &out)
{
    this->Pizza<Type>::afisare (out);
}

template <class Type>
class Pizza_normala: public Pizza<Type>
{
public:
    void citire (istream&);
    void afisare (ostream&);
};

template <class Type>
void Pizza_normala<Type>::citire (istream &in)
{
    this->Pizza<Type>::citire (in);
}

template <class Type>
void Pizza_normala<Type>::afisare (ostream &out)
{
    this->Pizza<Type>::afisare (out);
}

//Declarare-----------------------------

template <class Type>
class Meniu;

template <class Type>
istream& operator>> (istream& in, Meniu<Type>& M);

template <class Type>
ostream& operator<< (ostream& out, const Meniu<Type> &M);

template <class Type>
class Document_contabil_p_vegetariana;

//--------------------------------------

template <class Type>
class Meniu//E ca un document contabil
{
protected:
    static int index_vanzari;
    Pizza<Type> **tipuri_pizza;
public:
    Meniu();
    Meniu (const Pizza<Type>**, int);
    Meniu (const Meniu<Type>&);
    virtual ~Meniu();
    Meniu<Type> operator= (const Meniu<Type> &);
    Meniu<Type>& operator+= (Pizza<Type>*);
    friend istream& operator>> <Type> (istream& in, Meniu<Type>& M);
    friend ostream& operator<< <Type> (ostream& out, const Meniu<Type> &M);
    virtual void citire (istream&);
    virtual void afisare (ostream&) const;
    static int get_index_vanzari();
    static void set_index_vanzari (int);
};

template <class Type>
int Meniu<Type>::index_vanzari = 0;

template <class Type>
istream& operator>> (istream &in, Meniu<Type>&M)
{
    M.citire (in);
    return in;
}

template <class Type>
ostream& operator<< (ostream& out, const Meniu<Type> &M)
{
    M.afisare (out);
    return out;
}


template <class Type>
int Meniu<Type>::get_index_vanzari()
{
    return index_vanzari;
}

template <class Type>
void Meniu<Type>::set_index_vanzari (int p)
{
    try
    {
        if (p < 0)
            throw p;
    }
    catch (int p)
    {
        cout << "Indexul de vanzari nu poate avea valoare negativa";
    }
    index_vanzari = p;
}


template <class Type>
void Meniu<Type>::afisare (ostream &out)  const
{
    out << "Meniu:" << endl;
    int i;
    for (i = 0; i < index_vanzari; i++)
    {
        out << *tipuri_pizza[i];
    }
}

template <class Type>
void Meniu<Type>::citire (istream &in)
{
    cout << "Cate elemente s-au vandute: ";
    int n;
    in >> n;
    bool tip;
    for (int i = 0; i < n; i++)
    {
        cout << "Tip pizza 1-normala 0-vegetariana:";
        in >> tip;
        if (tip == 1)
        {
            Pizza<Type> *P = new Pizza_normala<Type>;
            in >> *P;
            P->calcul();
            *this += P;
        }
        else
        {
            Pizza<Type> *P = new Pizza_vegetariana<Type>;
            in >> *P;
            P->calcul();
            *this += P;
        }
    }
}

template <class Type>
Meniu<Type>& Meniu<Type>::operator+= (Pizza<Type> *P)
{
    if (index_vanzari == 0)
    {
        tipuri_pizza = new Pizza<Type>*[100];
    }
    index_vanzari++;
    tipuri_pizza[index_vanzari - 1] = P;
    return *this;
}

template <class Type>
Meniu<Type>::Meniu()
{
    tipuri_pizza = NULL;
    index_vanzari = 0;
}

template <class Type>
Meniu<Type>::Meniu (const Pizza<Type>** P, int index)
{
    try
    {
        if (index < 0)
            throw index;
    }
    catch (int p)
    {
        cout << "Indexul de vanzari nu poate avea valoare negativa";
    }
    index_vanzari = index;
    Pizza_normala<Type> Pn;
    Pizza_vegetariana<Type> Pv;
    for (int i = 0; i < index; i++)
    {
        if (typeid (* (P[i])) == typeid (Pn))
        {
            tipuri_pizza[i] = new Pizza_normala<Type>;
            *tipuri_pizza[i] = *P[i];
        }
        else if (typeid (* (P[i])) == typeid (Pv))
        {
            tipuri_pizza[i] = new Pizza_vegetariana<Type>;
            *tipuri_pizza[i] = *P[i];
        }
    }
}

template <class Type>
Meniu<Type>::Meniu (const Meniu<Type>& M)
{
    index_vanzari = M.get_index_vanzari ();
    int i;
    tipuri_pizza = new Pizza<Type>*[100];
    for (i = 0; i < index_vanzari; i++)
    {
        tipuri_pizza[i] = new Pizza<Type>[1];
        (*this->tipuri_pizza)[i] = (*M.tipuri_pizza)[i];
    }
}

template <class Type>
Meniu<Type> Meniu<Type>::operator= (const Meniu<Type> &M)
{
    index_vanzari = M.get_index_vanzari ();
    int i;
    tipuri_pizza = new Pizza<Type>*[100];
    for (i = 0; i < index_vanzari; i++)
    {
        tipuri_pizza[i] = new Pizza<Type>;
        (*this->tipuri_pizza)[i] = (*M.tipuri_pizza)[i];
    }
    return *this;
}

template <class Type>
Meniu<Type>::~Meniu()
{
    int i;
    for (i = 0; i < index_vanzari; i++)
    {
        delete (this->tipuri_pizza)[i];
    }
    delete []tipuri_pizza;
}

template<>
class Meniu<int>
{
protected:
    static int index_vanzari;
    Pizza<int> **tipuri_pizza;
public:
    Meniu();
    Meniu (const Pizza<int>**, int);
    Meniu (const Meniu<int>&);
    virtual ~Meniu();
    Meniu<int> operator= (const Meniu<int> &);
    Meniu<int>& operator+= (Pizza<int>*);
    friend istream& operator>> <int> (istream& in, Meniu<int>& M);
    friend ostream& operator<< <int> (ostream& out, const Meniu<int> &M);
    virtual void citire (istream&);
    virtual void afisare (ostream&) const;
    static int get_index_vanzari();
    static void set_index_vanzari (int);

};

int Meniu<int>::index_vanzari = 0;

istream& operator>> (istream &in, Meniu<int>&M)
{
    M.citire (in);
    return in;
}

ostream& operator<< (ostream& out, const Meniu<int> &M)
{
    M.afisare (out);
    return out;
}

int Meniu<int>::get_index_vanzari()
{
    return index_vanzari;
}

void Meniu<int>::set_index_vanzari (int p)
{
    try
    {
        if (p < 0)
            throw p;
    }
    catch (int p)
    {
        cout << "Indexul de vanzari nu poate avea valoare negativa";
    }
    index_vanzari = p;
}

void Meniu<int>::afisare (ostream &out)  const
{
    out << "Meniu<int> :" << endl;
    int i;
    for (i = 0; i < index_vanzari; i++)
    {
        out << *tipuri_pizza[i];
    }
}

void Meniu<int>::citire (istream &in)
{
    cout << "Cate elemente s-au vandute: ";
    int n;
    in >> n;
    bool tip;
    for (int i = 0; i < n; i++)
    {
        cout << "Tip pizza 1-normala 0-vegetariana:";
        in >> tip;
        if (tip == 1)
        {
            Pizza<int> *P = new Pizza_normala<int>;
            in >> *P;
            P->calcul();
            *this += P;
        }
        else
        {
            Pizza<int> *P = new Pizza_vegetariana<int>;
            in >> *P;
            P->calcul();
            *this += P;
        }
    }
}

Meniu<int>& Meniu<int>::operator+= (Pizza<int> *P)
{
    if (index_vanzari == 0)
    {
        tipuri_pizza = new Pizza<int>*[100];
    }
    index_vanzari++;
    tipuri_pizza[index_vanzari - 1] = P;
    return *this;
}

Meniu<int>::Meniu()
{
    tipuri_pizza = NULL;
    index_vanzari = 0;
}

Meniu<int>::Meniu (const Pizza<int>** P, int index)
{
    try
    {
        if (index < 0)
            throw index;
    }
    catch (int p)
    {
        cout << "Indexul de vanzari nu poate avea valoare negativa";
    }
    index_vanzari = index;
    Pizza_normala<int> Pn;
    Pizza_vegetariana<int>Pv;
    for (int i = 0; i < index; i++)
    {
        if (typeid (* (P[i])) == typeid (Pn))
        {
            tipuri_pizza[i] = new Pizza_normala<int>;
            *tipuri_pizza[i] = *P[i];
        }
        else if (typeid (* (P[i])) == typeid (Pv))
        {
            tipuri_pizza[i] = new Pizza_vegetariana<int>;
            *tipuri_pizza[i] = *P[i];
        }
    }
}

Meniu<int>::Meniu (const Meniu<int>& M)
{
    index_vanzari = M.get_index_vanzari ();
    int i;
    tipuri_pizza = new Pizza<int>*[100];
    for (i = 0; i < index_vanzari; i++)
    {
        tipuri_pizza[i] = new Pizza<int>[1];
        (*this->tipuri_pizza)[i] = (*M.tipuri_pizza)[i];
    }
}

Meniu<int> Meniu<int>::operator= (const Meniu<int> &M)
{
    index_vanzari = M.get_index_vanzari ();
    int i;
    tipuri_pizza = new Pizza<int>*[100];
    for (i = 0; i < index_vanzari; i++)
    {
        tipuri_pizza[i] = new Pizza<int>;
        (*this->tipuri_pizza)[i] = (*M.tipuri_pizza)[i];
    }
    return *this;
}

Meniu<int>::~Meniu()
{
    int i;
    for (i = 0; i < index_vanzari; i++)
    {
        delete tipuri_pizza[i];
    }
    delete []tipuri_pizza;
}


//Declarari--------------------------

template <class Type>
class Document_contabil_p_vegetariana;

template <class Type>
istream& operator>> (istream &in, Document_contabil_p_vegetariana<Type> &D);

template <class Type>
ostream& operator<< (ostream &out, const Document_contabil_p_vegetariana<Type> &D) ;

//----------------------------------

template <class Type>
class Document_contabil_p_vegetariana: public Meniu<Type>
{
    //folosesc tip_pizza din Meniu
    Pret<Type> incasari_totale;
public:
    void calcul();
    ~Document_contabil_p_vegetariana(){};
    Document_contabil_p_vegetariana();
    Document_contabil_p_vegetariana (const Pret<Type> &, int, Pizza<Type>**);
    Document_contabil_p_vegetariana (const Document_contabil_p_vegetariana<Type> &);
    Document_contabil_p_vegetariana<Type> operator= (const Document_contabil_p_vegetariana<Type> &);
    friend istream& operator>> <Type> (istream &in, Document_contabil_p_vegetariana<Type> &D);
    friend ostream& operator<< <Type> (ostream &out, const Document_contabil_p_vegetariana<Type> &D)   ;
};

template <class Type>
Document_contabil_p_vegetariana<Type>::Document_contabil_p_vegetariana(): Meniu<Type>()
{
    incasari_totale.set_pret (0);
    incasari_totale.set_km (0);
}

template <class Type>
Document_contabil_p_vegetariana<Type>::Document_contabil_p_vegetariana (const Pret<Type> &pret, int ind, Pizza<Type> **p): Meniu<Type> (p, ind)
{
    incasari_totale.set_pret (pret.pret);
    incasari_totale.set_km (pret.km);
}

template <class Type>
Document_contabil_p_vegetariana<Type>::Document_contabil_p_vegetariana (const Document_contabil_p_vegetariana<Type> &D): Meniu<Type> ((Meniu<Type>&)D)
{
    incasari_totale.set_pret (D.incasari_totale.pret);
    incasari_totale.set_km (D.incasari_totale.km);
}

template <class Type>
Document_contabil_p_vegetariana<Type> Document_contabil_p_vegetariana<Type>::operator= (const Document_contabil_p_vegetariana<Type> &D)
{
    this->Meniu<Type>::operator= (dynamic_cast<Meniu<Type>&> (D));
    incasari_totale = D.incasari_totale;
}

template <class Type>
istream& operator>> (istream &in, Document_contabil_p_vegetariana<Type>& D)
{
    in >> (dynamic_cast<Meniu<Type>&> (D));
    D.calcul();
    return in;
}

template <class Type>
ostream& operator<< (ostream &out, const Document_contabil_p_vegetariana<Type> &D)
{
    out << (Meniu<Type>&)D << endl;
    out << "Pret incasat pentru vanzarea pizzelor vegetariene: ";
    out << D.incasari_totale;
    return out;
}

template <class Type>
void Document_contabil_p_vegetariana<Type>::calcul()
{
    int index = Meniu<Type>::index_vanzari;
    incasari_totale.set_pret (0);
    Pizza_vegetariana<Type> Pv;
    for (int i = 0; i < index; i++)
    {
        if (typeid (*this->Meniu<Type>::tipuri_pizza[i]) == typeid (Pv))
            incasari_totale = incasari_totale + (*this->Meniu<Type>::tipuri_pizza[i]->get_Pret());
    }
}

int main()
{
    Document_contabil_p_vegetariana<int> D;
    cin >> D;
    cout << D;
    return 0;
}
