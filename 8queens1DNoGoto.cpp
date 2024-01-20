#include <iostream>
#include <cmath>
using namespace std;

void backtrack(int &col) {
    col--;
}

bool ok(int arr[], int col) {
    for(int i = 0; i < col; i++)
    {
        if(((col-i) == abs(arr[col] - arr[i])) or (arr[i] == arr[col]))
        {
            return false;
        }
    }
    return true;
}

void print(int arr[], int solutionNum) {
    cout << "Solution " << solutionNum << endl;
    for(int i = 0; i < 8; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(arr[j] == i)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << "--------------------------------" << endl;
}

int main() {
    int q[8], c = 0, counter = 0;
    q[0] = 0;
    while(c != -1)
    {
        c++;
        if(c == 8)
        {
            counter++;
            print(q, counter);
            backtrack(c);
        }
        else
        {
            q[c] = -1;
        }
        while(q[c] < 8)
        {
            q[c]++;
            if(q[c] == 8)
            {
                backtrack(c);
                if(c == -1)
                {
                    return 0;
                }
            }
            else if(ok(q, c))
            {
                break;
            }
        }
    }
    return 0;
}
    
