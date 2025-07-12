#include <iostream>
#include <string>

using namespace std;
class student
{
    public:
    string name;
    int marks;
    string roll_num;
    float* fee=new float;


    student() {}
    student(string name, int marks, string roll_num, float fees)
    {
        this->name = name;
        this->marks = marks;
        this->roll_num = roll_num;
        *(fee)=fees;
        
    }
    student(student &obj){
        this->name=obj.name;
        this->marks=obj.marks;
        this->roll_num=obj.roll_num;
        fee=new float;
        *(this->fee)=*(obj.fee);

    }
    void getinfo(){
        cout<<"NAME: "<<name<<endl;
        cout<<"FEE: "<<fee<<endl;
        cout<<"ROLL NUM: "<<roll_num<<endl;
    }
    ~student(){
        delete fee;
    }
};
int main()
{
    student s1("zain",91,"173762827",97000);
    s1.getinfo();
    cout<<endl<<endl;
    student s2(s1);
    *(s2.fee)=20000;
    s2.getinfo();
    cout<<endl<<endl;
    s1.getinfo();
    return 0;
}