#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int dataarray[7] = {1,8,2,5,4,9,7};
int cari;

void selection_short(){
    int temp, min, i, j;
    for (int i =0 ;i< 7; i++)
    {
        min = i;
        for (j = i; j<7 ;j++)
        {
            if (dataarray[j] < dataarray[min])
            {
                min =j;
            }
        }
        temp = dataarray[i];
        dataarray[i] = dataarray[min];
        dataarray[min] = temp;
    }
}

void binarysearch(){
    int awal, akhir, tengah;
    bool b_flag = false ;
    awal =0;
    akhir = 0;
    while (!b_flag && awal <= akhir)
    {
        tengah =(awal+akhir)/2;
        if (dataarray[tengah]== cari)
        {
            b_flag=true;
        }else if (dataarray[tengah]< cari)
        {
            awal=tengah +1;
        }else {
            akhir = tengah;
        }
    }
}



int main(){
    cout << "binary search "<< endl;
    cout << "\bdata:" << endl;

    for (int x= 0; x< 7; x++)
    {
        cout << setw(3)<< dataarray[x];
    }
    cout << endl;
    binarysearch();
    _getche();
    return 0;
}