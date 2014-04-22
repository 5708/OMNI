#ifndef _BPT_H_
#define _BPT_H_
#include <iostream>
#include <vector>
#include <Eigen/Dense>
using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

class BPT
{
public:
	vector<int> rangeResult;
	
	void rangeQuery(double low, double up, MatrixXd* tsCount);
}

#endif