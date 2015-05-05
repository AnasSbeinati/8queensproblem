#include<iostream>
#include<vector>

 using namespace std;

 void getSolution(int j);
 void printSolution();
 bool valid(int i,int j);
 int**board,n;
 vector<pair<int,int> > sols;

 int main() {
	 cin>>n;
	 board=new int*[n];
	 for(int i=0;i<n;i++)
	 {
		 board[i]=new int [n];
		  for(int j=0;j<n;j++)
	      {
			 board[i][j]=0;
		  }
	 }
	 getSolution(0);
     printSolution();
	 system("pause");
	 return 0;
 }

 void getSolution(int j)
 {
	 bool b=0;
	 if(j<n)
	 {
	 for(int i=0;i<n;i++)
	 {
		 if(valid(i,j))
		 {
			 b=1;
			 board[i][j]=1;
			 pair<int,int> temp;
			 temp.first=i;
			 temp.second=j;
			 sols.push_back(temp);
             getSolution(j+1);
			 if(sols.size()==n)
				 return;
		 }
	 }
	 if(!b||sols.size()!=n) 
	 {
		 board[sols[sols.size()-1].first][sols[sols.size()-1].second]=0;
		 sols.pop_back();
	 }   
	 }
 }
 bool valid(int k,int j)
 {
	 for(int i=0;i<sols.size();i++)
	 {
		 if(k==sols[i].first)
			 return 0;
		 if(j==sols[i].second)
			 return 0;
		 if(k+j==sols[i].first+sols[i].second)
			 return 0;
		 if(k-j==sols[i].first-sols[i].second)
			 return 0;
	 }
	 return 1;
 }
 void printSolution()
 {
	 for(int i=0;i<n;i++)
	 {
		  for(int j=0;j<n;j++)
	      {
			  cout<<board[i][j]<<" ";
		  }
		  cout<<endl;
	 }
 }