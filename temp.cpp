/*
bool is_good(ll m) {
	return true;
}

ll BS() {
	ll l = 1 , r = 2e9 , ans = -1;
	while ( l < r ) {
		ll m = l + ( r - l ) / 2;
		( is_good(m) ? l = m + 1 , ans = m : r = m );
	}
	return ans;
}
*/

/*
partial sum:
	int n , q;
	cin >> n >> q;
	vector<int> arr(n) , part(n+2);
	for ( int i = 1 ; i <= n ; ++i ) {
	    cin >> arr[i];
	}
	while ( q-- ) {
	    int l , r , v;
	    cin >> l >> r >> v;
	    part[l] += v;
	    part[r + 1] -= v;
	}
	for ( int i = 1 ; i <= n ; ++i ) {
	    part[i] += part[i - 1];
	}
	for ( int i = 1 ; i <= n ; ++i ) {
	    cout << arr[i] + part[i] << " ";
	}
*/ 

/*
prefix sum:
	int n , q;
	cin >> n >> q;
	vector<int> arr(n) , pref(n+1);
	for ( int i = 1 ; i <= n ; ++i ) {
		cin >> arr[i];
		pref[i] = pref[i - 1] + arr[i];
	}
	while ( q-- ) {
		int l , r;
		cin >> l >> r;
		cout << pref[r] - pref[l - 1] << endl;
	}
*/ 

/*
prefix and:
	const int N = 2e5 + 5;
	const int bits = 30;
	vector<vector<int>> pref(N , vector<int>(bits));
	vector<int> a;
	int n;
	
	void prefixAnd() {
		for ( int i = 0 ; i < n ; ++i ) {
			for ( int j = 0 ; j < bits ; ++j ) {
				if ( a[i] & ( 1 << j )) {
					pref[i + 1][j] = pref[i][j] + 1;
				}
				else {
					pref[i + 1][j] = pref[i][j];
				}
			}
		}
	}
*/ 

/*
permutation:
	int n;
	cin >> n;
	vector<int> v(n);
	cin >> v;

	sort(all(v));

	do {
		cout << v << endl;
	} while ( next_permutation(all(v)));
*/ 

