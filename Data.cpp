#include "Data.h"

using namespace std;

void Data::read(string filename, int tNum, int tLen, int ttLen, int fNum)
{
	ifstream file;
	int rCol, rRow, rID;
	MatrixXd tempM;
	VectorXd tempV;
	
	tsNum = tNum;
	tsLen = tLen;
	totalLen = ttLen;
	fociNum = fNum;
	file.open(filename);
	m.resize(tsNum, totalLen);
	for(int i = 0; i < tsNum; ++i)
	{
		for(int j = 0; j < totalLen; ++j)
		{
			file >> m(i,j);
		}
	}
	file.close();

	fociTS.resize(fociNum, tsLen);
	for(int a = 0; a < fociNum; ++a)
	{
		rRow = rand() % tsNum;
		rCol = rand() % (totalLen - tsLen);
		rID = rRow * 1000 + rCol;
		fociID.push_back(rID);
		fociTS.row(a) = m.block(rRow, rCol, 1,tsLen);
	}
	cout<<fociTS;
	fd.resize(fociNum);
	tempM.resize(tsNum, tsLen);
	for(int i = 0; i < fociNum; ++i)
	{
		fd[i].resize(tsNum, totalLen - tsLen + 1);
		for(int j = 0; j < totalLen - tsLen + 1; ++j)
		{
			tempM = m.block(0,j,tsNum, tsLen);
			fd[i].col(j) = tempM.rowwise().operator-(fociTS.row(i)).array().square().matrix().rowwise().sum();
		}
	}

}

void Data::write(vector<int>* result)
{
	ofstream file;
	int resultSize;
	
	file.open ("output.txt");
	resultSize = (*result).size();
	for(int i = 0; i < resultSize; ++i)
		file << (*result)[i]<<"\n";
	file.close();
}