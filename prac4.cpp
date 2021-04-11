#include <bits/stdc++.h>
using namespace std;
class Student 
{
public:
    string firstname;
    string lastname;
    string rollno;
    Student(string firstname,string lastname,string rollno){
        this->firstname = firstname;
        this->lastname = lastname;
        this->rollno = rollno;
    }

    bool operator ==(const Student &s)const{
        return this->rollno == s.rollno;
    }
    
};

class HashFn
{
public:
    size_t operator ()(const Student &s)const{
        return s.firstname.length() + s.lastname.length();
    }
    
};

int main(int argc, char const *argv[])
{
    unordered_map<Student,int,HashFn>mp;
    Student s1("Deep","Bansal","010");
    Student s2("Deep","Bansal","020");
    Student s3("Rah","singh","011");

    mp[s1] = 101;
    mp[s2] = 123;
    mp[s3] = 152;

    for(auto it:mp){
        cout<<it.first.firstname<<" "<<it.first.lastname<<" "<<it.first.rollno<<" "<<it.second<<endl;
    }



    
    return 0;
}