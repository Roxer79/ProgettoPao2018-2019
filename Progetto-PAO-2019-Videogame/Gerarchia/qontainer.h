#ifndef QONTAINER_H
#define QONTAINER_H

#include<iostream>
#include<string>
#include<ctime>

template<class T>
class Container {
private:
    class Nodo;

    class SmartP{  //SMARTP
    public:
        Nodo* punt;
        SmartP(Nodo* = nullptr);
        SmartP(const SmartP&);
        ~SmartP();
        SmartP& operator=(const SmartP&);
        /*SmartP& operator++();
        SmartP& operator--();*/
        Nodo& operator*() const;
        Nodo* operator->() const;
        bool operator==(const SmartP&) const;
        bool operator!=(const SmartP&) const;
    };

    class Nodo{
    public:
        T info;
        SmartP prev;
        SmartP next;
        int riferimenti;
        Nodo();
        Nodo(const T& = 0, const SmartP& = 0, const SmartP& = 0);
        Nodo(const Nodo&);
        //~Nodo();
    };
    SmartP primo;
    //SmartP libero; //aggiunto dopo
    SmartP ultimo;
    //static SmartP copy(const SmartP& , const SmartP&);
public:
    class iterator{ //ITERATOR
    private:
        SmartP* point;
        bool pastTheEnd;
        //iterator(SmartP*, bool = false);
    public:
        iterator();
        iterator(SmartP* = nullptr, bool = false);
        iterator(const iterator&);
        iterator& operator++();
        iterator& operator--();
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
        T& operator*() const;
        T* operator->() const;
    };

    class constiterator{ // CONST_ITERATOR
    private:
        const SmartP* pt;
        bool pte; //true se past the
        //constiterator(const SmartP*, bool = false);
    public:
        constiterator();
        constiterator(const SmartP* = nullptr, bool = false);
        constiterator(const constiterator&);
        constiterator& operator++();
        constiterator& operator--();
        bool operator==(const constiterator&) const;
        bool operator!=(const constiterator&) const;
        const T& operator*() const;
        const T* operator->() const;
    };

    iterator it_Begin();
    iterator it_End();
    constiterator cit_Begin() const;
    constiterator cit_End() const;

    //~Container();
    //void insert(const T&, const T& = nullptr, const T& = nullptr);
    //void insertLibero(const SmartP& = nullptr, const T& = nullptr, const SmartP& = nullptr, const SmartP& = nullptr);
    void insertInFront(const T&);
    void insertInBack(const T&);
    //SmartP& removeInFront(const T&);
    //SmartP& removeInBack(const T&);
    bool containerVuoto() const;
    void rimuoviElemento(const T&);
    unsigned int numElementiQontainer() const;
    const T ricercaContainerPuntatori(const T) const;
    const T& ricercaContainerOggetti(const T&) const;

    //Container(int = 0, T& = 0);
};

/*template<class T>
typename Container<T>::SmartP Container<T>::copy(const SmartP& first, const SmartP& last) {
    if(first.punt == nullptr) return last.punt = nullptr;
    SmartP f = new Nodo(first->info, nullptr, nullptr);
    SmartP p = f;
    while(first->next.punt != nullptr){
        p->next = new Nodo(first->next->info, p, nullptr);
        first = first->next;
        p = p->next;
    }
    last = p;
    return f;
}*/

//=========================================================================== #classe SmartP

template<class T>
Container<T>::SmartP::SmartP(Nodo* s): punt(s) { if(punt) punt->riferimenti++; }

template<class T>
Container<T>::SmartP::SmartP(const SmartP& s): punt(s.punt) { if(punt) punt->riferimenti++; }

template<class T>
Container<T>::SmartP::~SmartP() {
    if(punt) {
        punt->riferimenti--;
        if(punt->riferimenti == 0) delete punt; //delete punt->info;
    }
}

