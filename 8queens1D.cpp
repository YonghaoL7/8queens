#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int q[8], c = 0, counter = 0;
  q[0] = 0;
  nc: c++;
  if(c == 8)
  {
    goto print;
  }
  q[c] = -1;
  nr: q[c]++;
  if(q[c] == 8)
  {
    goto backtrack;
  }
  //Row and diagonal test
  for(int i = 0; i < c; i++)
  {
    if(((c-i) == abs(q[c] - q[i])) or (q[i] == q[c]))
    {
      goto nr;
    }
  }
  goto nc;
  backtrack: c--;
  if(c == -1)
  {
    return 0;
  }
  goto nr;
  print: counter++; 
  cout << "Solution " << counter << endl;
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(q[j] == i)
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
  cout << "-----------------------------------" << endl;
  goto backtrack;
}