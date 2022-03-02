#include <iostream>
#include <queue>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    int no;
    cin >> no;
    int timeQuantum = 2, idle_time = 0;
    int arrivalTime[no];
    int waitTime[no];
    int burstTime[no];
    int tat[no];
    int rem_bt[no];
    int finish[no];
    float sum_waitingTime = 0, sum_tat = 0;
    int currTime = 0;
    for (int i = 0; i < no; i++)
    {
        cin >> arrivalTime[i] >> burstTime[i];
    }

    for (int i = 0; i < no; i++)
    {
        rem_bt[i] = burstTime[i];
        finish[i] = arrivalTime[i];
        waitTime[i] = 0;
    }

    queue<int> q;

    while (true)
    {

        if (!q.empty())
        {
            int pro = q.front();
            q.pop();
            int inc = 0;
            if (rem_bt[pro] > timeQuantum)
            {
                waitTime[pro] += currTime - finish[pro];
                inc = timeQuantum;
                finish[pro] = currTime + inc;
                rem_bt[pro] -= timeQuantum;
            }
            else
            {
                waitTime[pro] += currTime - finish[pro];
                inc = rem_bt[pro];
                finish[pro] = currTime + inc;
                rem_bt[pro] = 0;
            }
            while (inc--)
            {
                currTime++;
                for (int i = 0; i < no; i++)
                {
                    if (arrivalTime[i] == currTime)
                    {
                        q.push(i);
                    }
                }
            }
            if (rem_bt[pro])
                q.push(pro);
        }
        else
        {
            int mn = INT_MAX, idx = -1;
            for (int i = 0; i < no; i++)
            {
                if (rem_bt[i] && mn > arrivalTime[i])
                    mn = arrivalTime[i], idx = i;
            }
            if (mn == INT_MAX)
                break;
            else
                q.push(idx);
            idle_time += mn - currTime;
            currTime = mn;
        }
    }
    for (int i = 0; i < no; i++)
    {
        tat[i] = finish[i] - arrivalTime[i];
        sum_waitingTime += waitTime[i];
        sum_tat += tat[i];
    }
    cout << "Process\tAt\tWt\tTat\tBt\n";
    for (int i = 0; i < no; i++)
    {
        cout << "P" << i + 1 << "\t" << arrivalTime[i] << "\t" << waitTime[i] << "\t" << tat[i] << "\t" << burstTime[i] << "\n";
    }
    cout << fixed << "Average Waiting Time : " << setprecision(7) << sum_waitingTime / no << "\n";
    cout << fixed << "Average Tat Time : " << setprecision(7) << sum_tat / no << "\n";
    cout << "Idle cpu time : " << idle_time << "\n";
    return 0;
}