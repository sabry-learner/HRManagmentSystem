#include "HRSystem.h"
#include"HourlyEmployee.h"
#include"SalariedEmployee.h"
#include"CommissionEmployee.h"
#include"ManagerEmployee.h"

using namespace std;
HRSystem::HRSystem(int n)
{

    m_size_emp=n;
    m_count_emp=0;
    m_employee_list= new Employee*[m_size_emp];
}

HRSystem::~HRSystem()
{
    for(int i=0;i<m_count_emp;i++){
        delete m_employee_list[i];
    }
    delete [] m_employee_list;

}
void HRSystem::calc_Total_Payroll(){

    cout<<"\t***Employee Total Payroll****\n";
    double total=0.0;
    for(int i=0;i<m_count_emp;i++){
        total+=m_employee_list[i]->calculatePay();
    }
    cout<<"Total Payroll = "<<total<<endl;
}
void HRSystem::add_Employee(){

    int select;
    cout<<"#################################\n";
    cout<<"##Select Type of Employee:-\n";
    cout<<"=>1- Hourly Employee.\n=>2- Salaried Employee.\n=>3- Manager Employee. \n=>4- Commission Employee.\n";
    cout<<"Enter Select: ";
    cin>>select;
    bool success=true;
    if(select==1){

        m_employee_list[m_count_emp]= new HourlyEmployee();
        m_employee_list[m_count_emp]->getSalary();
        m_count_emp++;

    }else if(select==2){
        m_employee_list[m_count_emp]=new SalariedEmployee();
        m_employee_list[m_count_emp]->getSalary();
        m_count_emp++;
    }else if(select==3){
        m_employee_list[m_count_emp]=new ManagerEmployee();
        m_employee_list[m_count_emp]->getSalary();
        m_count_emp++;
    }else if(select==4){
        m_employee_list[m_count_emp]=new CommissionEmployee();
        m_employee_list[m_count_emp]->getSalary();
        m_count_emp++;
    }else{
        success=false;
        cout<<"Invalid Select!!\n";
    }
    if(success){
        cout<<"Employee Added Successfully .....\n";
    }

}

bool HRSystem::assignDepartToEmployeeById(int emp_id, Departement* d){
    int emp_idx = findById(emp_id);
    if(emp_idx==-1){
        return false;
    }
    Employee *emp= m_employee_list[emp_idx];
    emp->set_depart(d);
    return true;
}
int HRSystem::findById(int emp_id){
    for(int i=0;i<m_count_emp;i++){
        if(m_employee_list[i]->get_ID()==emp_id){
            return i;
        }
    }
    return -1;
}
void HRSystem::edit_Employee(int id){
    if(m_count_emp==0){
        cout<<"NO Employee Exist!!\n";
        return;
    }
    bool edited=false;
    for(int i=0;i<m_count_emp;i++){
        if(m_employee_list[i]->get_ID()==id){
            m_employee_list[i]->getSalary();

            edited=true;
            break;
        }
    }
    if(edited){
        cout<<"Employee Edited Successfully....\n";
    }else{
        cout<<"NO Employee Exist!!\n";
    }

}
void HRSystem::del_Employee(int id){
    if(m_count_emp==0){
        cout<<"NO Employee Exist!!\n";
        return;
    }
    bool deleted=false;
    for(int i=0;i<m_count_emp;i++){
        if(m_employee_list[i]->get_ID()==id){
            m_employee_list[i]=m_employee_list[m_count_emp-1];
            m_employee_list[m_count_emp-1]=NULL;
            m_count_emp--;
            deleted=true;
            break;
        }
    }
    if(deleted){
        cout<<"Employee Deleted Successfully....\n";
    }else{
        cout<<"NO Employee Exist!!\n";
    }

}
void HRSystem::Find_Employee(string word){
    bool found =false;
    for(int i=0;i<m_count_emp;i++){
        if(m_employee_list[i]->get_name()==word||m_employee_list[i]->get_jobTitle()==word){
            found=true;
            m_employee_list[i]->displayDetails();
        }
    }
    if(found){
        cout<<"Founded Successfully.....\n";
    }else{
        cout<<"No Founded Employee!!!!\n";
    }

}
void HRSystem::show_All(){
    if(m_count_emp==0){
        cout<<"No Employee Found!!!\n";
    }
    cout<<"---------------------------------\n";
    cout<<"The All Employees:-\n";
    cout<<"num of employee is = "<<m_count_emp<<endl;
    for(int i=0;i<m_count_emp;i++){
        m_employee_list[i]->displayDetails();
        cout<<"\t##################\n";
    }


}
