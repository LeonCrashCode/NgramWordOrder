#include "Process.h"
#include <strstream>
using namespace std;
Process::Process(const string& line){
	istrstream istr(line.c_str());
	string word;
	while(istr>>word){
		words.push_back(word);
		if(bow.find(word) == bow.end()) bow[word] = 1;
		else bow[word] += 1;
	}
}
Process::~Process(){}

void Process::process(const Vocabulary& vocab, const Model& model){
	vector< vector<StateItem> > beams(words.size()+1);
	beams[0].push_back(StateItem(bow));
	beams[0][0].state = model.BeginSentenceState(); 
	for(int i = 0; i < words.size(); i ++){

		for(int j = 0; j < beams[i].size(); ++j){
			vector<string> actions;
			beams[i][j].generate(actions);
			for(int k = 0; k < actions.size(); k ++){
				StateItem newstateitem(beams[i][j]);
				beams[i][j].transit(newstateitem, vocab, model, actions[k]);

				adjust(beams[i+1],newstateitem);
			}
		}
/*		std::cout<<"==============="<<std::endl<<"beam "<<i<<std::endl;
                for(int j = 0; j < beams[i+1].size(); ++j){
                        for(int k = 0; k < beams[i+1][j].path.size(); ++k){
                                std::cout<<beams[i+1][j].path[k]<<" ";
                        }
                        std::cout<<beams[i+1][j].score<<std::endl;
                }
*/	}
	const vector<string>& path = beams[words.size()][0].path;
	for(int i = 0; i < path.size()-1; i ++){
			std::cout<<path[i]<<" ";
	}
	std::cout<<path.back();
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
