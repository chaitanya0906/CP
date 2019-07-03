#include <bits/stdc++.h>
using namespace std;


//The Maximum number which elemnts count can reach
const int MAXN = 1e5 + 5e1;
//Count of elements in each bucket
const int BSZ = 2;
//The Maximum number which buckets can reach
const int MAXB = (MAXN + BSZ - 1) / BSZ + 1;

//sum[i] equals to sum of elements in i-th bucket and bucval[i] equals to value which all i-th bucket increased by
int a[MAXN], sum[MAXB], bucval[MAXB];

int getBucket( int i) {
    //returns bucket number of element i
    return i / BSZ;
}

int getStart( int i) {
    //returns start element of bucket which consists i
    return getBucket( i) * BSZ;
}

int getEnd( int i, int n) {
    //returns end element of bucket which consists i (bucket include numbers in [start, end) )
    return min( getStart( i) + BSZ, n);
}

int main() {
    //gets input
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++) 
	cin >> a[ i];

    //getting queries and process them
    int q;
    cin >> q;
    cerr << q << endl;
    int l, r, x;
    char c;
    while ( q --) {
	cin >> c >> l >> r;

	if ( c == '+') {
	    cin >> x; //The value which each element should encreased by
	    //In case both l and r are in the same bucket
	    if ( getBucket( l) == getBucket( r)) {
		sum[ getBucket( l)] += ( r - l) * x;
		for (int i = l; i < r; i ++)
		    a[ i] += x;
	    }
	    //In case not :|
	    else {
		for ( int i = l; i < getEnd( l, n); i ++) {
		    sum[ getBucket( i)] += x;
		    a[ i] += x;
		}
		for ( int i = getBucket( l) + 1; i < getBucket( r - 1); i ++) {
		    bucval[ i] += x;
		    sum[ i] += x * BSZ;
		}
		for ( int i = getStart( r - 1); i < r; i ++) {
		    sum[ getBucket( i)] += x;
		    a[ i] += x;
		}
	    }
	}

	if ( c == '?') {
	    int res = 0;
	     //In case both l and r are in the same bucket
	    if ( getBucket( l) == getBucket( r - 1)) {
		for ( int i = l; i < r; i ++)
		    res += a[ i] + bucval[ getBucket( i)];
	    }
	    //In case not :|
	    else {
		for ( int i = l; i < getEnd( l, n); i ++) 
		    res += a[ i] + bucval[ getBucket( i)];

		for ( int i = getBucket( l) + 1; i < getBucket( r - 1); i ++)
		    res += sum[i];

		for (int i = getStart(r-1); i < r; i ++) 
		    res += a[i] + bucval[ getBucket( i)];	
	    }

	    cout << res << endl;
	}
    }
}
