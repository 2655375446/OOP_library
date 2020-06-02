//
//  main.cpp
//  周师扬 18040400054
//  编写日期：2020年3月5日
//  oop第一次上机实验第一题
//

#include <iostream>
#include <map>

using namespace std;//使用std命名空间

struct Name_message//定义一个有关name信息的结构体
{
    int count;//name输入的次数
    double sum;//name对应的value的总和
    Name_message()//利用构造函数进行初始化新的Name_message变量
    {
        count=0;
        sum=0;
    }
};

typedef map<string,Name_message> dict_type;//定义一个map类型
dict_type my_Dict;
dict_type::iterator iter;//建立一个dict_type类型的迭代器

void Info_message();

int main()
{
    Info_message();
    int count=0;
    int sum=0;
    cout<<"按名字小计:"<<endl;//输出按名字小记信息
    for(iter=my_Dict.begin();iter!=my_Dict.end();++iter)
    {
        cout<<" "<<iter->first<<" 总和:"<<iter->second.sum
                              <<" 平均数:"<<iter->second.sum/iter->second.count
                              <<endl;
        count+=iter->second.count;
        sum+=iter->second.sum;
    }
    cout<<"总计:"<<endl;//输出总计信息
    cout<<" 总和:"<<sum<<" ";
    cout<<" 平均数:"<<sum/count<<endl;
}

void Info_message()//输入信息函数
{
    string name;//姓名
    double value;//值
    while(1)
    {
        cout<<"Please enter the name and the value : "<<endl;
        cin>>name;if(!cin)break;//如果不输入就结束循环
        cin>>value;if(!cin)break;//如果不输入就结束循环
        Name_message & wordInfo=my_Dict[name];//定义一个name对应的value的引用
        if(wordInfo.count==0)//name值第一次出现
        {
            wordInfo.count=1;
            wordInfo.sum=value;
        }
        else//name值之后出现
        {
            wordInfo.count+=1;
            wordInfo.sum+=value;
        }
    }//end of while（1）
}
