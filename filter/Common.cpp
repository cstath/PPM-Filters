#include "Common.h"

using namespace std;
using namespace imaging;

void parseInit(int argc, char ** argv, string & inputFileName, string & outputFileName, list<Filter *> & filtersList){

	string argument;

	int i = 1;

	while(i<argc){

		argument = string(argv[i]);

		if (argument == "-o"){
			if (i+1 < argc) {
				i++;
				outputFileName = string(argv[i]);
			}
			else
			{
				cout << "Missing argument!" << endl;
				exit(1);
			}
		}
		else if (argument == "-f"){
			if (i+1 < argc){
				i++;
				filtersList.push_back( stringToFilter(string(argv[i])) );
			}
			else{
				cout << "Missing argument!" << endl;
				exit(1);
			}
		}
		else
		{
			inputFileName = string(argv[i]);
			break;
		}

		i++;
	}
	
	if (inputFileName.empty()){
		cout << "Please enter input filename: " << endl;
		cin >> inputFileName;
	}
	if (outputFileName.empty()){
		cout << "Please enter output filename: " << endl;
		cin >> outputFileName;
	}

	cout << "Input filename: " << inputFileName << endl;
	cout << "Output filename: " << outputFileName << endl;
	cout << "Filters list: " << filtersList << endl;
}

std::ostream& operator<<(std::ostream &strm, const list<Filter *> &a) {
	strm << "[";
	for (list<Filter *>::const_iterator it = a.begin(); it != a.end(); it++)
		strm << " " << **it;
	strm << " ]";
	return strm;
}

Filter * stringToFilter(string filterString){

	if(filterString == "gray")
		return new GrayFilter;
	if(filterString == "blur")
		return new BlurFilter;
	if(filterString == "diff")
		return new DiffFilter;
	if(filterString == "median")
		return new MedianFilter;
	
	cout << "Argument: \"" << filterString << "\" not recognized as a filter!!!" << endl;
	exit(1);

	return NULL;

}