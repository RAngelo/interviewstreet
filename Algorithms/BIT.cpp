#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;
//Create a BIT using the vector vi
vector<int> BIT(const vector<int> a)
{
    int k;
    vector <int> tree((a.size()+1),0);

    for(int i=1;i<tree.size();i++)
    {
        tree[i]+=a[i-1];
        k = i;
        while(k<tree.size())
        {
            k+=(k&-k);
            tree[k]+=a[i-1];
        }
        
    }
    return tree;
}
//Obtain the sum of vi's values from 1 to index (Read cumulative frequency)
int read(int index, const vector<int> tree)
{
    int sum =0;
    
    while(index>0)
    {
        sum += tree[index];
        index -= (index & -index);
    }
    return sum;
}

//Change the value at some position and update the BIT
void update(vector<int> &tree, int index, int val)
{
    while(index<tree.size())
    {
        tree[index] += val;
        index += (index & -index);
    }
}

int main()
{
    vector<int> vi;
   
    vector<int> tree;
    tree = BIT(vi); //create a BIT based on vector vi;
    return 0;
}


