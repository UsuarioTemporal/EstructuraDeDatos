#include<iostream>
#include<vector>
using namespace std;
void forExtendido(int xtabla,int xtope){
	cout<<"\nDesplegando la tabla "<<xtabla<<endl;
	for(int i=1;i<=xtope;i++){
		cout<<xtabla<<"x"<<i<<" = "<<xtabla*i<<endl;
	}
	cout<<endl;
}
int main(){
	int numeros[]={1,2,5};
	vector<int> vct;
	vct.push_back(4);
	vct.push_back(2);
	vct.push_back(3);
	vct.push_back(5);
	for(int i=0;i<vct.size();i++){
		cout<<vct[i]<<" ";
	}
	vct.push_back(4);
	for(int i=1;i<8;forExtendido(i++,10));

}
