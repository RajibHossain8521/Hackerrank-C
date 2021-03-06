#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<math.h>

using namespace std;

#define N 101 //maximum number of coins
#define M 25001 //maximum share of each person, max coin is 500c and max number of coins is 100

bool v[M];

int absulate(int n)
{
    return (n>0)? n:-n;
}

int main()
{
    int i, j, NumOfProblems, NumOfCoins, m, sum=0, arr[N];
    //input total number of problems
    cin >> NumOfProblems;

    while(NumOfProblems != 0)
    {
        NumOfProblems--;
        //input total number of coins
        cin >> NumOfCoins;

        //input the coins and calculate their sum
        for (sum=0, i=1; i<=NumOfCoins; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        //the share of each person (minus one if sum is odd)
        m = sum/2;
        memset(v, 0, sizeof(v));
        v[0]=true;
        //fill the v table
        //for each coins of the coins check with true the elements off the table v that
        // can be reached by adding this coin//example adding first coin 3
        //v[0] = v[3] = true//adding 2
        // v[0] = v[2] = v[3] =v[5]
        for (i=1; i<=NumOfCoins; i++)
        {
            for (j=m; j>=1; j--)
            {
                //if element j in the v table is false see if it could be reached or no//if its true leave it
                if (!v[j])
                    v[j] = (arr[i]<=j)?v[j-arr[i]]:false;
            }
        }
        // see the which is the last element that can be reached within the rangeof the share of each person
        for (j=m; j>=1; j--)
        {
            if (v[j])
                break;
        }
        // the rest is the difference between total money and total shares
        cout << absulate(sum-j*2)<<endl;
    }
    return 0;
}

/*
// memset example in c++
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[] = "Hello World";
    memset(str, 'o', 6);
    cout << str;
}
*/