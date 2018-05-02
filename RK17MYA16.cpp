#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
class ic
{
int ino,i;
char name[40];
float price,qty;
public:
void write();
void create()
{
cout<<"\n\n Enter the name of Icecream:- ";
cin>>name;
cout<<"\nEnter the Price(In Rs.):- ";
cin>>price;
}
void show()
{
cout<<"\nThe Item no.:- "<<i;
cout<<"\nThe name of the Icecream:- ";
puts(name);
cout<<"\nThe Price(In Rs.):- "<<price;
}
int retino()
{
return i;}
char retname()
{cout<<name;}
float retprice()
{return price;}
}; 
fstream f;
ic I;
void ic::write()
{
f.open("Shop.txt",ios::out|ios::app);
i++;
I.create();
f.write((char*)&I,sizeof(I));
f.close();
cout<<"\n\nThe Record Has Been Created Successfully";
getch();
}
void display()
{
cout<<"\n\n\n\t\tDisplay all Record:-\n\n";
f.open("Shop.txt",ios::in);
while(f.read((char*)&I,sizeof(I)))
{
I.show();
getch();
}
f.close();
getch();
}
void display_sp(int n)
{
int flag=0;
f.open("Shop.txt",ios::in);
while(f.read((char*)&I,sizeof(I)))
if(I.retino()==n)
{
I.show();
flag=1;
}
f.close();
if(flag==0)
cout<<"\n\nRecord not exist";
getch();
}
void modify()
{
int no,found=0;
cout<<"\n\n\tTo Modify";
cout<<"\n\n\tPlease enter the Appliance No.";
cin>>no;
f.open("Shop.txt",ios::in|ios::out);
while(f.read((char*)&I,sizeof(I)) && found==0)
{
if(I.retino()==no)
{
I.show();
cout<<"\nPlease enter the New Details:- "<<endl;
I.create();
int pos=1*sizeof(I);
f.seekp(pos,ios::cur);
f.write((char*)&I,sizeof(I));
cout<<"\n\n\t Record Updated:- ";
found=1;
}
}
f.close();
if(found==0)
cout<<"\n\n Record not found  ";
getch();
}
void delet()
{
int no;
cout<<"\n\n\n\tDelete Record";
cout<<"\n\nPlease enter the Item no. you want to Delete";
cin>>no;
f.open("Shop.txt",ios::in|ios::out);
fstream f2;
f2.open("Temp.txt",ios::out);
f.seekg(0,ios::beg);
while(f.read((char*)&I,sizeof(I)))
{
if(I.retino()!=no)
{
f2.write((char*)&I,sizeof(I));
}
}
f2.close();
f.close();
remove("Shop.txt");
rename("Temp.txt","Shop.txt");
cout<<"\n\n\tRecord Deleted ..";
getch();
}
void menu()
{

f.open("Shop.txt",ios::in);
if(!f)
{
cout<<"\n\t\t\t\t\tERROR! File could not be Opened \n\n\n Go to Admin Menu to Create File";
cout<<"\n\n\n Program is closing ............................................";
getch();
}
cout<<"\n\n\t\t MENU\n\n";
cout<<"====================================================\n";
cout<<"S.NO.\t\tNAME\t\tPRICE(In Rs.)\n";
cout<<"====================================================\n";
while(f.read((char*)&I,sizeof(I)))
{
 	 
cout<<I.retino()<<"\t\t";
cout<<I.retname()<<"\t\t"<<I.retprice()<<endl;
}
f.close();
}
void place_order()
{
int order_arr[30],quan[30],c=0;
float amt,total=0;
char ch='Y';
menu();
cout<<"\n============================";
cout<<"\n PLACE YOUR ORDER";
cout<<"\n============================\n";
do{
cout<<"\n\nEnter the Item no.:-";
cin>>order_arr[c];
cout<<"\nQuantity in number:-";
cin>>quan[c];
c++;
cout<<"\nDo you want to Order More ? (y/n)";
cin>>ch;
}while(ch=='y' ||ch=='Y');
cout<<"\n\nThank You For Placing The Order \nHAVE A NICE DAY ";
getch();
cout<<"\n\n********************************INVOICE************************\n";
cout<<"\nName\t\tQuantity \tPrice(In Rs.) \tAmount \n";
for(int x=0;x<=c;x++)
{
f.open("Shop.txt",ios::in);
f.read((char*)&I,sizeof(I));
while(!f.eof())
{
if(I.retino()==order_arr[x])
{
amt=I.retprice()*quan[x];

cout<<I.retname();
cout<<"\t"<<quan[x];
cout<<"\t\t"<<I.retprice();
cout<<"\t\t"<<amt<<"\t\t";
cout<<"\n";
total=total+amt;
}
f.read((char*)&I,sizeof(I));
}
f.close();
}
 cout<<"\n\n\t\t\t\t\tTOTAL AMOUNT THAT YOU HAVE TO PAY(In Rs.) :="<<total;
getch();
}
void admin_menu()
{
char ch2;

cout<<"\n\n\n\tADMIN MENU"<<endl;
 
cout<<"\n\n\t1.CREATE RECORD"<<endl;

cout<<"\n\n\t2.DISPLAY ALL RECORDS"<<endl;

cout<<"\n\n\t3.MODIFY RECORD"<<endl;
cout<<"\n\n\t4.DELETE RECORD"<<endl;

cout<<"\n\n\t5.VIEW MENU"<<endl;

cout<<"\n\n\t6.BACK TO MAIN MENU"<<endl;

cout<<"\n\n\tPlease Enter Your Choice "<<endl;
ch2=getche();
switch(ch2)
{
case '1':
I.write();
break;
case '2': display();break;

case '3': modify();break;
case '4': delet();break;
case '5': menu();
getch();
case '6': break;
default:cout<<"\a";admin_menu();
}
}
int main()
{
char ch;
do
{
	cout<<"                                                  ";
                                                                                                 
    cout<<"                    *                                                      *          ";       
    cout<<"                   **                                                     **                  ";
    cout<<"                   **                                                     **                  ";
   cout<<"                   **                                                     **                  ";
         cout<<"     ****    **                       ****                          **                  ";
   cout<<" ****      * **** * **  ***       ****      * ***  *    ****       ****    **  ***      ***    ";
  cout<<" * ***  *  **  ****  ** * ***     * ***  *  *   ****    * ***  *   * ***  * ** * ***    * ***   ";
 cout<<" *   ****  ****       ***   *     *   ****  **    **    *   ****   *   ****  ***   ***  *   ***  ";
cout<<" **    **     ***      **   *     **    **   **    **   **    **   **         **     ** **    *** ";
cout<<" **    **       ***    **  *      **    **   **    **   **    **   **         **     ** ********  ";
cout<<" **    **         ***  ** **      **    **   **    **   **    **   **         **     ** *******   ";
cout<<" **    **    ****  **  ******     **    **   **    **   **    **   **         **     ** **        ";
cout<<" **    **   * **** *   **  ***    **    **   *******    **    **   ***     *  **     ** ****    * ";
cout<<"  ***** **     ****    **   *** *  ***** **  ******      ***** **   *******   **     **  *******  ";
  cout<<" ***   **             **   ***    ***   ** **           ***   **   *****     **    **   *****   ";
    cout<<"                                         **                                      *            ";
            cout<<"                                 **                                     *             ";
                    cout<<"                          **                                   *              ";
                            cout<<"                                                      *               ";
cout<<"\n\t*****************************LaLA ICE-CREAM *****************************************************";
cout<<"\n\t*********************************************************************************";
cout<<"\n\n\*****************************t1.User mode**********************************************************";
cout<<"\n\n\*****************************t2.ADMIN MODE*********************************************************";
cout<<"\n\n\*****************************t3.EXIT****************************************************************";
cout<<"\n\n\t select 1 for user mode ,2 for admin mode and 3 for exit ";
ch=getche();
switch(ch)
{
case '1':
place_order();
getch();
break;
case '2': admin_menu();
break;
case '3':
	cout<<"\n\n\t\t\t\t\t*Thank You for Visiting LOOPS ********************* ";
break;
default :cout<<"\tPlease enter Right Key";
}
}while(ch!='3');
}


