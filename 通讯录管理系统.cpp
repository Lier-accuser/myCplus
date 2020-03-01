#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

struct Person {
	string m_Name;
	int m_Age;
	int m_Sex;//1-男，2-女。
	string m_Phone;
	string m_Address;
};
struct Addressbook {
	struct Person personArry[MAX];
	int m_Size;
};

//显示目录
void showMenu() {       
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
//添加联系人
void addPerson(struct Addressbook*abs) {
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		cout << "请输入姓名：" << endl;//输入姓名
		string name;
		cin >> name;
		abs->personArry[abs->m_Size].m_Name = name;
		cout << "请输入年龄：" << endl;//输入年龄
		int age = 0;
		cin >> age;
		abs->personArry[abs->m_Size].m_Age = age;
		cout << "请输入性别：" << endl;//输入性别
		cout << "(1-男,2-女)" << endl;
		int sex;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArry[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "性别输入错误，请重新输入！" << endl;
		}
		cout << "请输入联系电话：" << endl;//输入联系电话
		string phone;
		cin >> phone;
		abs->personArry[abs->m_Size].m_Phone = phone;
		cout << "请输入家庭住址：" << endl;//输入家庭住址
		cout << "(--市--区)" << endl;
		string address;
		cin >> address;
		abs->personArry[abs->m_Size].m_Address = address;
		abs->m_Size++;//联系人个数更新
		cout << "添加成功。" << endl;
	}
	system("pause");
	system("cls");
}
//显示联系人
void showPerson(struct Addressbook*abs) {
	if (abs->m_Size == 0) {
		cout << "通讯录里暂时还没有联系人！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArry[i].m_Name << "\t"
			 	 << "年龄：" << abs->personArry[i].m_Age << "\t"
				 << "性别：" << (abs->personArry[i].m_Sex == 1 ? "男" : "女") << "\t"
				 << "联系电话：" << abs->personArry[i].m_Phone << "\t"
				 << "家庭住址：" << abs->personArry[i].m_Address << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}
//判断联系人是否存在
int isExit(Addressbook*abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArry[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}
//删除联系人
void deletePerson(Addressbook*abs) {
	if (abs->m_Size == 0) {
		cout << "通讯录里暂时还没有联系人！" << endl;
	}
	else {
		cout << "请输入要删除的联系人的姓名：" << endl;
		string name;
		cin >> name;
		int ret = isExit(abs, name);
		if (ret == -1) {
			cout << "查无此人！" << endl;
		}
		else {
			for (int i = ret; i < abs->m_Size; i++) {
				abs->personArry[i].m_Name = abs->personArry[i + 1].m_Name;
			}
			abs->m_Size--;
			cout << "删除成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找联系人
void findPerson(Addressbook*abs) {
	if (abs->m_Size == 0) {
		cout << "通讯录里暂时还没有联系人！" << endl;
	}
	else {
		cout << "请输入要查找的联系人的姓名：" << endl;
		string name;
		cin >> name;
		int ret = isExit(abs, name);
		if (ret == -1) {
			cout << "查无此人！" << endl;
		}
		else {
			cout << "姓名：" << abs->personArry[ret].m_Name << "\t"
				<< "年龄：" << abs->personArry[ret].m_Age << "\t"
				<< "性别：" << (abs->personArry[ret].m_Sex == 1 ? "男" : "女") << "\t"
				<< "联系电话：" << abs->personArry[ret].m_Phone << "\t"
				<< "家庭住址：" << abs->personArry[ret].m_Address << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}
//修改联系人
void modifyPerson(Addressbook*abs) {
	if (abs->m_Size == 0) {
		cout << "通讯录里暂时还没有联系人！" << endl;
	}
	else {
		cout << "请输入要查找的联系人的姓名：" << endl;
		string name;
		cin >> name;
		int ret = isExit(abs, name);
		if (ret == -1) {
			cout << "查无此人！" << endl;
		}
		else {
			cout << "请输入修改后的年龄：" << endl;//输入年龄
			int age = 0;
			cin >> age;
			abs->personArry[ret].m_Age = age;
			cout << "请输入修改后的性别：" << endl;//输入性别
			cout << "(1-男,2-女)" << endl;
			int sex;
			while (true) {
				cin >> sex;
				if (sex == 1 || sex == 2) {
					abs->personArry[ret].m_Sex = sex;
					break;
				}
				cout << "性别输入错误，请重新输入！" << endl;
			}
			cout << "请输入修改后的联系电话：" << endl;//输入联系电话
			string phone;
			cin >> phone;
			abs->personArry[ret].m_Phone = phone;
			cout << "请输入修改后的家庭住址：" << endl;//输入家庭住址
			cout << "(--市--区)" << endl;
			string address;
			cin >> address;
			abs->personArry[ret].m_Address = address;
			cout << "修改成功。" << endl;
		}
	}
	system("pause");
	system("cls");
}
//清空联系人
void cleanPerson(Addressbook*abs) {
	abs->m_Size = 0;
	cout << "清除成功！" << endl;
	system("pause");
	system("cls");
}

int main() {
	Addressbook abs;
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		showMenu();
		cout << "请输入你的选择：";
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
			cout << "欢迎下次使用。" << endl;
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