#include <iostream>
#include "OMNI.h"
#include <time.h>
using namespace std;


int main()
{
	OMNI om;
	VectorXd v, tsLen;
	clock_t s,e;
    int testNum, fociNum;

    testNum = 50000;
    fociNum = 4;
    tsLen.resize(3);
    tsLen<<11,23,46;
	om.initial("./Data/data_unfiltered_h20v09_EVI_1000m_16day.txt",1440000,285);
    for(int a = 0; a < tsLen.size(); ++a)
    {
        cout<<"For tsLen = "<<tsLen(a)<<endl;
        om.reinitial(tsLen(a), fociNum, testNum);
        s = clock();
        for(int b = 0; b < testNum; ++b)
        {
            om.subsequenceQuery(om.data.testTS.row(b),1000000);
            //cout<<"There are "<<om.queryResult.size()<<" results"<<endl;
        }
        e=clock();
        cout<<"time"<<e-s<<"\n\n"<<endl;
        om.data.times.push_back(e-s);
        om.data.writeTestTS(a);
    }
    om.data.write(&(om.queryResult));
	return 0;
}

/*
int main(){
	CBPlusTree B;
    MatrixXd matrix = MatrixXd::Random(10,10);
// 	MatrixXd* matrix = new MatrixXd(10,10);
// 	(*matrix)<< 11,44,55,
// 				33,22,66,
// 				99,88,77;
// 	Data d;
// 	d.read("../Data/h20v9EVI1D1_1.txt",10000,285);
	B.BPTbuild(&matrix);
	B.print();
	B.printData();
// 	vector<int> r = B.rangeQuery(23.0,87.0);
// 	for(int i = 0 ; i < r.size(); ++i)
// 		cout<<r[i]<<"--";
	cin.get();
}*/

