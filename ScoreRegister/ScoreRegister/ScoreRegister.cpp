// ScoreRegister.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout<<"-----------�˵�-----------"<<endl;
		cout<<"1)ѧ������"<<endl;
		cout<<"2)����ѧ��"<<endl;
		cout<<"3)ɾ��ѧ��"<<endl;
		cout<<"4)¼�ɼ�"<<endl;
		cout<<"5)�˳�����"<<endl;


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
			cout<<"�������˴���Ĳ˵��������ѡ��";
		}
	}while(1);
}


void list(){
	cout<<"-------����-------"<<endl;
	cout<<"����\t"<<"ѧ��\t"<<"�ɼ�"<<endl;
	for(int i=0;i<NameCount;i++){
		cout<<students[i].name<<"\t"<<students[i].studentNumber<<"\t"<<students[i].score<<endl;
	}
	cout<<"-------����-------"<<endl;
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
		cout<<"��ѧ������";
	}
}
int addScore(){
    struct Student student;
	input(student);
	int t;
	int i = find(student.studentNumber);
	for(t=i;t<NameCount;t++){
		
		cout<<"����"<<students[t].name<<" "<<"ѧ��"<<students[t].studentNumber<<"����:";
		int fenshu;
		cin>>fenshu;
		students[t].score=fenshu;
		cout<<"�Ƿ����¼��ɼ�(1/2)"<<endl;
		
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
		cout<<"���ִ���"<<endl;
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
	cout<<"���֣�";
	cin>>student.name;


	cout<<"ѧ�ţ�";
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



