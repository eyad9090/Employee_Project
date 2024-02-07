#include<bits/stdc++.h>
using namespace std;
//-------------helper methods-------------------------------------
char to_upper(char c);
char to_lower(char c);
char is_lower(char c);
char is_upper(char c);
string to_lower(string str);
int string_to_integer(string number);
int get_integer_in_range(int range_start,int range_end);
bool is_only_character_space(string str);
string get_character_space(string message);
bool is_valid_character( char valid_characters[],int sz,int c );
char get_valid_lower_character(char lower_characters[],int sz);
//---------------menu methods----------------------------------
void display_menu();
int get_menu_choice();
//----------Employee methods-----------------------------
int get_age();
string get_name();
int get_salary();
bool is_valid_gender(char c);
char get_gender();
void add_employee();
void print_employees();
void start_employee_program();
void delete_age_range();
void update_salary_by_name();


int main()
{
    start_employee_program();
    return 0;
}


//---------------helper methods------------------------------

char to_upper(char c)
{
    if(is_lower(c))
    {
        c=(char)(c-'a'+'A');
    }
    return c;
}
char to_lower(char c)
{
    if(is_upper(c))
    {
        c=(char)(c-'A'+'a');
    }
    return c;
}
char is_lower(char c)
{
    if(c>='a'&&c<='z')
        return true;
    return false;
}
char is_upper(char c)
{
    if(c>='A'&&c<='Z')
        return true;
    return false;
}

string to_lower(string str)
{
    for(char &c:str)
    {
        if(is_upper(c))
        {
            c=to_lower(c);
        }
    }
    return str;
}

int string_to_integer(string number)
{
    int ans=0;
    for(int i=0;i<number.size();i++)
    {
        if(number[i]>='0'&&number[i]<='9')
        {
            ans=ans*10+(number[i]-'0');
        }
        else
            return -1;
    }
    return ans;
}
int get_integer_in_range(int range_start,int range_end)
{
    string choice;
    cin>>choice;
    int ans=-1;
    while(ans==-1)
    {
        ans=string_to_integer(choice);
        if(ans>=range_start&&ans<=range_end)
        {
            return ans;
        }
        else
        {
            cout<<"Invalid\n";
            cout<<"Please enter valid number in range["
            <<range_start<<"-"<<range_end<<"]: ";
            cin>>choice;
            ans=-1;
        }
    }
}
bool is_only_character_space(string str)
{
    for(char c:str)
    {
        if( (c>='a'&&c<='z') || (c>='A'&&c<='Z')||c==' ' )
        {
            continue;
        }
        return false;
    }
    return true;
}
string get_character_space(string message)
{
    cout<<message;
    string str;
    fflush(stdin);
    getline(cin,str);
    while(!is_only_character_space(str))
    {
        cout<<"invalid\n";
        cout<<message;
        cin>>str;
    }
    str=to_lower(str);
    return str;
}

bool is_valid_character( char valid_characters[],int sz,int c )
{
    for(int i=0;i<sz;i++)
    {
        if(valid_characters[i]==c)
            return true;
    }
    return false;
}
char get_valid_lower_character(char lower_characters[],int sz)
{
    string ans;
    cin>>ans;
    while(ans.size()!=1
          &&!is_valid_character(lower_characters,sz,ans[0]))
    {
        cout<<"Invalid\n";
        cout<<"Please enter valid character from[";
        bool is_first=true;
        for(int i=0;i<sz;i++)
        {
            if(!is_first)
                cout<<",";
            cout<<lower_characters[i];
            is_first=false;
        }
        cout<<"]:";
        cin>>ans;
        ans[0]=to_lower(ans[0]);
    }
    return ans[0];
}


//---------------menu methods-----------------------------------
int menu_size=5;
void display_menu()
{
    cout<<"--------------------Menu-----------------------------\n";
    cout<<"1) Add new employee\n"
        <<"2) Print all employees\n"
        <<"3) Delete by age\n"
        <<"4) Update Salary by name\n"
        <<"5) Exit\n";
}

