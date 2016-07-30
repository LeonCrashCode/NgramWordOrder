#ifndef PROCESS_H
#define PROCESS_H
#include <string>
#include <vector>
#include "StateItem.h"
#include <map>
#define BEAM_SIZE 64
using namespace std;
using namespace lm::ngram;
class Process{
public:
	vector<string> words;
	map<string, int> bow;
public:
	Process(const string& line);
	~Process();

	void process(const Vocabulary& vocab, const Model& model);
	void adjust(vector<StateItem>& beam, const StateItem& newstateitem);
};


#endif
