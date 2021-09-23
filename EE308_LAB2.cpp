#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
string words[32]={"auto","case","char","const","do",
		   "double","enum","extern","float","goto",
		   "int","long","register","short","signed","static",
		   "struct","typedef","union","unsigned","void","volatile","while"
		   ,"break","continue","for","if","sizeof","switch","return","default","else"};

void getNum(char *s,int grade){
	queue<int> q;
	ifstream infile;
	infile.open(s,ios::in);
	if (!infile){
		printf("file opened failure£¡£¡£¡");
		return ; 
	}
	string temp;
	bool judgeswitch=false;
	int cntcase;
	while (!infile.eof()){
		infile>>temp;
		//cout<<temp<<endl;
		for (int i=0;i<32;i++){
			if (i<22){
				if (temp==words[i]){
					mp[temp]++;
					if (temp=="case"&&judgeswitch)   cntcase++;
				}   
			}
			else{
				if (temp.substr(0,words[i].size())==words[i]){
					if (temp.size()==words[i].size()){
						mp[words[i]]++;
						if (words[i]=="switch"){
							judgeswitch=true;
							cntcase=0;
						} 
						else if (words[i]=="default"){
							judgeswitch=false;
							q.push(cntcase);
						}  
					}   
					else if (temp[words[i].size()]=='('||temp[words[i].size()]==';'||temp[words[i].size()]==':'
					||temp[words[i].size()]=='{'){
						mp[words[i]]++;
						if (words[i]=="switch"){
							judgeswitch=true;
							cntcase=0;
						}   
						else if (words[i]=="default"){
							judgeswitch=false;
							q.push(cntcase);
						}  
					}
				}
			}
		}
	}
	int total=0;
	for (auto v:mp){
		//output all the keywords
		//cout<<v.first<<" : "<<v.second<<endl;
		//calculate the sum
		total+=v.second;
	}
	cout<<"total :"<<total<<endl;
	if (grade==2){
		cout<<"switch : "<<q.size()<<endl;
		cout<<"case : ";
		while (!q.empty()){
			cout<<q.front()<<" ";
			q.pop();
		}
	}
}
int main(){
	char url[100];
	int grade;
	cout<<"Enter the file path and judgment level£º"<<endl;  // in.txt level 2
	cin>>url>>grade;
	getNum(url,grade);
	return 0;
}

