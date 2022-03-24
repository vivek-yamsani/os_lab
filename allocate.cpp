#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void BestFit(vector<int> pro, vector<int> block)
{
    cout << "Best Fit allocation\n";
    vector<int> allocated(pro.size());
    for (int j = 0; j < pro.size(); j++)
    {
        int just_sufficient_index = -1;
        for (int i = 0; i < block.size(); i++)
        {
            if (block[i] >= pro[j])
            {
                if (just_sufficient_index >= 0)
                {
                    just_sufficient_index = block[just_sufficient_index] < block[i] ? just_sufficient_index : i;
                }
                else
                    just_sufficient_index = i;
            }
        }
        allocated[j] = just_sufficient_index;
        if (just_sufficient_index >= 0)
            block[just_sufficient_index] -= pro[j];
    }

    for (int i = 0; i < pro.size(); i++)
    {
        cout << pro[i] << " " << allocated[i] << "\n";
    }
    cout << "\n";
}

void FirstFit(vector<int> pro, vector<int> block)
{
    cout << "First Fit allocation\n";
    vector<int> allocated(pro.size());
    for (int j = 0; j < pro.size(); j++)
    {
        int sufficient_index = -1;
        for (int i = 0; i < block.size(); i++)
        {
            if (block[i] >= pro[j])
            {
                sufficient_index = i;
                break;
            }
        }
        allocated[j] = sufficient_index;
        if (sufficient_index >= 0)
            block[sufficient_index] -= pro[j];
    }

    for (int i = 0; i < pro.size(); i++)
    {
        cout << pro[i] << " " << allocated[i] << "\n";
    }
    cout << "\n";
}

void WorstFit(vector<int> pro, vector<int> block)
{
    cout << "Worst Fit allocation\n";
    vector<int> allocated(pro.size());
    for (int j = 0; j < pro.size(); j++)
    {
        int most_sufficient_index = -1, val = -1;
        for (int i = 0; i < block.size(); i++)
        {
            if (pro[j] <= block[i] && val < block[i])
            {
                val = block[i];
                most_sufficient_index = i;
            }
        }
        allocated[j] = most_sufficient_index;
        if (most_sufficient_index >= 0)
            block[most_sufficient_index] -= pro[j];
    }

    for (int i = 0; i < pro.size(); i++)
    {
        cout << pro[i] << " " << allocated[i] << "\n";
    }
    cout << "\n";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> pro(n), block(m);
    for (int &i : pro)
        cin >> i;
    for (int &i : block)
        cin >> i;
    cout << "\n";
    BestFit(pro, block);
    FirstFit(pro, block);
    WorstFit(pro, block);
    return 0;
}
/*
4 5
212 317 172 426
100 450 250 300 600
*/