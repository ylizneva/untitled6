//
// Created by Yulia Lizneva on 2017-12-04.
//

#include <iostream>

using namespace std;
template <typename T>




int binarySearch(T arr[], int n, T toFind)
{
    int midd=0;
    int start=0;
    int slut=n-1;


    midd=(start+slut)/2;
    while(start<=slut && arr[midd]!=toFind)
    {
        if(toFind<arr[midd])
        {
            slut= midd-1;
        }
        else
        {
            start= midd+1;
        }

        midd = (start+slut)/2;

        if(arr[midd]!=toFind)
        {
            midd=-1;
        }
        return midd;
    }
}





int main()
{

    int nrs[]={0,10, 20, 30, 40, 50, 60};
    int pos = binarySearch(nrs, 7, 50);

    cout<<"Position"<<pos<<endl;
    pos= binarySearch(nrs, 7, 55);
    cout<<pos<<endl;







    return 0;
}
