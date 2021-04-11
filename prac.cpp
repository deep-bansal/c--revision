#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
	string key;
	T value;
	node<T>*next;
	node(string k,T val){
		key = k;
		value = val;
		next = NULL;
	}
	~node(){
		if(next != NULL){
			delete next;
		}
	}
};

template <typename T>
class hashMap
{
	node<T>** arr;
	int currSize;
	int totalSize;

	int hashFunction(string k){
		int idx = 0;
		int length = k.length();
		int multiplicationFactor = 1;
		for (int i = 0; i < length; ++i)
		{
			
		  int res =((k[length-i-1]%totalSize)*(multiplicationFactor*totalSize)) % totalSize;
		  idx = ((idx%totalSize) + (res%totalSize))%totalSize;
		  multiplicationFactor = ((multiplicationFactor%totalSize) * (47%totalSize))%totalSize;

		}
		return idx;
	}

	void reHash(){
		node<T>** oldArr = arr;
		int oldSize = totalSize;
		totalSize = 2* totalSize;
		arr = new node<T>*[totalSize];
		currSize = 0;
		for (int i = 0; i < totalSize; ++i)
		{
			arr[i] = NULL;
		}
		for (int i = 0; i < oldSize; ++i)
		{
			if(oldArr[i] != NULL){
				node<T>* temp = oldArr[i];
				while(temp != NULL){
					insert(temp->key,temp->value);
					temp = temp->next;
				}
			}

		}

		for (int i = 0; i < oldSize; ++i)
		{
			delete oldArr[i];
		}
		delete oldArr;
	}

public:
	hashMap(int defaultSize = 7){
		currSize = 0;
		totalSize = defaultSize;
		arr = new node<T>* [totalSize];
		for (int i = 0; i < totalSize; ++i)
		{
			arr[i] = NULL;
		}
	}

	void insert(string k,T value){
		int idx = hashFunction(k);
		node<T>* newNode = new node<T>(k,value);
		newNode->next = arr[idx];
		arr[idx] = newNode;
		currSize++;
		float loadFactor = (float)currSize/totalSize;
		if(loadFactor>0.7){
			reHash();
		}
	}
	T* search(string k){
		int idx = hashFunction(k);
		node<T>* temp = arr[idx];
		while(temp!=NULL){
			if(temp->key==k){
				return &(temp->value);
			}
			temp = temp->next;
		}
		return NULL;
	}

	T& operator [](string k)
	{
		T* valueAdd=NULL;
		if(search(k)!=NULL) 
		{
			valueAdd=search(k);
		}
		else
		{
			T garbageValue;

			insert(k,garbageValue);
			valueAdd=search(k);
		}
		return *valueAdd;

	}
};

int main(int argc, char const *argv[])
{
	hashMap<int>m(9) ;
	m.insert("ABC",10);
	m.insert("DEF",100);
	m.insert("GHI",1000);
	// m["GFD"] = 2000;
	cout<<m["GFD"]<<endl;
	return 0;
}