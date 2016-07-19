#ifndef STATEITEM_H
#define STATEITEM_H
#include "lm/model.hh"
#include "lm/ngram_query.hh"
#include <iostream>

using namespace std;
using namespace lm::ngram;

class StateItem{
public:
	double score;
	unsigned long bits[4];
	State state;
	vector<int> path;
public:
	StateItem(){
			bits[0] = (unsigned long)0;
			bits[1] = (unsigned long)0;
			bits[2] = (unsigned long)0;
			bits[3] = (unsigned long)0;
			score = 0.0;
			path.clear();
	};
	~StateItem(){};
	
	void copy(const StateItem& stateitem){
		bits[0] = stateitem.bits[0];
		bits[1] = stateitem.bits[1];
		bits[2] = stateitem.bits[2];
		bits[3] = stateitem.bits[3];
		score = stateitem.score;
		path = stateitem.path;
	}
	bool check(const int& index){
		unsigned long anchor = 1;
		if(index < 64){
			return ( (anchor << index) & bits[0] );
		}
		else if(index < 128){
			return ( (anchor << (index-64)) & bits[1] );
		}
		else if(index < 192){
			return ( (anchor << (index-128)) & bits[2] );
		}
		else if(index < 256){
			return ( (anchor << (index-192)) & bits[3] );
		}
		else{
			std::cerr<<"out of the range"<<std::endl;
			exit(1);
			return false;
		}

	}
	void transit(StateItem& stateitem, const Vocabulary& vocab, const Model& model, const string& word, const int& index){
			lm::FullScoreReturn ret = model.FullScore(state, vocab.Index(word), stateitem.state);
		stateitem.score += ret.prob;
		unsigned long anchor = 1;
		stateitem.path.push_back(index);
		if(index < 64) stateitem.bits[0] &= (anchor << index);
		else if(index < 128) stateitem.bits[1] &= (anchor << (index - 64));
		else if(index < 192) stateitem.bits[2] &= (anchor << (index - 128));
		else if(index < 256) stateitem.bits[3] &= (anchor << (index - 192));
		else {
			std::cerr<<"out of the range"<<std::endl;
			            exit(1);
		}
	}
};

#endif
