#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,checks=0,checksM;
    cin>>n;
    while(n--)
    {
        checks=0,checksM=0;
        char a[8][8];

        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                cin>>a[i][j];

        //Promote Pawn
        for(int j=0;j<8;j++)
            if(a[1][j]=='P'&&a[0][j]=='#')
            {
                a[0][j]='M';
                a[1][j]='#';
            }



        //scan for king and its check cases if found.
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                {
                    if(a[i][j]=='k')
                    {
                        //Discovered Checks
                        //right Queen Rook King
                        for(int k=j+1;k<8;k++)
                        {
                           if(a[i][k]=='#')
                                continue;
                            if((a[i][k]>=97&&a[i][k]<=122)||a[i][k]=='P'||a[i][k]=='B'||a[i][k]=='N')
                                break;

                            if(a[i][k]=='Q'||a[i][k]=='R')
                                {
                                checks++;
                                 break;
                                 }
                            if(a[i][k]=='M')
                               {
                                checksM=2;
                                break;
                               }
                        }



                        //left Queen Rook King
                        for(int k=j-1;k>=0;k--)
                        {
                           if(a[i][k]=='#')
                                continue;
                            if((a[i][k]>=97&&a[i][k]<=122)||a[i][k]=='P'||a[i][k]=='B'||a[i][k]=='N')
                                break;

                            if(a[i][k]=='Q'||a[i][k]=='R')
                                {
                                checks++;
                                 break;}
                            if(a[i][k]=='M')
                               {
                                checksM=2;
                                break;
                               }
                        }
                        //cout<<"mark1";

                        //down Queen Rook King
                        for(int k=i+1;k<8;k++)
                        {
                            if(a[i+1][j]=='K')
                            {
                                checks++;break;
                            }
                            if(a[k][j]=='#')
                                continue;
                            if((a[k][j]>=97&&a[k][j]<=122)||a[k][j]=='P'||a[k][j]=='B'||a[k][j]=='N')
                                break;
                            if(a[k][j]=='Q'||a[k][j]=='R')
                                {checks++;break;}
                        }

                        //up Queen Rook King
                        for(int k=i-1;k>=0;k--)
                        {
                            if(a[i-1][j]=='K')
                            {
                                checks++;break;
                            }
                            if(a[k][j]=='#')
                                continue;
                            if((a[k][j]>=97&&a[k][j]<=122)||a[k][j]=='P'||a[k][j]=='B'||a[k][j]=='N')
                                break;

                            if(a[k][j]=='Q'||a[k][j]=='R')
                                {
                                checks++;
                                 break;
                                 }
                            if(a[k][j]=='M')
                               {
                                checksM=2;
                                break;
                               }
                        }
                        //cout<<"mark2";
                         //right to left up diagonal Queen Bishop King Pawn
                        for(int k=i-1,m=j-1;k>=0&&m>=0;k--,m--)
                        {
                            if(a[k][m]=='#')
                                continue;
                            if((a[k][m]>=97&&a[k][m]<=122)||a[k][m]=='P'||a[k][m]=='R'||a[k][m]=='N')
                                break;
                            if(a[k][m]=='Q'||a[k][m]=='B')
                                {
                                checks++;
                                break;}
                            if(a[k][m]=='M')
                               {
                                checksM=2;
                                break;
                               }
                        }

                        //cout<<checks<<" diag\n";
                         //left to right up diagonal Queen Bishop King Pawn
                        for(int k=i+1, m=j+1;k<8&&m<8;k++,m++)
                        {
                            if(a[k][m]=='#')
                                continue;
                            if((a[k][m]>=97&&a[k][m]<=122)||a[k][m]=='P'||a[k][m]=='R'||a[k][m]=='N')
                                break;
                            if(a[k][m]=='Q'||a[k][m]=='B')
                                {
                                checks++;
                                 break;}
                            if(a[k][m]=='M')
                               {
                                checksM=2;
                                break;
                               }
                        }

                       // cout<<checks<<" diag\n";

                        //left to right up queen bishop pawn
                        for(int k=i-1, m=j+1;k>=0&&m<8;k--,m++)
                        {
                            if(a[k][m]=='#')
                                continue;
                            if((a[k][m]>=97&&a[k][m]<=122)||a[k][m]=='P'||a[k][m]=='R'||a[k][m]=='N')
                                break;
                            if(a[k][m]=='Q'||a[k][m]=='B')
                                {
                                checks++;
                                 break;
                                }
                            if(a[k][m]=='M')
                               {
                                checksM=2;
                                break;
                               }
                        }

                        //cout<<checks<<" diag\n";

                        //right to left down queen bishop pawn
                        for(int k=i+1, m=j-1;k<8&&m>=0;k++,m--)
                        {
                            if(a[k][m]=='#')
                                continue;
                            if((a[k][m]>=97&&a[k][m]<=122)||a[k][m]=='P'||a[k][m]=='R'||a[k][m]=='N')
                                break;
                            if(a[k][m]=='Q'||a[k][m]=='B'||a[k][m]=='M')
                                {
                                checks++;
                                 break;}
                            if(a[k][m]=='M')
                               {
                                checksM=2;
                                break;
                               }
                        }
                        //knight
                        if(i-2>=0&&j-1>=0)
                            if(a[i-2][j-1]=='M')
                                checksM=1;

                        if(i-2>=0&&j+1<8)
                        if(a[i-2][j+1]=='M')
                                checksM++;

                        if(i-1>=0&&j-2>=0)
                        if(a[i-1][j-2]=='M')
                            checksM++;

                        if(i-1>=0&&j+2<8)
                        if(a[i-1][j+2]=='M')
                            checksM++;


                        if(i+2<8&&j-1>=0)
                        if(a[i+2][j-1]=='M')
                                checksM++;

                        if(i+2<8&&j+1<8)
                        if(a[i+2][j+1]=='M')
                                checksM++;

                        if(i+1<8&&j+2<8)
                        if(a[i+1][j+2]=='M')
                                checksM++;


                        if(i+1<8&&j-2>=0)
                        if(a[i+1][j-2]=='M')
                                checksM++;


                    }


                }
                if(checks>0)
                    cout<<4<<endl;
                else
                    cout<<checksM<<endl;



    }


    return 0;
}
