#include<bits/stdc++.h>

using namespace std;


int main(){
    int n1,s1=0;
    int n2,s2=0;
    int n3,s3=0;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for(int h1_i = 0;h1_i < n1;h1_i++){
       cin >> h1[h1_i];s1+=h1[h1_i];
    }
    vector<int> h2(n2);
    for(int h2_i = 0;h2_i < n2;h2_i++){
       cin >> h2[h2_i];s2+=h2[h2_i];
    }
    vector<int> h3(n3);
    for(int h3_i = 0;h3_i < n3;h3_i++){
       cin >> h3[h3_i];s3+=h3[h3_i];
    }
    int i=0,j=0,k=0;
    while(s1>=0&&s2>=0&&s3>=0)
    {
        if(s1==s2&&s2==s3)
            {cout<<s1;break;}
        else if(s1>=s2&&s1>=s3)
        {
            s1-=h1[i];
            i++;
        }
        else if(s2>=s1&&s2>=s3)
        {
            s2-=h2[j];
            j++;
        }
        else if(s3>=s2&&s3>=s1)
        {
            s3-=h3[k];
            k++;
        }

    }
    return 0;
}
