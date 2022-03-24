#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    vector<int> frames(4, -1);
    vector<int> p;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int dummy;
        cin >> dummy;
        p.push_back(dummy);
    }
    int pf = 0, insertion_index = 0;
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Process considered:" << p[i] << endl;
        int min = INT_MAX;
        bool already_presen_in_frame = false;
        for (int j = 0; j < 4; j++)
        {
            if (frames[j] == p[i])
            {
                already_presen_in_frame = true;
                break;
            }
        }
        if (already_presen_in_frame == false)
        {
            pf++;
            frames[insertion_index % 4] = p[i];
            insertion_index++;
        }

        for (int i = 0; i < 4; i++)
            cout << frames[i] << " ";
        cout << endl;
    }
    cout << "No. of page faults:" << pf << endl;
    return 0;
}

// 22 4 7 2 0 1 3 2 3 4 2 1 5 7 6 2 6 3 2 1 2 3 6