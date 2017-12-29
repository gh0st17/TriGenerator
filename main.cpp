#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

size_t count(int i){
	stringstream ss;
	ss << i;
	return ss.str().size();
}

int main(){
	int limit;
	cin >> limit;
	if (count(limit) > 4 || limit < 2) return 1;
	ofstream ofs("tri.txt");
	for (int i = 0; i < limit; i++){
		for (int j = 0; j <= i; j++){
			srand(time(0) + i + j + i*j);
			stringstream ss;
			ss << 1 + rand() % 99;
			string s = ss.str();
			if (s.size() < 2) s.insert(0, "0");
			ofs << s;
			if (j != i) ofs << ' ';
		}
		ofs << '\n';
	}
	ofs.close();
	return 0;
}