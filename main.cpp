#include <iostream>
#include "OMNI.h"
#include <time.h>
using namespace std;
int main()
{
	OMNI om;
	VectorXd v;
	clock_t s,e;

	v.resize(10);
	v<<4269,5040,4227,4584,5088,4070,3250,3126,4651,4902;
	om.initial("../../Data/h20v9EVI1D1_1.txt",10001,10,285,4);
	cout<<"finish initial"<<endl;
	s = clock();
	om.subsequenceQuery(v,1000000);
	for(int i = 0; i < om.queryResult.size(); ++i)
	{
		cout<<om.queryResult[i]<<endl;
	}
	e=clock();
	cout<<"time"<<e-s<<endl;
	cin.get();
	return 0;
}