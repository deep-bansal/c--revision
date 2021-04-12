#include <bits/stdc++.h>
using namespace std;

void sumZero(int arr[], int n) {
    unordered_map<int, int>mp;
    for (int i = 0; i < n; ++i)
    {
        mp[arr[i]] == i;
    }

    for (int i = 0; i < n; ++i)
    {
        if (mp.count(0 - arr[i])) {
            cout << arr[i] << " + " << 0 - arr[i] << " = 0" << endl;
            break;
        }

    }
    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }
}

void subarraySumZero(int*arr, int n) {
    unordered_map<int, int>mp;
    int prefixSum = 0;
    for (int i = 0; i < n; ++i)
    {
        prefixSum += arr[i];
        if (prefixSum == 0) {
            cout << 0 << " " << i << endl;
        } else if (mp.count(prefixSum) && mp[prefixSum] != i) {
            cout << mp[prefixSum] + 1 << " " << i << endl;
        }
        else {
            mp[prefixSum] = i;
        }
    }
}

void longestSumZero(int* arr, int n) {
    unordered_map<int, int>mp;
    int prefixSum = 0;
    int maxLength = 0;
    int left = -1;
    int right = -1;

    for (int i = 0; i < n; ++i)
    {
        prefixSum += arr[i];
        if (arr[i] == 0 && maxLength == 0) {
            maxLength = 1;
            left = i;
            right = i;
        }
        if (prefixSum == 0) {
            if (i + 1 > maxLength) {
                maxLength = i + 1;
                left = 0;
                right = i;
            }
        }
        if (mp.count(prefixSum)) {
            int currl = i - mp[prefixSum];
            if (currl > maxLength) {
                left = mp[prefixSum] + 1;
                right = i;
                maxLength = currl;
            }

        } else {
            mp[prefixSum] = i;
        }
    }
    cout << maxLength << endl;
    cout << left << "    to    " << right << endl;
}
void targetSumPair(int* arr, int n, int target) {
    unordered_map<int, int>mp;

    for (int i = 0; i < n; ++i)
    {
        if (mp.count(target - arr[i])) {
            cout << target - arr[i] << " " << arr[i] << endl;
        } else {
            mp[arr[i]] = i;
        }
    }
}

void longestSubarrayWithSumTarget(int* arr, int n, int target) {
    unordered_map<int, int>mp;
    int prefixSum = 0, maxLength = 0, left = -1, right = -1;

    for (int i = 0; i < n; ++i)
    {
        prefixSum += arr[i];
        if (arr[i] == target && maxLength == 0) {
            left = i;
            right = i;
            maxLength = 1;
        }
        if (prefixSum == target) {
            if (i + 1 > maxLength) {
                maxLength = i + 1;
                left = 0;
                right = i;
            }
        }
        if (mp.count(prefixSum - target)) {
            int currl = i - mp[prefixSum - target];
            if (currl > maxLength) {
                left = mp[prefixSum - target] + 1;
                right = i;
                maxLength = currl;
            } else {
                mp[prefixSum] = i;
            }
        } else {
            mp[prefixSum] = i;
        }
    }
    cout << maxLength << endl;
    cout << left << "    to    " << right << endl;

}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 1, 2, 0, -1, 2};
    int n = sizeof(arr) / sizeof(int);
    int target;
    cin >> target;

    // sumZero(arr,n);

    // subarraySumZero(arr, n);
    // longestSumZero(arr,n);
    // targetSumPair(arr,n,target);
    longestSubarrayWithSumTarget(arr, n, target);

    return 0;
}