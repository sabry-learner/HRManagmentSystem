#include "Departement.h"

Departement::Departement(int id,string name)
{

    m_departID=id;
    m_departName=name;
}

void Departement::read_depart()
{
    cout<<"Enter Employee Departement Name: ";
    getline(cin,m_departName);

    cout<<"Enter Department ID : ";
    cin>>m_departID;
    cin.ignore();

}
void Departement::print()
{
    cout<<"Departement Name : "<<m_departName<<"\t\t";
    cout<<"Departement ID : "<<m_departID<<endl;
}
void Departement::set_id(int id)
{
    m_departID = id;
}
int Departement::get_id()
{
    return m_departID;
}
string Departement::get_depart()
{
    return m_departName;
}
Departement::Departement()
{
}
Departement::~Departement()
{
    //dtor
}
