/*
ID: rafael12
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>


using namespace std;

int back(int i, string a)
{
    char aux,aux2;
    int index,count=0;
    aux = a[i];
    index = i-1;
    while(index>=0)
    {
        aux2 = a[index];
        if(aux == aux2 || aux2 == 'w')
        {
            count++;
        }
        else if(aux == 'w')
        {
            aux = aux2;
            count ++;
        }

        else index = 0;
        index--;
    }
    return count + 1;
}

int front(int i, string a)
{
    char aux,aux2;
    int index,count=0;
    if(i!=a.size()-2)
    {
        aux = a[i+1];
        index = i+2;
    }
    else
    {
       aux = a[a.size()-1];
       index = 0;
    }
    while(index<=a.size())
    {
        aux2 = a[index];
        if(aux == aux2 || aux2 == 'w')
        {
            count++;
        }
        else if(aux == 'w')
        {
            aux = aux2;
            count ++;
        }

        else index = a.size()+1;
        index++;
    }
    return count + 1;
}

int main() {
   ifstream textin("beads.in");
   ofstream textout("beads.out");
   int T,i=0,result;
   bool flag = false;
   string necklace;
   vector<int> values;
   textin >> T;
   textin>> necklace;
   necklace = necklace+necklace;
   if(necklace.find("b")!=string::npos && necklace.find("r")!=string::npos) flag = true; 
   for(i = 1; i < T-1; i++)
   {
       if(flag)
       {
           result = back(i,necklace);
           result += front(i,necklace);
           values.push_back(result);
       }
       else
       {
           i = T;
           values.push_back(necklace.size()/2);
       }
           
   }
   sort(values.begin(), values.end());
   values.erase( unique( values.begin(), values.end() ), values.end() );
   textout<<values[values.size()-1]<<endl;
   return 0;
}