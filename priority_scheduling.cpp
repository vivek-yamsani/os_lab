#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int no;
    cin >> no;
    int burstTime[no];
    int waitTime[no];
    int tat[no];
    pair<int, int> priorities[no];
    for (int i = 0; i < no; i++)
    {
        int priority;
        cin >> burstTime[i] >> priority;
        priorities[i] = {priority, i};
    }
    sort(priorities, priorities + no);
    int currTime = 0;
    for (int i = 0; i < no; i++)
    {
        int idx = priorities[i].second;
        waitTime[idx] = currTime;
        currTime += burstTime[idx];
        tat[idx] = currTime;
    }

    float sum_waitTime = 0, sum_tat = 0;
    cout << "Process\tBt\tWt\tTat\n";
    for (int i = 0; i < no; i++)
    {
        cout << "P" << i + 1 << "\t" << burstTime[i] << "\t" << waitTime[i] << "\t" << tat[i] << "\n";
        sum_tat += tat[i];
        sum_waitTime += waitTime[i];
    }
    cout << "Average Waiting Time : " << sum_waitTime / no << "\n";
    cout << "Average Turn Around Time : " << sum_tat / no << "\n";
    cout << " ";
    for (int i = 0; i < no; i++)
    {
        int x = priorities[i].second, bt = burstTime[x];
        for (int j = 0; j < bt; j++)
            cout << "--";

        cout << " ";
    }
    cout << "\n|";

    for (int i = 0; i < no; i++)
    {
        int x = priorities[i].second, bt = burstTime[x];
        for (int j = 0; j < bt - 1; j++)
            cout << " ";
        cout << "P" << x + 1;
        for (int j = 0; j < bt - 1; j++)
            cout << " ";

        cout << "|";
    }
    cout << "\n";
    for (int i = 0; i < no; i++)
    {
        cout << " ";
        int x = priorities[i].second, bt = burstTime[x];
        for (int j = 0; j < bt; j++)
            cout << "--";
    }

    cout << "\n0";
    for (int i = 0; i < no; i++)
    {
        int x = priorities[i].second, bt = burstTime[x];
        for (int j = 0; j < bt; j++)
            cout << "  ";
        if (tat[x] > 9)
            cout << "\b";

        cout << tat[x];
    }
    cout << "\n";

    return 0;
}