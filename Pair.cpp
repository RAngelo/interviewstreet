//10
//1 1 5 4 3 6 6 5 9 10
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>


using namespace std;


int main() {
   ifstream textin("billboards.txt");
   ofstream textout("output.txt");
   int N,aux=0,k,aux2=0,result=0,find=0;
   vector<int> number;
   vector<int> values;
   vector<int>::iterator it;
   textin >> N;
   textin >> k;
   unsigned int array[N];
   
   for(int i =0; i<N; i++)
   {
       textin >> aux;
       number.push_back(aux);
   }
   
   sort(number.begin(),number.end());
   
   for(int i = 0; i <number.size(); i++)
   {
       values.push_back(number[i]);
       
       if(number[i]>=k)
       {
           aux = number[i] + k;
           aux2 = number[i] - k;
           if(binary_search (values.begin(), values.end(), aux) == 0 && binary_search (number.begin(), number.end(), aux) != 0) result++;
           if(binary_search (values.begin(), values.end(), aux2) == 0 && binary_search (number.begin(), number.end(), aux2) != 0) result++;
       }
       else
       {
           aux = k + number[i];
           if(binary_search (values.begin(), values.end(), aux) == 0 && binary_search (number.begin(), number.end(), aux) != 0) result++;
       }
   }
   cout<<result;   
 
   return 0;
}