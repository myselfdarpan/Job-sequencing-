#include <iostream>
#include <algorithm>

using namespace std;

int total_profit=0;

void sort_job(int n, char id[], int dead[], int profit[])
{
    for(int m=n;m>=0;m--)
    {
        for(int i=0; i<n-1;i++)
        {
            int k = i+1;
            if(profit[i]<profit[k])
            {
                int temp;
                temp=profit[i];
                profit[i]=profit[k];
                profit[k]=temp;

                temp=dead[i];
                dead[i]=dead[k];
                dead[k]=temp;

                char tem;
                tem=id[i];
                id[i]=id[k];
                id[k]=tem;
            }
        }
    }
}

void printjobScheduling(int n, char id[], int dead[], int profit[])
{

    int result[n];
    bool slot[n];

    for(int i=0; i<n; i++)
    {
        slot[i]=false;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=dead[i]-1; j>=0; j--)
        {
            if(slot[j]==false)
            {
                result[j] = i;
                slot[j] = true;
                total_profit += profit[i];
                break;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        if(slot[i])
        {
            cout<<id[result[i]] << " ";
        }
        cout<<endl;
    }

}

int main()
{
    int dead[10],profit[10];
    char id[10];
    int n;

    cout<<"Enter the number of jobs: "<<endl;
    cin>>n;

    for(int i=0; i<n;i++)
    {
        cout<<"Enter the job "<<i+1<<" Id , deadline and profit: "<<endl;
        cin>>id[i]>>dead[i]>>profit[i];
    }
    sort_job(n, id, dead, profit);
    cout<<"Following is the maximum profit sequence of job: ";

    //Function call
    printjobScheduling(n, id, dead, profit);
    cout<<"Maximum profit is : "<<total_profit;
    return 0;
}
