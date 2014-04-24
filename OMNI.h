#ifndef _OMNI_H_
#define _OMNI_H_
#include <iostream>
#include <vector>
#include "BPlus_tree.h"
#include "Data.h"


using namespace std;
using Eigen::VectorXd;
class OMNI
{
public:
	OMNI();
	~OMNI();
	Data data;
	vector<CBPlusTree> forest;
	VectorXd qsdf;
	MatrixXd tsCount;
	vector<int> queryResult;
	
	void initial(string filename, int tsNum, int ttLen);
	void subsequenceQuery(VectorXd qs, double epsilon);
    void reinitial(int tLen, int fNum, int tstNum);


private:

};




#endif
