#include<bits/stdc++.h>
using namespace std;
  string numberToWords(int num) {
        string single_dig[]= {"","One","Two","Three","Four",
                              "Five","Six","Seven","Eight","Nine"};        
        string double_dig[] ={"","Eleven","Twelve","Thirteen","Fourteen",
                              "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};        
        string ten_multiple[]={"","Ten","Twenty","Thirty","Forty","Fifty",
                               "Sixty","Seventy","Eighty","Ninety"};        
        string ten_power[]={"Hundred","Thousand","Million","Billion"};        
        string output;
        int i = 3,p=9;
        while(i>=0){
            int y = pow(10,p);
            int div = num/y;
            if(div>=100){
                int x = div/100;

                output+=single_dig[x]+" "+ten_power[0]+" ";
                div = div%100;
            }
            if(div>=10){
                int x = div/10;

                output += ten_multiple[x]+" ";
                div = div%10;
            }            
            if(num>=1000000000 && i==3){
                output += single_dig[div] + " " +ten_power[3]+" ";
            }else if(num>=1000000 && i==2) {
                output += single_dig[div] + " " +ten_power[2]+" ";
            }else if(num>=1000 && i==1){
                output += single_dig[div] + " " +ten_power[1]+" ";
            }else if(num>=100 && i==0){
                output += single_dig[div] + " " +ten_power[0]+" ";
            }
            i--;
            num = num%y;
            if(p==3){
                p = p-1;
                continue;
            }
            p =p -3;
        }
        if(num>=10){
            int div = num/10;
            output+=ten_multiple[div]+" ";
            num = num%10;
        }
        if(num>0){
            output += single_dig[num];
        }
        return output;       
}
int main(int argc, char const *argv[])
{
    cout<<numberToWords(123)<<endl;
    return 0;
}