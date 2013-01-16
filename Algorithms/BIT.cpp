//10
//1 1 5 4 3 6 6 5 9 10
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

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
    vi.push_back(1);vi.push_back(0); vi.push_back(2);vi.push_back(1); vi.push_back(1); vi.push_back(3);vi.push_back(0);
    vi.push_back(4);vi.push_back(2);  vi.push_back(5);  vi.push_back(2);  vi.push_back(2);  vi.push_back(3); vi.push_back(1);vi.push_back(0); vi.push_back(2);
    
    vector<int> tree;
    tree = BIT(vi);
    cout<<read(4,tree);
    return 0;
}


