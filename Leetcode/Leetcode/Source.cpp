#include <iostream>
#include <string>

using namespace std;



	bool canConstruct(string ransomNote, string magazine) {

		int truecount = 0;
		string mag = magazine;


		for (int i = 0; i < ransomNote.length(); i++) {

			for (int j = 0; j < mag.length(); i++) {

				if (ransomNote.at(i) == mag.at(j)) {
					truecount++;
					mag.erase(j-1, 1);
				}

			}

		}

		if (truecount == ransomNote.length()) {
			return true;
		}
		return false;

	}


int main() {

	cout << canConstruct("a", "ab");

}