int get_menu_choice()
{
    display_menu();
    cout<<"Please enter your choice:";
    int choice=get_integer_in_range(1,menu_size);
    return choice;
}
//----------Employee methods-----------------------------
int current_employee_sz=0;
const int employee_sz=500;
string employee_name[employee_sz];
int employee_age[employee_sz];
int employee_salary[employee_sz];
char employee_gender[employee_sz];
//-----------------read employee data-----------------------------
int get_age()
{
    cout<<"Please enter your age:";
    int age=get_integer_in_range(18,60);
    return age;
}
string get_name()
{
    string name=get_character_space("Please enter name:");
    return name;
}
int get_salary()
{
    cout<<"Please enter your salary:";
    int salary=get_integer_in_range(2000,50000);
    return salary;
}

bool is_valid_gender(char c)
{
    if(c=='m'||c=='f')
        return true;
    return false;
}

char get_gender()
{
    cout<<"Please enter your gender[m,f]:";
    char characters[]{'m','f'};
    char gen=get_valid_lower_character(characters,2);
    return gen;
}
void add_employee()
{
    cout<<"-----------option 1 add employee-----------------------\n";
    string name=get_name();
    int age=get_age();
    int salary=get_salary();
    char gender=get_gender();

    cout<<"Are you sure you want to add it[y,n]:";
    char characters[]{'y','n'};
    char flag=get_valid_lower_character(characters,2);

    if(flag=='n')
    {
        start_employee_program();
    }

    employee_name[current_employee_sz]=name;
    employee_age[current_employee_sz]=age;
    employee_salary[current_employee_sz]=salary;
    employee_gender[current_employee_sz]=gender;

    cout<<"Employee inserted successfully\n";

    current_employee_sz++;
    start_employee_program();
}

void print_employees()
{
    cout<<"------------Employees----------------------------\n";
    if(current_employee_sz==0)
        cout<<"There isn't employee\n";
    for(int i=0;i<current_employee_sz;i++)
    {
        cout<<(i+1)<<") ";
        cout<<"Name:"<<employee_name[i]<<"\t"
            <<"Age:"<<employee_age[i]<<"\t"
            <<"Salary:"<<employee_salary[i]<<"\t"
            <<"Gender:"<<employee_gender[i]<<"\n";
    }
    start_employee_program();
}
void delete_age_range()
{
    cout<<"--------option 3 delete age range------------------------\n";
    int start_age,end_age;
    cout<<"Enter your start age:";
    start_age=get_integer_in_range(18,60);
    cout<<"Enter your end age:";
    end_age=get_integer_in_range(start_age,60);
    int tmp_sz_employee=0;
    for(int i=0;i<current_employee_sz;i++)
    {
        if(employee_age[i]>=start_age && employee_age[i]<=end_age)
        {
            continue;
        }
        employee_name[tmp_sz_employee]=employee_name[i];
        employee_age[tmp_sz_employee]=employee_age[i];
        employee_salary[tmp_sz_employee]=employee_salary[i];
        employee_gender[tmp_sz_employee]=employee_gender[i];
        tmp_sz_employee++;
    }
    current_employee_sz=tmp_sz_employee;
    cout<<"Deleted successfully\n";
    start_employee_program();
}

void update_salary_by_name()
{
    cout<<"-------option 4 update salary by name------------\n";
    string name=get_character_space("Enter the name:");
    cout<<"Enter the salary:";
    int salary=get_integer_in_range(2000,50000);
    for(int i=0;i<current_employee_sz;i++)
    {
        if(employee_name[i]==name)
        {
            employee_salary[i]=salary;
            break;
        }
    }
    cout<<"Updated successfully\n";
    start_employee_program();
}

void start_employee_program()
{
    int choice=get_menu_choice();
    if(choice==1)
    {
        add_employee();
    }
    else if(choice==2)
    {
        print_employees();
    }
    else if(choice==3)
    {
        delete_age_range();
    }
    else if(choice==4)
    {
        update_salary_by_name();
    }
    else if(choice==5)
    {
        return ;
    }
}



