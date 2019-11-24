#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Candidate {
	string name;
	int votes = 0;
};

Candidate Candidates[10];

bool isName(string line) {
	if (line.length() < 1) return false;
	for (int i = 0; i < line.length(); ++i) {
		if (line[i] == '0' || line[i] == '1' || line[i] == '2' || line[i] == '3' || line[i] == '4' || line[i] == '5' || line[i] == '6' || line[i] == '7' || line[i] == '8' || line[i] == '9') return false;
	}
	return true;
}

string formatLine(string name, int votes) {
	int spaceNum = 15 - name.length();
	for (int i = 0; i < spaceNum; ++i) {
		name += " ";
	}
	string voteNum = to_string(votes);
	spaceNum = 3 - voteNum.length();
	for (int i = 0; i < spaceNum; ++i) {
		voteNum = " " + voteNum;
	}
	return name + voteNum;
}

void printResult(int voters, int spoiltBallots, int countCand) {
	int validBallots = voters - spoiltBallots;
	cout << "Number of voters: " << voters << endl;
	cout << "Number of valid ballots: " << validBallots << endl;
	cout << "Number of spoilt ballots: " << spoiltBallots << endl;
	cout << endl;
	cout << "Candidate      Score" << endl;
	cout << endl;
	for (int i = 0; i < countCand; ++i) {
		string line = formatLine(Candidates[i].name, Candidates[i].votes);
		cout << line << endl;
	}
}

void verifyVotes(string numStr) {
	int countCand = 0;
	int voters = 0;
	int invalidBallots = 0;
	string currentLine;

	int votesLimit;
	if (numStr == "0") votesLimit = -1;
	else {
		istringstream iss{ numStr };
		iss >> votesLimit;
	}

	while (getline(cin, currentLine)) {
		if (isName(currentLine)) {
			Candidates[countCand].name = currentLine;
			++countCand;
		}
		else {
			if (votesLimit == -1) votesLimit = countCand;
			string currentLine1 = currentLine;
			++voters;
			int sum = 0;
			int temp;
			int col = 0;
			stringstream stream(currentLine);
			while (stream >> temp) {
				sum += temp;
				++col;
			}
			if (col == countCand && sum <= votesLimit) {
				col = 0;
				stringstream stream(currentLine1);
				while (stream >> temp) {
					Candidates[col].votes += temp;
					++col;
				}
			} else {
				++invalidBallots;
			}
		}
	}
	printResult(voters, invalidBallots, countCand);
}

int main(int argc, char *argv[]) {
	string numOfVotesStr;
	if (argc == 1) numOfVotesStr = "0";
	else numOfVotesStr = argv[1];
	verifyVotes(numOfVotesStr);
}

