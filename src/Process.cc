#include "Process.h"
#include <strstream>
using namespace std;
Process::Process(const string& line){
	istrstream istr(line.c_str());
	string word;
	while(istr>>word){
		words.push_back(word);
	}
}
Process::~Process(){}

void Process::process(const Vocabulary& vocab, const Model& model){
	vector< vector<StateItem> > beams(words.size()+1);
	beams[0].push_back(StateItem());
	beams[0][0].state = model.BeginSentenceState(); 
	for(int i = 0; i < words.size(); i ++){

/*		std::cerr<<"==============="<<std::endl<<"beam "<<i<<std::endl;
		for(int j = 0; j < beams[i].size(); ++j){
			for(int k = 0; k < beams[i][j].path.size(); ++k){
				std::cout<<words[beams[i][j].path[k]]<<" ";
			}
			std::cout<<beams[i][j].score<<std::endl;
		}
*/		for(int j = 0; j < beams[i].size(); ++j){
			for(int k = 0; k < words.size(); k ++){
				if(beams[i][j].check(k)) continue;
				StateItem newstateitem;
				newstateitem.copy(beams[i][j]);
				beams[i][j].transit(newstateitem, vocab, model, words[k], k);

				adjust(beams[i+1],newstateitem);
			}
		}
	}
	const vector<int>& path = beams[words.size()][0].path;
	for(int i = 0; i < path.size(); i ++){
			std::cout<<words[path[i]]<<" ";
	}
	std::cout<<endl;
}
void Process::adjust(vector<StateItem>& beam, const StateItem& newstateitem){
	int pos = 0;
	for(int i = 0; i < beam.size(); i ++, pos++){
		if(beam[i].score <= newstateitem.score){
			break;
		}
	}
	beam.insert(beam.begin()+pos,newstateitem);
	if(beam.size() > BEAM_SIZE) beam.pop_back();
}
