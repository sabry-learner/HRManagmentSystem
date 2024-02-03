#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include"Departement.h"
#include"HRSystem.h"
using namespace std;
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
HRSystem x(100) ;
int size_depart=10;
int count_depart=0;
Departement* depart= new Departement [size_depart];


inline void printline(string msg, bool end_line = true, int color_code=15)
{
    SetConsoleTextAttribute(cout_handle, color_code);
    cout <<  msg << (end_line?"\n":"\t");
}
void departments()
{
    int ch=1;
    while(ch!=0)
    {

        cout<<"\t 1- Add New Department \n";
        cout<<"\t 2- Print All Departments \n";
        cout<<"\t 0- Return to main menu \n";
        cout<<"Enter Your selection : ";
        cin>>ch;
        cin.ignore();
        switch(ch)
        {
        case 1:
            cout<<"Add New Department........\n";
            if(count_depart<size_depart)
            {
                depart[count_depart++].read_depart();
            }
            else
            {
                cout<<"No more room for new department!!!\n";
            }
            break;
        case 2:
            cout<<"Print All Department.......\n";
            for(int i=0; i<count_depart; i++)
            {
                depart[i].print();
            }
            Sleep(3000);
            break;
        case 0:
            return;
        default:
            cout<<"Invalid choise, try again!";
            Sleep(3000);
        }
    }

}
void HRManagmentSystem()
{
    int ch=1;
    while(ch!=0)
    {
        system("cls");
        cout<<"\t\t\t#######Employee Information Managment######\n\n";
        cout<<"\t 1- Add New Employee \n";
        cout<<"\t 2- Delete Employee\n";
        cout<<"\t 3- Edit Employee\n";
        cout<<"\t 0- Return to main menu \n\n";
        cout<<"Enter Your selection : ";
        cin>>ch;
        cin.ignore();
        switch(ch)
        {
        case 1:
        {
            x.add_Employee();
            for(int i=0; i<count_depart; i++)
            {

                cout<<"\n######Depart Number "<<i+1<<"######\n";
                depart[i].print();
            }
            int dept_id = -1;
            cout<<"Enter Department ID: ";
            cin>>dept_id;
            cin.ignore();
            int dept_indx = -1;
            for(int i=0; i<count_depart; i++)
            {
                if(depart[i].get_id()==dept_id)
                {
                    dept_indx = i;
                    break;
                }
            }
            if(dept_indx!=-1)
            {

                int emp_id =-1;
                cout<<"Enter Employee ID again, please: ";
                cin>>emp_id;

                bool assignedSuccess = x.assignDepartToEmployeeById(emp_id, depart+dept_indx);
                if(assignedSuccess)
                {
                    cout<<"Successfully assign Employee to Department\x02\n";
                }
                else
                {
                    printline("Employee ID Not Found, try again!!!",true,4);
                }

            }
            else
            {
                cout<<"Department Not Found, try again!!!\n";
                Sleep(3000);
                break;
            }
            Sleep(3000);
        }

        break;
        case 2:
        {
            int id;
            cout<<"Enter ID: ";
            cin>>id;

            x.del_Employee(id);
            Sleep(3000);
        }
        break;
        case 3:
        {
            int id_emp;
            cout<<"Enter ID: ";
            cin>>id_emp;
            x.edit_Employee(id_emp);
            Sleep(3000);
        }

        break;
        case 0:
            return;
        default:
            cout<<"Invalid choise, try again!";
            Sleep(3000);
        }
    }



}


int main()
{


    int c=1;

    while(c!=0)
    {


        SetConsoleTextAttribute(cout_handle,11);
        cout<<" \t\tHR Managment System\n";
        cout<<"\t 1- Employee Information Managment.\n";
        cout<<"\t 2- Add New Department.\n";
        cout<<"\t 3- Salary Calculation.\n";
        cout<<"\t 4- Reporting for All Employees.\n";
        cout<<"\t 5- Search for Employee.\n";
        cout<<"\t 0- Exit from Program.\n";
        printline("Enter choice, please:",false,15);
        cin>>c;
        SetConsoleTextAttribute(cout_handle,14);
        switch(c)
        {
        case 1:
            HRManagmentSystem();

            break;

        case 2:
            departments();
            break;
        case 3:
            x.calc_Total_Payroll();
            break;
        case 4:
            x.show_All();

            break;
        case 5:
        {
            string name;
            cout<<"Enter Your name or Job Ttle to find: ";
            cin.ignore();
            getline(cin,name);

            x.Find_Employee(name);
        }
        break;
        case 0:
            system("cls");
            SetConsoleTextAttribute(cout_handle,3);
            cout<<"\t\t\t Thanks To Use My App :) \n\n";
            return 0;
        default:
            SetConsoleTextAttribute(cout_handle,4);
            cout<<"Invalid choise, try again!\n";
            Sleep(3000);
        }

    }

    return 0;
}
