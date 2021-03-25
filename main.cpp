#include <iostream>
#include <string>
#include <vector>
#include<sstream>
using namespace std;

string FindIntersection(string strArr[], int arrLength) {
  
  // code goes here
  string first, second;
  first = strArr[0];
  second = strArr[1];
  vector<string> fvec, svec;

  stringstream ss1(first);
  stringstream ss2(second);

  while(ss1.good())
  {
    string sub;
    getline(ss1, sub, ',');
    fvec.push_back(sub);
  }

  for(int i = 0; i < fvec.size(); i++)
  {
    if(fvec[i].length()>1 && i != 0)
    {
      fvec[i] = fvec[i].substr(1,fvec[i].length());
    }
  }

  while(ss2.good())
  {
    string sub;
    getline(ss2, sub, ',');
    svec.push_back(sub);
  }

  for(int i = 0; i < svec.size(); i++)
  {
    if(svec[i].length()>1 && i != 0)
    {
      svec[i] = svec[i].substr(1,svec[i].length());
    }
  }

  vector<string> result;
  bool once = true;

  for(int i = 0; i<fvec.size(); i++)
  {
    for(int j = 0; j<svec.size(); j++)
    {
      if(svec[j] == fvec[i])
      {
        result.push_back(fvec[i]);
        once = false;
      }
    }
  }

  if(once)
  {
    return "false";
  }

  string fin;
  for(int a = 0; a<result.size();a++)
  {
    fin += result[a];
    fin += ",";
  }
    
  return fin.substr(0,fin.length()-1);

}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << FindIntersection(A, arrLength);
  return 0;
    
}
