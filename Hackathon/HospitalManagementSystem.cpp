
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person{
protected:
    int id; string name;
public:
    Person(int id=0,string name=""):id(id),name(name){}
    virtual void display()=0;
    virtual ~Person(){}
};

class Doctor: public Person{
    string specialization;
public:
    Doctor(int id=0,string name="",string s=""):Person(id,name),specialization(s){}
    void display() override{
        cout<<"Doctor ID: "<<id<<" Name: "<<name<<" Specialization: "<<specialization<<endl;
    }
};

class Patient: public Person{
protected:
    int age;
public:
    Patient(int id=0,string name="",int age=0):Person(id,name),age(age){
        if(age<0) throw "Invalid Age";
    }
    virtual double calculateBill()=0;
    bool operator>(Patient& other){ return calculateBill()>other.calculateBill(); }
};

class InPatient: virtual public Patient{
protected:
    double roomCharge,treatmentCost;
public:
    InPatient(int id=0,string n="",int a=0,double rc=0,double tc=0):Patient(id,n,a),roomCharge(rc),treatmentCost(tc){}
    double calculateBill() override { return roomCharge+treatmentCost; }
    void display() override{
        cout<<"[InPatient] "<<name<<" Bill="<<calculateBill()<<endl;
    }
};

class OutPatient: public Patient{
    double fee;
public:
    OutPatient(int id=0,string n="",int a=0,double f=0):Patient(id,n,a),fee(f){}
    double calculateBill() override { return fee; }
    void display() override{
        cout<<"[OutPatient] "<<name<<" Bill="<<calculateBill()<<endl;
    }
};

class EmergencyPatient: virtual public Patient{
protected:
    double emergencyCharge;
public:
    EmergencyPatient(int id=0,string n="",int a=0,double e=0):Patient(id,n,a),emergencyCharge(e){}
    double calculateBill() override { return emergencyCharge; }
    void display() override{
        cout<<"[EmergencyPatient] "<<name<<" Bill="<<calculateBill()<<endl;
    }
};

class CriticalPatient: public InPatient, public EmergencyPatient{
public:
    CriticalPatient(int id,string n,int a,double rc,double tc,double ec)
    : Patient(id,n,a),InPatient(id,n,a,rc,tc),EmergencyPatient(id,n,a,ec){}
    double calculateBill() override { return roomCharge+treatmentCost+emergencyCharge; }
    void display() override{
        cout<<"[CriticalPatient] "<<name<<" Bill="<<calculateBill()<<endl;
    }
};

int main(){
    Patient* patients[100];
    int count=0,choice;

    do{
        cout<<"\n1.Add InPatient\n2.Add OutPatient\n3.Add Emergency\n4.Add Critical\n5.View\n6.Save File\n7.Exit\nChoice: ";
        cin>>choice;

        try{
            if(choice>=1 && choice<=4){
                int id,age; string name;
                cout<<"ID: "; cin>>id;
                cout<<"Name: "; cin>>name;
                cout<<"Age: "; cin>>age;

                if(choice==1){
                    double rc,tc; cin>>rc>>tc;
                    patients[count++]=new InPatient(id,name,age,rc,tc);
                }else if(choice==2){
                    double f; cin>>f;
                    patients[count++]=new OutPatient(id,name,age,f);
                }else if(choice==3){
                    double e; cin>>e;
                    patients[count++]=new EmergencyPatient(id,name,age,e);
                }else{
                    double rc,tc,ec; cin>>rc>>tc>>ec;
                    patients[count++]=new CriticalPatient(id,name,age,rc,tc,ec);
                }
            }else if(choice==5){
                for(int i=0;i<count;i++) patients[i]->display();
            }else if(choice==6){
                ofstream file("patients.txt");
                for(int i=0;i<count;i++) file<<"Bill: "<<patients[i]->calculateBill()<<endl;
                file.close();
                cout<<"Saved\n";
            }
        }catch(const char* msg){
            cout<<msg<<endl;
        }
    }while(choice!=7);

    for(int i=0;i<count;i++) delete patients[i];
    return 0;
}
