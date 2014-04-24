#include "OMNI.h"
using Eigen::VectorXd;
OMNI::OMNI()
{
}

OMNI::~OMNI()
{
}
void OMNI::initial(string filename, int tsNum, int ttLen)
{
    cout<<"start initial"<<endl;
	data.read(filename, tsNum, ttLen);
	cout<<"finish initial"<<endl;
}

void OMNI::subsequenceQuery(VectorXd qs, double epsilon)
{
	double low, up;
	MatrixXd qsMatrix;

	qsMatrix.resize(1,qs.size());
	qsMatrix.row(0) = qs;
	qsdf.resize(data.fociNum);
	for(int i = 0; i < data.fociNum; ++i)
	{
		qsdf = data.fociTS.rowwise().operator-(qsMatrix.row(0)).array().square().matrix().rowwise().sum();
	}

	tsCount.resize(data.tsNum, data.totalLen - data.tsLen + 1);
	tsCount.setZero();

	for(int a = 0; a < data.fociNum; ++a)
	{
		low = qsdf[a] - epsilon;
		up = qsdf[a] + epsilon;
		forest[a].rangeQuery(low, up, &tsCount);
	}
	queryResult.resize(0);
	for(int x = 0; x < data.tsNum; ++x)
	{
		for(int y = 0; y < data.totalLen - data.tsLen + 1; ++y)
		{
			if(tsCount(x,y) == data.fociNum)
			{
				queryResult.push_back(x*1000+y);
			}
		}
	}
	

}
void OMNI::reinitial(int tLen, int fNum, int tstNum)
{
    cout<<"start reinitial"<<endl;
    data.initial(tLen, fNum);
    data.testPick(tstNum);
    forest.resize(0);
    forest.resize(fNum);
	for(int i = 0; i < fNum; ++i)
	{
		forest[i].BPTbuild(&(data.fd[i]));
	}
    cout<<"end reinitial"<<endl;
}