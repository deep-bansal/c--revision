#include <iostream>
#include <string.h>
 
using namespace std;
 

class AddString {
 
public:
    
    char str[100]; 
    
    AddString(char str[])
    {
        strcpy(this->str, str);
    }

    AddString operator+(AddString& S2)
    {
        
        AddString S3;

        strcat(this->str, S2.str);
 
        strcpy(S3.str, this->str);
 
        return S3;
    }

    // AddString operator=(AddString&S1){
    //     if(this->str == S1) return true;
    //     else return false;
    // }
};
 
int main()
{
    char str1[] = "Deep";
    char str2[] = "bansal";

    AddString a1(str1);
    AddString a2(str2);
    AddString a3;
 
    a3 = a1 + a2;
    cout << "Concatenation: " << a3.str<<endl;
 
    return 0;
}