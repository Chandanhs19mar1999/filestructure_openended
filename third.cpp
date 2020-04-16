#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<string>
#include<cstring>
#include<fstream>
#define fixedlength 150
using namespace std;
int count1;
char idobk[3];
class bookreseller
{
   public:
          char bookname[30],authorname[30],op[5],sp[5],vendorname[30],address[30],buffer[500],buffer2[50],uid[3];
          
          void unpackingtogetid()
          {
            strcpy(uid,strtok(buffer2,"|"));
          }
          
          void del(char id[])
          {
            fstream f3,f4,f5,f6,f7,f8;
            f3.open("index.txt",ios::in);
            f5.open("temp1.txt",ios::out|ios::trunc);
            f6.open("temp2.txt",ios::out|ios::trunc);
            while(!f3.eof())
            {
                 f3>>buffer2;
                 if(f3.fail())
                 {
                   break;
                 }
                 unpackingtogetid();
                 if(strcmp(uid,id)==0)
                 {
                    cout<<"Thanks for buying the book "<<endl;
                    char buf[50];
                    f3>>buf;
                    while(!f3.eof())
                    {
                      f6<<buf<<endl;
                      f3>>buf;
                    }
                    f3.close();
                    f6.close();
                    f4.open("index.txt",ios::out|ios::trunc);
                    f7.open("temp1.txt",ios::in);
                    f8.open("temp2.txt",ios::in);
                    f7>>buffer2;
                    while(!f7.eof())
                    {
                            f4<<buffer2<<endl;
                            f7>>buffer2;
                    }
                    f8>>buffer2;
                    while(!f8.eof())
                    {
                        f4<<buffer2<<endl;
                        f8>>buffer2;
                    }
                    f4.close();
                    f7.close();
                    f8.close();
                    return;
                 }
                 f5<<buffer<<endl;
                 f3>>buffer;
            }
            cout<<"Invalid Book ID "<<endl;
            return;
          }
          void add()
          {
              fstream f1,f2;
              f1.open("index.txt",ios::out|ios::app);
              f2.open("record.txt",ios::out|ios::app);
              cout<<"enter the bookname "<<endl;
              cin>>bookname;
              cout<<"enter the authorname "<<endl;
              cin>>authorname;
              cout<<"enter the original price of the book "<<endl;
              cin>>op;
              cout<<"enter the selling price of the book "<<endl;
              cin>>sp;
              cout<<"enter the vendorname (your name) "<<endl;
              cin>>vendorname;
              cout<<"enter the address of vendor "<<endl;
              cin>>address;
             strcpy(buffer,bookname);
             strcat(buffer,"|");
             strcat(buffer,authorname);
             strcat(buffer,"|");
             strcat(buffer,op);
             strcat(buffer,"|");
             strcat(buffer,sp);
             strcat(buffer,"|");
             strcat(buffer,vendorname);
             strcat(buffer,"|");
             strcat(buffer,address);
             strcat(buffer,"#");
             f2<<count1<<"|"<<buffer;
             f2<<endl;
             f2.close();
             strcpy(buffer2,bookname);
             f1<<count1<<"|"<<buffer2<<"#";
             f1<<endl;
             f1.close();
             count1++;
          }
          
          void unpack()
          {
              strcpy(uid,strtok(buffer,"|"));
              strcpy(bookname,strtok(NULL,"|"));
              strcpy(authorname,strtok(NULL,"|"));
              strcpy(op,strtok(NULL,"|"));
              strcpy(sp,strtok(NULL,"|"));
              strcpy(vendorname,strtok(NULL,"|"));
              strcpy(address,strtok(NULL,"#"));
          }
          
          void unpackingindexfordisplay()
          {
             strcpy(uid,strtok(buffer2,"|"));
             strcpy(idobk,uid);
          }
          
