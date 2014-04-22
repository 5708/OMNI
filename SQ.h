#ifndef _SQ_H_
#define _SQ_H_
#include <iostream>
#include <vector>
using namespace std;

class SQ
{
public:
	double epsilon;
	vector<vector<int> > singleMatch;
	vector<vector<vector<int> > > match;
	int queryLen, tsLen, tsNum;

	//Part 1
	void initialBPT();
	
	//Part 2
	void similarityQuery(double v);
	void matchCheck();
	void clearMatchTS(int i);
	
	//Part 3
	
	//Part 40


};

#endif