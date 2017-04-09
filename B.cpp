#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>

using namespace std;

void insertion_sort(vector<int> & v)
{
     int insert, moveItem;
     for(int next=1;next<v.size();++next)
     {
         insert = v.at(next);
         moveItem = next;
         while((moveItem>0) && (v.at(moveItem-1) > insert))
         {
             v.at(moveItem) = v.at(moveItem-1);
            --moveItem;
         }
         v.at(moveItem) = insert;
     }
}

int main()
{
    fstream fout("./sort.log", ios::out);
    srand(time(0));
    const int size[4] = {1000, 10000, 100000, 1000000};
    vector<int> v1, v2;
    for(int t=0;t<4;t++)
    {
        fout << "Array Size = " << size[t] << endl;

        v1.clear();
        v2.clear();

        for(int i=0, rnd;i<size[t];i++)
        {
            rnd = rand();
            v1.push_back(rnd);
            v2.push_back(rnd);
        }

        clock_t t1, t2;

        t2 = clock();
        sort(v2.begin(), v2.end());
        t2 = clock() - t2;
        fout << "STL Sort Time : " << (double)t2/CLOCKS_PER_SEC << " s"  << endl;

        t1 = clock();
        insertion_sort(v1);
        t1 = clock() - t1;
        fout << "Insertion Sort Time : " << (double)t1/CLOCKS_PER_SEC << " s" << endl;

        fout << endl;
    }
    return 0;
}
