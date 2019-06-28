#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
class hero
{
    public:
    int hp,dmg;
    long int gold=0;
    int ex,lvl;
    double crit_chanse,crit;

void show_information()
{
cout<<lvl<<" "<<dmg;
}
};
class Monster
{
public:
    int hp,dmg,ex,gold,id;
    string name,dis;

void show_information()
{
cout<<"Имя монстра: "<<name<<endl;
cout<<"Описание: "<<endl;
cout<<dis<<endl;
cout<<"Здоровье: "<<hp<<endl;
cout<<"Урон: "<<dmg<<endl;
cout<<"Опыт за монстра: "<<ex<<endl;
cout<<"Золота за монстра: "<<gold<<endl;
}
};



void death(hero player,Monster m)
{
player.show_information();
cout<<"Вас убил: "<<m.name<<endl;
}


int damage(int dm,double crit,double crit_chanse )
{
srand ( time(NULL) );
int p=rand()%2;
int j=rand()%11;
if (p==0){dm+=j;}
else{dm-=j;}
int l=rand()%100+1;
if (crit_chanse<=l){dm=round(dm*crit);}
return dm;
}

void victory(int ex,int hp,long int gold)
{
cout<<"Вы одержали победу!"<<endl;
cout<<"Текущее здоровье: "<<hp<<endl;
cout<<"Текущее золото: "<<gold<<endl;
cout<<"Текущий уровень: "<<ex<<endl;
}


int battle(hero p,Monster m)
{
while (p.hp>0 && m.hp>0)
{
    cout<<p.hp<<endl;
cout<<"1"<<endl;
int choise;
cin>>choise;
switch(choise)
{
case 1:
    {
        m.show_information();
        break;
    }
case 2:
    {
      m.hp-=damage(p.dmg,p.crit,p.crit_chanse);
    break;
    }
case 3:
    {
        p.hp=0;
        break;
    }
}
}
if(p.hp<=0){return 0;}
else{return p.hp;}
}




int main()
{

hero p;
p.hp=150;
p.dmg=10;
p.crit=1,5;
p.crit_chanse=1;
p.lvl=0;
p.ex=0;

srand ( time(NULL) );
int n=rand()%4;
setlocale(LC_ALL, "Russian");
Monster cake;
cake.hp=10;cake.dmg=5;cake.ex=7;cake.gold=25;cake.name="Живой Кекс"; cake.dis="Что это вообще такое?! Это живое тесто! И, кажется, оно пытается убить тебя!"; cake.id=1;
Monster skeleton;
skeleton.hp=20;skeleton.name="Мистер Дудец";skeleton.dmg=15;skeleton.ex=100;skeleton.gold=500;skeleton.dis="Черт возьми! Даже мемы против меня :'(";skeleton.id=2;
Monster boss;
boss.hp=10;boss.name="Твой Босс";boss.dmg=8;boss.ex=10;boss.gold=288;boss.dis="Даже твой босс решил проучить тебя)";boss.id=3;
Monster ashot;
ashot.hp=5;ashot.dmg=30;ashot.ex=1;ashot.gold=0;ashot.name="Мусульманин";ashot.dis="Его бомба уже летит в твое очко)";ashot.id=4;
switch (n)
{
case 0:
{
int dd=battle(p,cake);
if (dd==0){death(p,cake);}
else {p.hp=dd;p.ex+=cake.ex;p.gold+=cake.gold; victory(p.ex,p.hp,p.gold);}
break;
}
case 1:
{
int dd=battle(p,skeleton);
if (dd==0){death(p,skeleton);}
else {p.hp=dd;p.ex+=skeleton.ex;p.gold+=skeleton.gold;victory(p.ex,p.hp,p.gold);}
break;
}
case 2:
{
int dd=battle(p,boss);
if(dd==0){death(p,boss);}
else {p.hp=dd; p.ex+=boss.ex; p.gold+=boss.gold;victory(p.ex,p.hp,p.gold);}
break;
}
case 3:
{
int dd=battle(p,ashot);
if (dd==0){death(p,ashot);}
else{p.hp=dd;p.ex+=ashot.ex;p.gold+=ashot.gold;victory(p.ex,p.hp,p.gold);}
break;
}
}




return 0;
}

