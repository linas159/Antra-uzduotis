#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>
#include <regex>
#include <random>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct studentas
{
    string vard;
    string pavard;
    vector <int> nd;
    int egz;
    float gal;
    float galmed;
};

class Person {
protected:
    string vard;
    string pavard;

public:
    Person() : vard(""), pavard("") {}
    Person(string vardas, string pavarde)
    {
        vard = vardas;
        pavard = pavarde;
    }

    inline string vardas() const { return vard; }
    inline string pavarde() const { return pavard; }

    virtual void setVardas(string name) = 0;
    virtual void setPavarde(string surname) = 0;

    friend bool operator<(const Person& a, const Person& b) // less than operator
    {
        if (a.vard != b.vard)
            return a.vard < b.vard;
        else
            return a.pavard < b.pavard;
    }
    friend bool operator>(const Person& a, const Person& b) // greater than operator
    {
        if (a.vard != b.vard)
            return a.vard > b.vard;
        else
            return a.pavard > b.pavard;
    }
    friend bool operator<=(const Person& a, const Person& b) // less than or equal to operator
    {
        if (a.vard != b.vard)
            return a.vard <= b.vard;
        else
            return a.pavard <= b.pavard;
    }
    friend bool operator>=(const Person& a, const Person& b) // greater than or equal to operator
    {
        if (a.vard != b.vard)
            return a.vard >= b.vard;
        else
            return a.pavard >= b.pavard;
    }

    virtual std::ostream& write(std::ostream& out) const
    {
        out << vard << " " << vard;
        return out;
    }
    friend std::ostream& operator<<(std::ostream& out, const Person& p) 
    {
        return p.write(out);
    }
};

class Student : public Person {
    // realizacija
private:
    double egz;
    float gal;
    // interfeisas
public:
    Student(string vard = "", string pavard = "") : Person(vard, pavard), egz(0) {} // default konstruktorius
    Student(string vard, string pavard, double egz, float gal ) : Person(vard,pavard), egz(0), gal(0.0) { }  // konstruktorius
    ~Student() {}; //destruktorius
    Student(const Student& that) //copy konstruktorius
    {
        this->vard = that.vard;
        this->pavard = that.pavard;
        this->egz = that.egz;
        this->gal = that.gal;
    }

    Student& operator=(const Student& that) //copy assignment operator
    {
        if (this != &that)
        {
            this->vard = that.vard;
            this->pavard = that.pavard;
            this->egz = that.egz;
            this->gal = that.gal;
        }
        return *this;
    }

    friend bool operator<(const Student& a, const Student& b) //naujas operatorius
    {
        if (a.vard != b.vard)
            return a.vard < b.vard;
        else
            return a.pavard < b.pavard;
    }

    inline string vardas() const { return vard; }    // get'eriai, inline
    inline string pavarde() const { return pavard; }  // get'eriai, inline
    inline float galbal() const { return gal; } // get'eriai, inline

    //set'eriai
    void setVardas(string a) { vard = a; }
    void setPavarde(string a) { pavard = a; }
    void setEgz(double a) { egz = a; }
    void setGal(float a) { gal = a; }

};

void exists_test(const string& name);
void skaicius(int& a);
void ivestisranka(vector <studentas>& stud);
int kiekpazymiu();
void ivestis(vector <studentas>& stud);
bool palyginimas(studentas& a, studentas& b);
bool palyginimas2(Student& a, Student& b);
void isvestis(vector <studentas> stud);
void failugeneracija(int kieknd);
void failgen(int kieknd, int kiekstud);

void greicioanalizevector(int kiekstud);
void rusiavimasvector(vector <studentas> &stud, vector <studentas>& nend, vector <studentas>& kiet);

void greicioanalizelist(int kiekstud);
void rusiavimaslist(list <studentas> &stud, list <studentas>& nend, list <studentas>& kiet);

void greicioanalizedeque(int kiekstud);
void rusiavimasdeque(deque <studentas> &stud, deque <studentas>& nend, deque <studentas>& kiet);

void nendartiolaiifaila(int kieknd, vector <studentas> nend, int kiekstud);
void kietiakaiifaila(int kieknd, vector <studentas> kiet, int kiekstud);

//antra strategija

void greicioanalizevector2(int kiekstud);
void rusiavimasvector2(vector <Student>& stud, vector <Student>& nend);
void nendartiolaiifaila2(int kieknd, vector <Student> nend, int kiekstud);
void kietiakaiifaila2(int kieknd, vector <Student> stud, int kiekstud);

void greicioanalizelist2(int kiekstud);
void rusiavimaslist2(list <studentas>& stud, list <studentas>& nend);
void nendartiolaiifailalist2(int kieknd, list <studentas> nend, int kiekstud);
void kietiakaiifailalist2(int kieknd, list <studentas> stud, int kiekstud);

void greicioanalizedeque2(int kiekstud);
void rusiavimasdeque2(deque <studentas>& stud, deque <studentas>& nend);
void nendartiolaiifailadeque2(int kieknd, deque <studentas> nend, int kiekstud);
void kietiakaiifailadeque2(int kieknd, deque <studentas> stud, int kiekstud);