          void display()
          {
             cout<<"UID"<<"            BOOKNAME"<<"          AUTHORNAME"<<"    ORIGINALPRICE"<<"     SELLINGPRICE"<<"          VENDORNAME"<<"             ADDRESS"<<endl;
             cout<<"_____________________________________________________________________________________________________________________________________________ "<<endl;
             ifstream fin,fre;
             fin.open("index.txt");
             while(!fin.eof())
             {
                fin>>buffer2;
                if(fin.fail())
                {
                  break;
                } 
                unpackingindexfordisplay();
                fre.open("record.txt");
                while(!fre.eof())
                {
                  fre>>buffer;
                  if(fre.fail())
                  {
                    break;
                  }
                  unpack();
                  if(strcmp(idobk,uid)==0)
                  {
                      cout.width(3);
                      cout<<uid;
                      cout.width(20);
                      cout<<bookname;
                      cout.width(20);
                      cout<<authorname;
                      cout.width(16);
                      cout<<op;
                      cout.width(16);
                      cout<<sp;
                      cout.width(20);
                      cout<<vendorname;
                      cout.width(20);
                      cout<<address;
                      cout<<endl;
                  }
                }
                fre.close();
             }
             fin.close();
             fre.close();
          }
          
          void unpackrecord()
          {
              strcpy(uid,strtok(buffer2,"|"));
              strcpy(bookname,strtok(NULL,"#"));
          }
          
          void search()
          {
             char bid[3];
             char bn[30];
             cout<<"enter the bookname to search "<<endl;
             cin>>bn;
             int i,flag=0;
             fstream f1,f2;
             f1.open("index.txt",ios::in);
             while(!f1.eof())
             {
                f1>>buffer2;     
                if(f1.fail())
                {
                  break;
                }
                unpackrecord();
                if(strcmp(bookname,bn)==0)
                {
                  flag=1;
                  break;
                }
             }
             f1.close();
             if(flag==1)
             {
                f2.open("records.txt",ios::in);
                cout<<"The book which you are finding is found "<<endl;
                 while(!f2.eof())
                 {
                          cout<<"I am here "<<endl;
                          f2>>buffer;     
                          cout<<"before fail"<<endl;
                          if(f2.fail())
                          {
                              break;
                          }
                          cout<<"before unpackmethod "<<endl;
                          unpack();
                          cout<<"after unpackmethod "<<endl;
                          if(strcmp(bookname,bn)==0)
                          {
                              cout.width(3);
                              cout<<uid;
                              cout.width(20);
                              cout<<bookname;
                              cout.width(20);
                              cout<<authorname;
                              cout.width(16);
                              cout<<op;
                              cout.width(16);
                              cout<<sp;
                              cout.width(20);
                              cout<<vendorname;
                              cout.width(20);
                              cout<<address;
                              cout<<endl;
                          } 
                 }
                f2.close();
                cout<<"Enter the uid of the book to buy enter -1 to not buy"<<endl;
                cin>>bid;
                if(strcmp(bid,"-1")!=0)
                {
                  del(bid);
                }
                else
                {
                  cout<<"Thanks"<<endl;
                  return;
                }
                
             }
             else
             {
                cout<<"we are very sorry the book that you are searching is not available"<<endl;
                return;
             } 
          }
};


void getcount1()
{
 ifstream fin;
 fin.open("record.txt");
 string str;
 while(getline(fin,str))
 {
  count1++;
 }
 fin.close();
}

int main()
{
   cout<<"Welcome to Bookreseller Application"<<endl;
   count1=0;
   getcount1();
   bookreseller bs;
   int choice;
   while(1)
   {
      cout<<"1 sell book \n"<<"2 Buy book \n"<<"3 exit \n "<<"enter the choice ";
      cin>>choice;
      switch(choice)
      {
          case 1:{
                     bs.add();
                     cout<<"Thanks for selling the book \n"<<endl;
                 }
                 break;
          case 2:{
            
                   bs.display();
                   bs.search();
                 }
                 break;
          case 3:{
                   exit(0);
                 }
          default : cout<<"Invalid Choice \n";
      }
   }
}