/*
BFS:
	vector<vector<int>> g;
	
	void solve() {
		int n , m;
		cin >> n >> m;
		g.assign(n + 5 , vector<int>());
		vector<int> dis(n + 5 , inf);
		for ( int i = 0 ; i < m ; ++i ) {
			int u , v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
	
		int root = 1;
		queue<int> q;
		q.push(root);
		dis[root] = 0;
	
		while ( !q.empty()) {
			int sz = int(q.size());
			while ( sz-- ) {
				int src = q.front();
				q.pop();
	//			cout << src << " "; // print BFS;
	
				for ( auto & nxt : g[src] ) {
					if ( dis[nxt] == inf ) {
						q.push(nxt);
						dis[nxt] = dis[src] + 1;
					}
				}
			}
		}
	//	for ( int i = 1 ; i <= n ; ++i ) {
	//		cout << dis[i] << " ";
	//	} // to print shortest path from root
	}

	###############################################

	DFS:
	int n,m;
	
	vector<vector<int>> g;
	vector<bool> vis;
	
	void DFS(int src) {
		vis[src] = true;
		cout << src << " ";
	
		for ( auto & nxt : g[src] ) {
			if ( !vis[nxt] ) DFS(nxt);
		}
	
	}
	
	
	void solve() {
		cin >> n>>m;
		g.assign(n + 5 , vector<int>());
		vis.assign(n + 5 , false);
		int root = 1;
		
		for ( int i = 0 ; i < m ; ++i ) {
			int u , v;
			cin >> u >> v;
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		
		DFS(root);
	}
	

##############################################################

	Factorial:
	ll fact (ll n){
		if(n==0 || n==1)
			return 1;
	
		else
			return n*fact(n-1);
	}

	##########################################################

	FastPower:
	ll fastPow(ll base , ll power , ll modulo = 1e18 + 5) {
		ll result = 1;
		for ( ; power ; power >>= 1 ) {
			if ( power & 1 ) result = 1LL * result * base % modulo;
			base = 1LL * base * base % modulo;
		}
		return result;
	}

	#################################################################

	gcd & lcm:
	long long gcd(long long a , long long b) {
	if ( a == 0 )
		return b;
	return gcd(b % a , a);
	}

	long long lcm(long long a , long long b) { return ( a / gcd(a , b)) * b; }

	################################################################

	prime factors:
	int factors(ll n) {
		set<int> st;

		int p = 2;
		while ( n > 1 ) {
			while ( n % p == 0 ) {
				st.emplace(p);
				n /= p;
			}
			p++;
		}
		return st.size();
	}

	#######################################################################

	int dx[8] = { 0 , 0 , 1 , -1 , 1 , -1 , 1 , -1 };
	int dy[8] = { 1 , -1 , 0 , 0 , 1 , -1 , -1 , 1 };

	bool comp(int x , int y) {
		return x > y;
	}

	##########################################################################

	isSqure or cubed:
	bool isSquare(int num) {
		int root = sqrt(num);
		return ( root * root ) == num;
	}
	
	bool isCube(int num) {
		int root = cbrt(num);
		return ( root * root * root ) == num;
	}

	int res = (int) sqrt(n) + (int) cbrt(n) - (int) ( sqrt(cbrt(n)));

	######################################################################

	Mex:
	ll mex(vector<int> v) {
		set<ll> st(v.begin() , v.end());
		ll indx = 0;
		for ( auto i : st ) {
			if ( i != indx ) return indx;
			indx++;
		}
		return indx;
	}

	####################################################################

	Rectangle:
	struct Rect {
		ll x1 , y1 , x2 , y2;

		ll area() { return ( y2 - y1 ) * ( x2 - x1 ); }
	};

	long long area(int bl_x , int bl_y , int tr_x , int tr_y) {
		long long length = tr_y - bl_y;
		long long width = tr_x - bl_x;
		return length * width;
	}

	ll intersect(Rect p , Rect q) {
		ll xOverlap = max(0ll , min(p.x2 , q.x2) - max(p.x1 , q.x1));
		ll yOverlap = max(0ll , min(p.y2 , q.y2) - max(p.y1 , q.y1));
		return xOverlap * yOverlap;
	}

	Rect cut(Rect A , Rect B) {

		if ( A.x1 >= B.x1 && B.x2 >= A.x1 && B.y1 <= A.y1 && B.y2 >= A.y2 ) {
			A.x1 = B.x2;
			A.x2 = max(A.x2 , B.x2);
		}

		if ( A.x2 >= B.x1 && B.x2 >= A.x2 && B.y1 <= A.y1 && B.y2 >= A.y2 ) {
			A.x2 = B.x1;
			A.x1 = min(A.x1 , B.x1);
		}


		if ( A.y1 >= B.y1 && B.y2 >= A.y1 && B.x1 <= A.x1 && B.x2 >= A.x2 ) {
			A.y1 = B.y2;
			A.y2 = max(A.y2 , B.y2);  // If B covers A entirely
		}


		if ( A.y2 >= B.y1 && B.y2 >= A.y2 && B.x1 <= A.x1 && B.x2 >= A.x2 ) {
			A.y2 = B.y1;
			A.y1 = min(A.y1 , B.y1);
		}

		return A;
	}

	bool is_intersect(vector<int> s1 , vector<int> s2) {
		int bl_a_x = s1[0] , bl_a_y = s1[1] , tr_a_x = s1[2] , tr_a_y = s1[3];
		int bl_b_x = s2[0] , bl_b_y = s2[1] , tr_b_x = s2[2] , tr_b_y = s2[3];

		// no overlap
		if ( bl_a_x >= tr_b_x || tr_a_x <= bl_b_x || bl_a_y >= tr_b_y ||
		     tr_a_y <= bl_b_y ) {
			return false;
		}
		else {
			return true;
		}
	}

	int inter_area(vector<int> s1 , vector<int> s2) {
		int bl_a_x = s1[0] , bl_a_y = s1[1] , tr_a_x = s1[2] , tr_a_y = s1[3];
		int bl_b_x = s2[0] , bl_b_y = s2[1] , tr_b_x = s2[2] , tr_b_y = s2[3];

		return (( min(tr_a_x , tr_b_x) - max(bl_a_x , bl_b_x)) *
		        ( min(tr_a_y , tr_b_y) - max(bl_a_y , bl_b_y)));
	}

	void solve() {
		Rect a , b , t;
		cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
		cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
		cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;


	}

*/ 