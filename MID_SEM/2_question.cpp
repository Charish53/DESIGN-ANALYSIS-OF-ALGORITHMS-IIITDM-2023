 #include<iostream>
using namespace std;
void findWaitingTime(int processes[], int n, int bt[],
								int wt[], int at[])
{
	int service_time[n];
	service_time[0] = at[0];
	wt[0] = 0;

	for (int i = 1; i < n ; i++)
	{
		service_time[i] = service_time[i-1] + bt[i-1];
		wt[i] = service_time[i] - at[i];
		if (wt[i] < 0)
			wt[i] = 0;
	}
}

void findavgTime(int processes[], int n, int bt[], int at[])
{
	int wt[n], tat[n];

	findWaitingTime(processes, n, bt, wt, at);
	int total_wt = 0;
	for (int i = 0 ; i < n ; i++)
	{
		total_wt = total_wt + wt[i];
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
}

int main()
{
    int n=2;
    int processes[]={1,2};
    int m;
    cout<<"Enter number of jobs:";
    cin>>m;
    int a[m],e[m];
    cout<<"Enter starting time :";
    for(int i=0;i<n;i++)
        cin>>a[i];
	cout<<"Enter end time :";
    for(int i=0;i<n;i++)
        cin>>e[i];
    
	findavgTime(processes, n, e,a);

	return 0;
}
