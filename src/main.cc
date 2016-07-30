#include "lm/model.hh"
#include <iostream>
#include <string>
#include "Process.h"
#include <fstream>
using namespace std;
using namespace lm;

int main(int argc, char** argv) {
	Model model(argv[1]);
	const Vocabulary &vocab = model.GetVocabulary();

	ifstream ifs(argv[2]);
	string line;
	while(getline(ifs,line)){
		Process proc(line);
		proc.process(vocab,model);

	}
}