template<class T>
typename Container<T>::SmartP& Container<T>::SmartP::operator=(const SmartP& s){
    if(this != &s){
        Nodo* nuovo = punt;
        punt = s.punt;
        if(punt) punt->riferimenti++;
        if(nuovo){
            nuovo->riferimenti--;
            if(nuovo->riferimenti == 0) delete nuovo;
        }
    }
    return *this;
}

template<class T>
typename Container<T>::Nodo& Container<T>::SmartP::operator*() const { return *punt; }

template<class T>
typename Container<T>::Nodo* Container<T>::SmartP::operator->() const { return punt; }

template<class T>
bool Container<T>::SmartP::operator==(const SmartP& s) const { return punt == s.punt; }

template<class T>
bool Container<T>::SmartP::operator!=(const SmartP& s) const { return punt != s.punt; }

//=========================================================================== #classe Nodo

template<class T>
Container<T>::Nodo::Nodo(): riferimenti(0) {}

template<class T>
Container<T>::Nodo::Nodo(const T& t, const SmartP& p, const SmartP& n): info(t), prev(p), next(n), riferimenti(0) {}

template<class T>
Container<T>::Nodo::Nodo(const Nodo& t): info(t.info), prev(t.prev), next(t.next), riferimenti(t.riferimenti) {}

//template<class T>
//Container<T>::Nodo::~Nodo() { if(info) delete info; }

//=========================================================================== #classe Iterator

template<class T>
Container<T>::iterator::iterator(): point(nullptr), pastTheEnd(false) {}

template<class T>
Container<T>::iterator::iterator(SmartP* pt, bool pastThe): point(pt), pastTheEnd(pastThe) {}

template<class T>
Container<T>::iterator::iterator(const iterator& s): point(s.point), pastTheEnd(s.pastTheEnd) {}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator++() {
    if(!pastTheEnd && point != 0){
        if((*point)->next == nullptr) {
            point = &((*point)->next);//point = ++point;
            pastTheEnd = true;
        }
        else point = &((*point)->next);
    }
    return *this;
}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator--() {
    if(pastTheEnd){
        point = &((*point)->prev);//point = --point;
        pastTheEnd = false;
    }
    else{
        if(point) point = &((*point)->prev);
    }
    return *this;
}

template<class T>
bool Container<T>::iterator::operator==(const iterator& x) const { return point == x.point; }

template<class T>
bool Container<T>::iterator::operator!=(const iterator& x) const { return point != x.point; }

template<class T>
T& Container<T>::iterator::operator*() const { return ((*point)->info); }

template<class T>
T* Container<T>::iterator::operator->() const { return &((*point)->info); /*return point->info;*/ }

//=========================================================================== #classe constiterator

template<class T>
Container<T>::constiterator::constiterator(): pt(nullptr), pte(false) {}

template<class T>
Container<T>::constiterator::constiterator(const SmartP* p, bool pt): pt(p), pte(pt) {}

template<class T>
Container<T>::constiterator::constiterator(const constiterator& s): pt(s.pt), pte(s.pte) {}

template<class T>
typename Container<T>::constiterator& Container<T>::constiterator::operator++() {
    if(!pte && pt != nullptr){
        if((*pt)->next == nullptr) {
            pt = &((*pt)->next);// pt = ++pt;
            pte = true;
        }
        else pt = &((*pt)->next);
    }
    return *this;
}

template<class T>
typename Container<T>::constiterator& Container<T>::constiterator::operator--() {
    if(pte){
        pt = &((*pt)->prev);//pt = --pt;
        pte = false;
    }
    else{
        if(pt) pt = &((*pt)->prev);
    }
    return *this;
}

template<class T>
bool Container<T>::constiterator::operator==(const constiterator& x) const { return pt == x.pt; }

template<class T>
bool Container<T>::constiterator::operator!=(const constiterator& x) const { return pt != x.pt; }

template<class T>
const T& Container<T>::constiterator::operator* () const { return ((*pt)->info); }

template<class T>
const T* Container<T>::constiterator::operator->() const { return &((*pt)->info); }

//===========================================================================

