#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, int>> frames(4, {-1, -1});
    int timer = 0;
    vector<int> p;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int dummy;
        cin >> dummy;
        p.push_back(dummy);
    }
    int pf = 0;
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Process considered:" << p[i] << endl;
        int min = INT_MAX, minind;
        bool already_present_in_frame = false;
        for (int j = 0; j < 4; j++)
        {
            if (frames[j].second < min)
            {
                min = frames[j].second;
                minind = j;
            }
            if (frames[j].first == p[i])
            {
                already_present_in_frame = true;
                frames[j].second = timer;
                break;
            }
        }
        if (!already_present_in_frame)
        {
            pf++;
            pair<int, int> pr = {p[i], timer};
            frames[minind] = pr;
        }
        cout << "timer:" << timer << "  ";
        for (int i = 0; i < 4; i++)
            cout << frames[i].first << " ";
        cout << endl;
        timer++;
    }
    cout << "No. of page faults:" << pf << endl;
    return 0;
}
// 22 4 7 2 0 1 3 2 3 4 2 1 5 7 6 2 6 3 2 1 2 3 6