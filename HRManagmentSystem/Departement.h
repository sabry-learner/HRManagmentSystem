#include<iostream>
#include<string>
#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
using namespace std;
class Departement
{
private:
    int m_departID;
    string m_departName;
public:
    Departement();
    ~Departement();

    Departement (int id,string name);
    void read_depart();
    void print();
    void set_id(int);
    int get_id();
    string get_depart();

};

#endif // DEPARTEMENT_H