template<class T>
typename Container<T>::iterator Container<T>::it_Begin() {
    if(primo == nullptr) return iterator(nullptr);
    return iterator(&primo);
}

template<class T>
typename Container<T>::iterator Container<T>::it_End() {
    if(primo == nullptr) return iterator(nullptr);
    return iterator(&(ultimo->next), true);
}

template<class T>
typename Container<T>::constiterator Container<T>::cit_Begin() const{
    if(primo == nullptr) return constiterator(nullptr);
    return constiterator(&primo);
}

template<class T>
typename Container<T>::constiterator Container<T>::cit_End() const {
    if(primo == nullptr) return constiterator(nullptr);
    return constiterator(&(ultimo->next), true);
}

//=========================================================================== #funzioni

template<class T>
void Container<T>::insertInFront(const T& x) {
    primo = new Nodo(x, nullptr, primo);
    if(ultimo == nullptr) {
       ultimo = primo;
    } else { (primo->next)->prev = primo; }
    //delete x; //fatto dopo
}

template<class T>
void Container<T>::insertInBack(const T& x) {
    ultimo = new Nodo(x, ultimo, nullptr);
    if(primo == nullptr) {
       primo = ultimo;
    } else { (ultimo->prev)->next = ultimo; }
    //delete x; //fatto dopo
}

/*template<class T>
typename Container<T>::SmartP& Container<T>::removeInFront(const T& x) {
    SmartP nuovo = x->prev;
    x->next->prev = x->prev;
    x->prev->next = x->next;
    delete x;
    return nuovo;
}

template<class T>
typename Container<T>::SmartP& Container<T>::removeInBack(const T& x) {
    SmartP nuovo = x->next;
    x->next->prev = x->prev;
    x->prev->next = x->next;
    delete x;
    return nuovo;
}*/

template<class T>
bool Container<T>::containerVuoto() const { return primo == nullptr; }

template<class T>
void Container<T>::rimuoviElemento(const T& x) {
    SmartP p = primo;
    SmartP prec = nullptr, q = nullptr;
    SmartP original = primo;
    //original->
    primo = nullptr;
    while(p != nullptr && !(p->info == x)) {
        q = new Nodo(p->info, p->prev, p->next);
        if(p->prev == nullptr) primo = q;
        else {
            prec->next = q;
            q->prev = prec;
        }
        prec = q;
        p = p->next;
    }
    if(p == nullptr) primo = original;
    else {
        if(prec == nullptr) {
            if(original == ultimo) { //
                primo = original; //
                primo = nullptr; //
                ultimo = nullptr; //
            } else { //
                primo = p->next;
                primo->prev = nullptr;
            }
        } else {
            if(p->next != nullptr) {
                prec->next = p->next;
                (p->next)->prev = prec;
            } else {
                prec->next = p->next;
                ultimo = prec;
            }
        }
    }
}

template<class T>
unsigned int Container<T>::numElementiQontainer() const {
    unsigned int conta = 0;
    constiterator cit = cit_Begin();
    for( ; cit != cit_End(); ++cit) {
        conta += 1;
    }
    return conta;
}

template<class T>
const T Container<T>::ricercaContainerPuntatori(const T ric) const {
    constiterator cit = cit_Begin();
    for( ; cit != cit_End(); ++cit) {
        if(*(*cit)== *ric) return (*cit);
    }
    return nullptr;//0;
}

template<class T>
const T& Container<T>::ricercaContainerOggetti(const T& ric) const {
    constiterator cit = cit_Begin();
    for( ; cit != cit_End(); ++cit) {
        if((*cit)== ric) return (*cit);
    }
    return 0;
}

//=========================================================================== #anno corrente

static unsigned int AnnoCorrente() {
    time_t currentTime;
    time(&currentTime);
    //std::string annoC = asctime(localtime(&currentTime));
    struct tm* timeinfo = localtime(&currentTime);
    int AnnoC = (1900 + (timeinfo->tm_year));
    return static_cast<unsigned int>(AnnoC);
}

#endif // QONTAINER_H
