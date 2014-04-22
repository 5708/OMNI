#ifndef _DATA_H_
#define _DATA_H_
#include <iostream>
#include "Eigen/Eigen/Dense"
#include <fstream>
#include <vector>
using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;
class Data{
public:
	MatrixXd m;
	int tsNum, tsLen,fociNum,totalLen;
	MatrixXd fociTS;
	vector<MatrixXd> fd;
	vector<int> fociID;
	
	void read(string filename, int tNum, int tLen, int ttLen, int fNum);
	void write(vector<int>* result);
	
};

#endif