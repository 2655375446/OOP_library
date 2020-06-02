//
//  main.cpp
//  周师扬 18040400054
//  编写日期：2020年3月20日
//  oop第二次上机实验第四题
//

#include <iostream>
#include <ctime>//调用头文件判断星期几

using namespace std;

typedef struct Date//定义一个Date类型
{
    int year;
    int month;
    int day;
}Date;

Date Gcalendar;//定义一个万年历

bool If_Leap(int);//判断是否是闰年
void Get_Date();//输入日期
void Put_Date();//输出日期
void Oprition(char,int);
void Op_month(int);//对月份的操作
void Op_day(int );//对日的操作
bool F_week();//判断是星期几
int F_month(int);//判断month的flag
void F_Monday();

int main(int argc, const char * argv[])
{
    Get_Date();
    char tag;
    int value;
    cout<<"Please enter the tag you want to oprete and the value : "<<endl;
    cin>>tag;
    cin>>value;
    Oprition(tag,value);
    Put_Date();
    F_week();
    F_Monday();
    return 0;
}

void Get_Date()//输入函数
{
    cout<<"Please enter the year, the month and the day:"<<endl;
    cin>>Gcalendar.year;
    cin>>Gcalendar.month;
    cin>>Gcalendar.day;
}

void Put_Date()//输出函数
{
    cout<<"Now date is:";
    cout<<Gcalendar.year<<'/';
    cout<<Gcalendar.month<<'/';
    cout<<Gcalendar.day<<endl;
}

void Oprition(char ch,int n)//y代表对年进行操作、m代表对月进行操作、d代表对日进行操作
{
    switch (ch)
    {
        case 'y':
            Gcalendar.year+=n;
            break;
        case 'm':
            Op_month(n);
            break;
        case 'd':
            Op_day(n);
        default:
            break;
    }
}

void Op_month(int n)//对月的操作
{
    int flag_1,flag_2;
    flag_1=F_month(Gcalendar.month);//判断之前月份的来类型
    Gcalendar.month+=n;
    flag_2=F_month(Gcalendar.month);//判断之后月份的类型
    Gcalendar.year+=Gcalendar.month/12;
    Gcalendar.month=Gcalendar.month%12;
    if((Gcalendar.day==31)&&(flag_1==2)&&(flag_2==3))
    {
        Gcalendar.day=30;//31天的月份的处理
    }
    if((Gcalendar.month==2)&&(flag_1==2)
       &&(Gcalendar.day==31)&&(If_Leap(Gcalendar.year)))
    {
        Gcalendar.day=29;//闰年的2月
    }
    if((Gcalendar.month==2)&&(flag_1==3)
       &&(Gcalendar.day==30)&&(If_Leap(Gcalendar.year)))
    {
        Gcalendar.day=29;//闰年的2月
    }
    if((Gcalendar.month==2)&&(flag_1==2)
       &&(Gcalendar.day==31)&&(!If_Leap(Gcalendar.year)))
    {
        Gcalendar.day=28;//平年的2月
    }
    if((Gcalendar.month==2)&&(flag_1==3)
       &&(Gcalendar.day==30)&&(!If_Leap(Gcalendar.year)))
    {
        Gcalendar.day=28;//平年的2月
    }
}

void Op_day(int n)
{
    Gcalendar.day+=n;
    int flag;//用来判断月份的类型
    flag=F_month(Gcalendar.month);
    if(flag==2)
    {
        if(Gcalendar.day>31)
        {
            Op_month((Gcalendar.day+n)/31);
            Gcalendar.day=Gcalendar.day%31;
        }
    }
    if(flag==3)
    {
        if(Gcalendar.day>30)
        {
            Op_month((Gcalendar.day+n)/30);
            Gcalendar.day=Gcalendar.day%30;
        }
    }
    if(flag==1)
    {
        if((If_Leap(Gcalendar.year))&&(Gcalendar.day>29))
        {
            Op_month((Gcalendar.day+n)/29);
            Gcalendar.day=Gcalendar.day%29;
        }
        if((!If_Leap(Gcalendar.year))&&(Gcalendar.day>28))
        {
            Op_month((Gcalendar.day+n)/28);
            Gcalendar.day=Gcalendar.day%28;
        }
    }
}

bool If_Leap(int year)//判断是否为闰年
{
    if((year%100==0)&&(year%400!=0))
    {
        return false;
    }
    else if(year%4!=0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int F_month(int n)
{
    int flag;
    if((Gcalendar.month==2)&&((If_Leap(Gcalendar.year))))
    {
        flag=1;
    }
    else if((Gcalendar.month%2==1)&&(Gcalendar.month<8))
    {
        flag=2;//2代表31的月份
    }
    else if((Gcalendar.month%2==0)&&(Gcalendar.month>7))
    {
        flag=2;
    }
    else
    {
        flag=3;//3代表30天的月份
    }
    return flag;
}

bool F_week()
{
    time_t rawtime;
    struct tm * timeinfo;
    const char * weekday[]={"Sunday","Monday","Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday"};
    
    time (&rawtime);
    timeinfo=localtime(&rawtime);
    timeinfo->tm_year=Gcalendar.year-1900;
    timeinfo->tm_mon=Gcalendar.month-1;
    timeinfo->tm_mday=Gcalendar.day;
    
    mktime (timeinfo);
    cout<<"That day is a "<<weekday[timeinfo->tm_wday]<<endl;
    if(timeinfo->tm_wday==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void F_Monday()
{
    while(1)
    {
        if(F_week())
        {
            break;
        }
        Op_day(1);
    }
    cout<<"First Monday:"<<endl;
    Put_Date();
}
