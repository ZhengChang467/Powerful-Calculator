/*
Powerful Calculator
Designed by ZhengChang
*/
#include <iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
string finalout;
string add(string a,string b)
{
    stack<char> result,p1,p2;
    for(int i=0; i<a.size(); i++)
    {
        p1.push(a[i]);
    }
    for(int i=0; i<b.size(); i++)
    {
        p2.push(b[i]);
    }
    int carry=0;
    for(int i=1; i<=max(a.size(),b.size()); i++)
    {
        if(p1.empty()!=true&&p2.empty()!=true)
        {
            result.push((p1.top()-'0'+p2.top()-'0'+carry)%10+'0');
            carry=(p1.top()-'0'+p2.top()-'0'+carry)/10;
            p1.pop();
            p2.pop();
        }
        if(p1.empty()==true&&p2.empty()==false)
        {
            result.push((p2.top()-'0'+carry)%10+'0');
            carry=(p2.top()-'0'+carry)/10;
            p2.pop();
        }
        if(p2.empty()==true&&p1.empty()==false)
        {
            result.push((p1.top()-'0'+carry)%10+'0');
            carry=(p1.top()-'0'+carry)/10;
            p1.pop();
        }
    }
    if(carry!=0)
        result.push(carry+'0');
    string out;
    for(int i=0;!result.empty();i++){
        out+=result.top();
        result.pop();
    }
    return out;
}
string sub(string a,string b)
{
    int index=0;
    stack<char> result,p1,p2;

    if(a.size()==b.size())
    {
        if(a<b)
        {
            swap(a,b);
            index=1;
        }
    }
    else if(a.size()<b.size())
    {
        swap(a,b);
        index=1;
    }
    for(int i=0; i<a.size(); i++)
    {
        p1.push(a[i]);
    }
    for(int i=0; i<b.size(); i++)
    {
        p2.push(b[i]);
    }
    int borrow=0,temp;
    for(int i=1; i<=a.size(); i++)
    {
        if(p1.empty()!=true&&p2.empty()!=true)
        {
            temp=p1.top()-'0'-borrow;
            if(temp>=p2.top()-'0')
            {
                borrow=0;
            }
            else
            {
                borrow=1;
            }
            p1.pop();
            p1.push(temp+10+'0');//更新
            result.push((p1.top()-p2.top())%10+'0');
            p1.pop();
            p2.pop();
        }
        else if(p2.empty()==true&&p1.empty()!=true)
        {
            temp=p1.top()-'0'-borrow;
            if(temp>=0)
            {
                borrow=0;
            }
            else
            {
                borrow=1;
            }
            p1.pop();
            p1.push((temp+10)%10+'0');//更新
            result.push(p1.top());
            p1.pop();
        }
    }
    if(borrow!=0)
        result.push(10-borrow+'0');
    int s=result.size();
    for(int i=0;i<s;i++)
    {
        if(result.top()=='0'&&result.size()>1)
            result.pop();
    }
    if(index==1)
    {
        result.push('-');
    }
    string out;
    for(int i=0;!result.empty();i++){
        out+=result.top();
        result.pop();
    }
    return out;
}
string multipy(string a,string b)
{
    string submultipy="0",out="0";
    stack<char> p;
    for(int i=0;i<b.size();i++)
        p.push(b[i]);
    for(int i=0;i<b.size();i++){
        submultipy="0";
        for(int j=0;j<p.top()-'0';j++){
            submultipy=add(submultipy,a);
        }
        for(int j=0;j<i;j++)
        {
            submultipy+='0';
        }
        out=add(out,submultipy);
        p.pop();
    }
    return out;
}
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        finalout=add(s1,s2);
        cout<<finalout<<endl;
        finalout=sub(s1,s2);
        cout<<finalout<<endl;
        finalout=multipy(s1,s2);
        cout<<finalout<<endl;
    }
    return 0;
}
