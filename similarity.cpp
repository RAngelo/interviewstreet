#include <iostream>
#include <string>
using namespace std;

int compare(string comp, string enter)
{
    int size,res=0;
    size = comp.size();
    for(int a = 0; a < size; a++)
    {
            if(enter[a] == comp[a]) res++;
            else return res;
    }
    return res;
}

int main()
{
    string enter, comp;
    int T,size,result;
    cin >> T;
    
    for (int i =0; i<T; i++)
    {
        cin>>enter;
        comp = enter;
        size = enter.size();
        result = size;
        for(int a = 0; a < size; a++)
        {
                comp = comp.substr(1,size);
                result += compare(comp,enter);
        }
        cout<<result<<endl;
                
    }
    return 0;
}
