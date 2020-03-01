#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

struct Person {
	string m_Name;
	int m_Age;
	int m_Sex;//1-�У�2-Ů��
	string m_Phone;
	string m_Address;
};
struct Addressbook {
	struct Person personArry[MAX];
	int m_Size;
};

//��ʾĿ¼
void showMenu() {       
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}
//�����ϵ��
void addPerson(struct Addressbook*abs) {
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else {
		cout << "������������" << endl;//��������
		string name;
		cin >> name;
		abs->personArry[abs->m_Size].m_Name = name;
		cout << "���������䣺" << endl;//��������
		int age = 0;
		cin >> age;
		abs->personArry[abs->m_Size].m_Age = age;
		cout << "�������Ա�" << endl;//�����Ա�
		cout << "(1-��,2-Ů)" << endl;
		int sex;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArry[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�Ա�����������������룡" << endl;
		}
		cout << "��������ϵ�绰��" << endl;//������ϵ�绰
		string phone;
		cin >> phone;
		abs->personArry[abs->m_Size].m_Phone = phone;
		cout << "�������ͥסַ��" << endl;//�����ͥסַ
		cout << "(--��--��)" << endl;
		string address;
		cin >> address;
		abs->personArry[abs->m_Size].m_Address = address;
		abs->m_Size++;//��ϵ�˸�������
		cout << "��ӳɹ���" << endl;
	}
	system("pause");
	system("cls");
}
//��ʾ��ϵ��
void showPerson(struct Addressbook*abs) {
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼����ʱ��û����ϵ�ˣ�" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "������" << abs->personArry[i].m_Name << "\t"
			 	 << "���䣺" << abs->personArry[i].m_Age << "\t"
				 << "�Ա�" << (abs->personArry[i].m_Sex == 1 ? "��" : "Ů") << "\t"
				 << "��ϵ�绰��" << abs->personArry[i].m_Phone << "\t"
				 << "��ͥסַ��" << abs->personArry[i].m_Address << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}
//�ж���ϵ���Ƿ����
int isExit(Addressbook*abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArry[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}
//ɾ����ϵ��
void deletePerson(Addressbook*abs) {
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼����ʱ��û����ϵ�ˣ�" << endl;
	}
	else {
		cout << "������Ҫɾ������ϵ�˵�������" << endl;
		string name;
		cin >> name;
		int ret = isExit(abs, name);
		if (ret == -1) {
			cout << "���޴��ˣ�" << endl;
		}
		else {
			for (int i = ret; i < abs->m_Size; i++) {
				abs->personArry[i].m_Name = abs->personArry[i + 1].m_Name;
			}
			abs->m_Size--;
			cout << "ɾ���ɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findPerson(Addressbook*abs) {
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼����ʱ��û����ϵ�ˣ�" << endl;
	}
	else {
		cout << "������Ҫ���ҵ���ϵ�˵�������" << endl;
		string name;
		cin >> name;
		int ret = isExit(abs, name);
		if (ret == -1) {
			cout << "���޴��ˣ�" << endl;
		}
		else {
			cout << "������" << abs->personArry[ret].m_Name << "\t"
				<< "���䣺" << abs->personArry[ret].m_Age << "\t"
				<< "�Ա�" << (abs->personArry[ret].m_Sex == 1 ? "��" : "Ů") << "\t"
				<< "��ϵ�绰��" << abs->personArry[ret].m_Phone << "\t"
				<< "��ͥסַ��" << abs->personArry[ret].m_Address << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyPerson(Addressbook*abs) {
	if (abs->m_Size == 0) {
		cout << "ͨѶ¼����ʱ��û����ϵ�ˣ�" << endl;
	}
	else {
		cout << "������Ҫ���ҵ���ϵ�˵�������" << endl;
		string name;
		cin >> name;
		int ret = isExit(abs, name);
		if (ret == -1) {
			cout << "���޴��ˣ�" << endl;
		}
		else {
			cout << "�������޸ĺ�����䣺" << endl;//��������
			int age = 0;
			cin >> age;
			abs->personArry[ret].m_Age = age;
			cout << "�������޸ĺ���Ա�" << endl;//�����Ա�
			cout << "(1-��,2-Ů)" << endl;
			int sex;
			while (true) {
				cin >> sex;
				if (sex == 1 || sex == 2) {
					abs->personArry[ret].m_Sex = sex;
					break;
				}
				cout << "�Ա�����������������룡" << endl;
			}
			cout << "�������޸ĺ����ϵ�绰��" << endl;//������ϵ�绰
			string phone;
			cin >> phone;
			abs->personArry[ret].m_Phone = phone;
			cout << "�������޸ĺ�ļ�ͥסַ��" << endl;//�����ͥסַ
			cout << "(--��--��)" << endl;
			string address;
			cin >> address;
			abs->personArry[ret].m_Address = address;
			cout << "�޸ĳɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void cleanPerson(Addressbook*abs) {
	abs->m_Size = 0;
	cout << "����ɹ���" << endl;
	system("pause");
	system("cls");
}

int main() {
	Addressbook abs;
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		showMenu();
		cout << "���������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�á�" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}