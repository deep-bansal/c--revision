#include<bits/stdc++.h>
using namespace std;

class Polynomial
{
public:
	int capacity;
	int* degCoeff;
	Polynomial(){
		capacity = 6;
		degCoeff= new int [capacity]();
	}

	void setCoeff(int degree,int coeff){
		if(degree >= capacity){
			int* newDegCoeff = new int[degree+1];
			for (int i = 0; i < degree; ++i)
			{
				newDegCoeff[i]= degCoeff[i];
			}

			delete[] degCoeff;
			degCoeff = newDegCoeff;
			capacity = degree +1;

		}
		degCoeff[degree] = coeff;
	}

	Polynomial operator + (const Polynomial &p){
		Polynomial result;
		if(capacity > p.capacity){
			for (int i = 0; i < capacity ; ++i)	
			{
				result.degCoeff[i] = degCoeff[i]; 

			}

			for (int i = 0; i < p.capacity; ++i)
			{
				result.degCoeff[i] += p.degCoeff[i];
			}
		}else{
			for (int i = 0; i < p.capacity; ++i)
			{
				result.degCoeff[i] = p.degCoeff[i];
			}
			for (int i = 0; i < capacity; ++i)
			{
				result.degCoeff[i] += degCoeff[i];
			}
		}
		return result;
	}

	// Polynomial operator + (const Polynomial &p1,const Polynomial &p2){
// 			Polynomial result;
// 		if(p1.capacity > p2.capacity){
// 			for (int i = 0; i < p1.capacity ; ++i)	
// 			{
// 				result.degCoeff[i] = p1.degCoeff[i]; 

// 			}

// 			for (int i = 0; i < p2.capacity; ++i)
// 			{
// 				result.degCoeff[i] += p2.degCoeff[i];
// 			}
// 		}else{
// 			for (int i = 0; i < p2.capacity; ++i)
// 			{
// 				result.degCoeff[i] = p2.degCoeff[i];
// 			}
// 			for (int i = 0; i < p1.capacity; ++i)
// 			{
// 				result.degCoeff[i] += p1.degCoeff[i];
// 			}
// 		}
// 		return result;

// 	}

	Polynomial operator - (const Polynomial &p){
		Polynomial result;
		for (int i = 0; i < capacity; ++i)
		{
			result.degCoeff[i] = degCoeff[i];
		}

		for (int i = 0; i < p.capacity; ++i)
		{
			result.degCoeff[i] -= p.degCoeff[i];
		}
		return result;
	}

	Polynomial operator * (const Polynomial &p){
		Polynomial result;

		for (int i = 0; i < this->capacity; ++i)
		{
			for (int j = 0; j < p.capacity; ++j)
			{
				int degree = i +j;
				int coeff = this->degCoeff[i]*p.degCoeff[j];

				if(degree < result.capacity){
					result.degCoeff[degree] += coeff;
				}else{
					result.setCoeff(degree,coeff);
				}

			}
		}
		return  result;


	}

	 Polynomial (Polynomial &p1)
    {
        int capacity1=p1.capacity;
        degCoeff=new int[capacity1];
        for(int i=0;i<p1.capacity;i++)
        {
            degCoeff[i]=p1.degCoeff[i];
        }
    }




	void print(){
		for (int i = 0; i < capacity; ++i)
		{
			if(degCoeff[i] != 0){
				cout<<degCoeff[i]<<"x"<<i<<" ";
			}
		}

	}
	
};



int main(int argc, char const *argv[])
{
	int count1,count2,choice;
	cin>>count1;
	int* degree1 = new int [count1];
	int* coeff1 = new int [count1];

	for (int i = 0; i < count1; ++i)
	{
		cin>>degree1[i];
	}

	for (int i = 0; i < count1; ++i)
	{
		cin>>coeff1[i];
	}

	Polynomial first;
	for (int i = 0; i < count1; ++i)
	{
		first.setCoeff(degree1[i],coeff1[i]);
	}

	

	cin>>count2;
	int* degree2 = new int [count2];
	int* coeff2 = new int [count2];

	for (int i = 0; i < count2; ++i)
	{
		cin>>degree2[i];
	}

	for (int i = 0; i < count2; ++i)
	{
		cin>>coeff2[i];
	}

		Polynomial second;
	for (int i = 0; i < count2; ++i)
	{
		second.setCoeff(degree2[i],coeff2[i]);
	}
	cin>>choice;




	Polynomial result;

	switch(choice){
		case 1: 
		result = first + second;
		result.print();
		break;

		case 2:
		result = first - second;
		result.print();
		break;

		case 3:
		result = first * second;
		result.print();
		break;

		case 4:
		{
			Polynomial third(first);
			if(third.degCoeff == first.degCoeff){
				cout<<"false"<<endl;
			}
			else{
				cout<<"true"<<endl;
			}
			break;
		}
		// case 5:{
		// 	Polynomial fourth(first);
		// 	if(third.degCoeff == first.degCoeff){
		// 		cout<<"false"<<endl;
		// 	}
		// 	else{
		// 		cout<<"true"<<endl;
		// 	}
		// 	break;

		// }

	}
	return 0;
}