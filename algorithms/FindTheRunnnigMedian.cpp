#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */


void runningMedian(vector<int> arr) {
    struct compare
    {
	bool operator()(const int & a, const int & b)
	{
	    return a<b;
	}
    };
    // Print your answer within the function
    int n = arr.size();
    float med[n+1];
    priority_queue<float, vector<float>, compare> ma;
    priority_queue<float, vector<float>, greater<float>> mi;
    ma.push(min(float(arr[0]), float(arr[1])));
    mi.push(max(float(arr[0]), float(arr[1])));
    med[0] = float(arr[0]);
    med[1] = (mi.top() + ma.top())/2;
    for(int i=2;i<n;i++) {
	if(mi.top() < arr[i]) {
	    mi.push(arr[i]);
	    float val = mi.top();
//	    cout << val << endl;
	    mi.pop();
	    ma.push(val);
//	    cout << "ma.top() : " << ma.top() << " mi.top() : " << mi.top() << endl;;
	}
	else ma.push(arr[i]);
	if(ma.size() - mi.size() > 1) {
	    float val = ma.top();
	    ma.pop();
	    mi.push(val);
	}
	if(i%2 == 0) {
	    med[i] = ma.top();
	}
	else {
	    med[i] = (ma.top() + mi.top()) / 2;
	}
//	cout << ma.size() << mi.size() << endl;
    }
    for(int i=0; i<n; i++){
	printf("%.1f\n", med[i]);
    }

}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    runningMedian(a);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
