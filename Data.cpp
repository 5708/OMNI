#include "Data.h"

using namespace std;

void Data::read(string filename, int tNum, int ttLen)
{
	ifstream file;
	MatrixXd tempM;
	VectorXd tempV;
	
	tsNum = tNum;
	totalLen = ttLen;;
	file.open(filename.c_str());
	m.resize(tsNum, totalLen);
	for(int i = 0; i < tsNum; ++i)
	{
		for(int j = 0; j < totalLen; ++j)
		{
			file >> m(i,j);
		}
	}
	file.close();
}

void Data::initial(int tLen, int fNum)
{
    int rRow, rCol, rID;
    MatrixXd tempM;
    
    tsLen = tLen;
    fociNum = fNum;
    
    fociTS.resize(fociNum, tsLen);
	for(int a = 0; a < fociNum; ++a)
	{
		rRow = rand() % tsNum;
		rCol = rand() % (totalLen - tsLen);
		rID = rRow * 1000 + rCol;
		fociID.push_back(rID);
		fociTS.row(a) = m.block(rRow, rCol, 1,tsLen);
	}
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
	int timesSize;
	
// 	file.open ("output.txt");
// 	resultSize = (*result).size();
// 	for(int i = 0; i < resultSize; ++i)
// 		file << (*result)[i]<<"\n";
// 	file.close();
    
    file.open ("output_times.txt");
	timesSize = times.size();
	for(int i = 0; i < timesSize; ++i)
		file << times[i]<<"\n";
	file.close();
}

void Data::testPick(int num)
{
    int rRow, rCol;
    
    testNum = num;
    testTS.resize(testNum,tsLen);
    for(int i = 0; i < num; ++i)
    {
        rRow = rand() % tsNum;
        rCol = rand() % (totalLen - tsLen);
        testTS.row(i) = m.block(rRow, rCol, 1,tsLen);
    }
}

void Data::writeTestTS(int i)
{
    ofstream file;
    
    if(i == 0)
        file.open ("testTS1.txt");
    else if(i==1)
        file.open ("testTS2.txt");
    else if(i == 2)
        file.open ("testTS3.txt");
	for(int i = 0; i < testNum; ++i)
    {
        for(int j = 0; j < tsLen; ++j)
        {
            file << testTS(i,j)<<" ";
        }
        file<<endl;
    }
		
	file.close();
}