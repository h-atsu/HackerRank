#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int makeAnagram(string a, string b) {
    map<char,int> mpa;
    map<char,int> mpb;
    for(auto itr : a) {
	mpa[itr]++;
    }
    for(auto itr : b) {
	mpb[itr]++;
    }
    int ans = 0;
    for(char c='a'; c<='z'; c++) {
	ans += abs(mpa[c] - mpb[c]);
//	cout << mpa[c] << mpb[c]<<endl;
    }
//    cout << ans << endl;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
