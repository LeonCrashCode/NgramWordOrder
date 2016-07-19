#include "lm/model.hh"
#include <iostream>
#include <string>
#include "Process.h"
#include <fstream>
using namespace std;
using namespace lm;

int main() {
	Model model("file.arpa");
	const Vocabulary &vocab = model.GetVocabulary();

	ifstream ifs("test");
	string line;
	while(getline(ifs,line)){
		Process proc(line);
		proc.process(vocab,model);

	}
}
