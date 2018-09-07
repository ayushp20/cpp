#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>
using namespace std;

long largestRectangle(vector <long> v) {

    if(v.size()==0)
        return 0;
    else{
        stack <long> height,pos;
        long i=0,max=0,area=0;
        while(i<v.size())
        {
            if(pos.empty()==1)
            {
                height.push(v[i]);
                pos.push(i);
                i++;
            }
            else
            {
               if(v[i]>height.top())
                    {
                        height.push(v[i]);
                        pos.push(i);
                        i++;
                    }
                    else if(v[i]<height.top())
                    {
                        do
                        {area=height.top()*(i-pos.top());
                        height.pop();
                         pos.pop();
                         if (area>max)
                        {
                            max=long(area);
                        }
                        height.pop();
                        }while(height.top()>v[i]);

                         i++;

                    }
                }
            }
        }


return long(max);}
int main() {
    int n;
    cin >> n;
    vector<long> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    long result = largestRectangle(h);
    cout << result << endl;
    return 0;
}


int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    long result = largestRectangle(h);
    cout << result << endl;


    return 0;
}
