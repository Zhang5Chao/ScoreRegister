// ScoreRegister.cpp : 定义控制台应用程序的入口点。
//
#include "iostream"
using namespace std;


struct Student{
	char name[20];
	char studentNumber[20];
	int score;
}students[100];


int NameCount = 0;


void list();
void addStudent();
void subtractStudent();
int addScore();
void input(struct Student &student);
int find(char *studentNumber);


int main()
{
	int action;
	
	do{
		cout<<"-----------菜单-----------"<<endl;
		cout<<"1)学生名单"<<endl;
		cout<<"2)增添学生"<<endl;
		cout<<"3)删除学生"<<endl;
		cout<<"4)录成绩"<<endl;
		cout<<"5)退出程序"<<endl;


		cin>>action;
		switch(action){
		case 1:
			list();
			break;
		case 2:
			addStudent();
			break;
		case 3:
			subtractStudent();
			break;
		case 4:
			addScore();
			break;
		case 5:
			return 0;
		default:
			cout<<"您输入了错误的菜单项，请重新选择！";
		}
	}while(1);
}


void list(){
	cout<<"-------名单-------"<<endl;
	cout<<"名字\t"<<"学号\t"<<"成绩"<<endl;
	for(int i=0;i<NameCount;i++){
		cout<<students[i].name<<"\t"<<students[i].studentNumber<<"\t"<<students[i].score<<endl;
	}
	cout<<"-------名单-------"<<endl;
}
void addStudent(){
	struct Student student;
	input(student);
    int i = find(student.name);
	if(i == NameCount){
		strcpy_s(students[i].name ,student.name);
		strcpy_s(students[i].studentNumber,student.studentNumber);
		
		NameCount++;
	}else{
		cout<<"此学生存在";
	}
}
int addScore(){
    struct Student student;
	input(student);
	int t;
	int i = find(student.studentNumber);
	for(t=i;t<NameCount;t++){
		
		cout<<"姓名"<<students[t].name<<" "<<"学号"<<students[t].studentNumber<<"分数:";
		int fenshu;
		cin>>fenshu;
		students[t].score=fenshu;
		cout<<"是否继续录入成绩(1/2)"<<endl;
		
		int judge;
		cin>>judge;
			if(judge==1)
		{
			continue;

		}
		else if(judge==2)
		{
			break;
		}
       }
	
	return 1;

}



void subtractStudent(){
	struct Student student;
	input(student);


	int i = find(student.studentNumber);
	if(i == NameCount){
		cout<<"名字错误！"<<endl;
	}
	else{
		int t=i;
		for(t=i;t<100;t++)
		{
		  students[t]= students[t+1];
		}	
	}
	NameCount--;
}


void input(struct Student &student){
	cout<<"名字：";
	cin>>student.name;


	cout<<"学号：";
	cin>>student.studentNumber;

	
}


int find(char* stuentNumber){
	int i;
	for(i=0;i<NameCount;i++){
		if(strcmp(students[i].studentNumber,stuentNumber) == 0){
			break;
		}
	}
	return i;
}



