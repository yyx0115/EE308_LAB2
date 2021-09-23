#include 
#include 
using namespace std;

int main() {
	int i,counter = 0;
	ifstream readfile;
	char filename[60];
	char text[60],ch;
	cout << "The file name:";
	cin >> filename;
	readfile.open(filename);
	if(readfile.is_open == false) {
		cout << "没有找到文件:" << filename << endl;
		return 1;
	}
	while(cin.get() != '\n')
		;
	cout << "待查找的关键字:";
	cin.getline(text,60);
	i = 0;
	while(readfile >> ch) {
		if(ch == text[i]) {
			for(++i; text[i] && (readfile >> ch); ++i)
				if(text[i] != ch) break;
			if(text[i] == '\0') ++counter;
			if(ch == text[0]) i = 1;
			else i = 0;
		}
	}
	cout << "\n the file name: " << filename << endl;
	cout << "关 键 字: " << text << endl;
	cout << "出现次数: " << counter << endl;
	return 0;
}
