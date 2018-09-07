#include<iostream>
using namespace std;

string name(char ch)
{
  switch(ch)
  {
      case '1':return "One ";break;
      case '2':return "Two ";break;
      case '3':return "Three ";break;
      case '4':return "Four ";break;
      case '5':return "Five ";break;
      case '6':return "Six ";break;
      case '7':return "Seven ";break;
      case '8':return "Eight ";break;
      case '9':return "Nine ";break;
      case '0':return "";
  }
}

int main()
{
    int test;
    cin>>test;
    while(test)
    {
        string N;
        cin>>N;
        int length=N.size();

        for(int i=0;i<length;i++)
        {
            switch(i)
            {
                case 12:cout<<name(N[i])<<"Hundred "
            }
        }

    }
    return 0;
}
