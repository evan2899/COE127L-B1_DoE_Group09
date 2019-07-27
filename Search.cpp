#include <omp.h>
#include <iostream>
#include <fstream>
#include "Word.h"
int main(int argc,char*argv[])
{
	std::string word = "word";
	string filename = "american-english.csv";
	string filename2 = "data.csv";
	std::ifstream file; 
	std::ofstream ofs;
	std::size_t line_number = 0;
	std::string line;
	double time1{};
	double start_time;
	Word wordsearch;
	wordsearch.createFile(ofs, filename2);
	wordsearch.openFile(file, filename);	
	start_time = omp_get_wtime();
	while (std::getline(file, line))
	{
		++line_number;
		if (wordsearch.contains(line, word)) 
		{
			wordsearch.disp(line_number,line,word,time1);
			wordsearch.wrFile(ofs, line, word, time1, line_number);
		}
			time1 = omp_get_wtime() - start_time;

	}
			
			cout<<"Total time: " <<time1;
}
