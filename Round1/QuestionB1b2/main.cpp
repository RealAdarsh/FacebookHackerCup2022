#include <bits/stdc++.h>
#define m 1000000007

using namespace std; 
int main(){
	long long T; 
	cin >> T; 
	long long n=1; 

	while(T--){
		long long N; 
		cin>>N;
		vector <pair<long long,long long>> Tree(N);
		long long sum=0; 

		cout << "Case #" << n++<<": "; 

		for (long long i=0; i<N; i++){
			cin>> Tree[i].first;
			cin>> Tree[i].second; 
		}

		int Q; 
		cin>>Q; 

		vector <pair<long long,long long>> Wells(Q); 

		for (long long i=0; i<Q; i++){
			cin>>Wells[i].first; 
			cin>>Wells[i].second;
		}

		long long sumXTree=0;
		long long sumYTree=0; 

		for (long long i=0; i<N; i++){
			long long square=Tree[i].first;
			square=(square%m * square%m)%m; 
			square=(square*(Q))%m; 
			sum=(sum%m + square%m)%m; 

			long long square2=Tree[i].second;
			square2=(square2%m * square2%m)%m; 
			square2=(square2*(Q))%m; 
			sum=(sum%m + square2%m)%m; 

			sumXTree=(sumXTree%m + Tree[i].first%m)%m; 
			sumYTree=(sumYTree%m + Tree[i].second%m)%m;
		}
		

		for (long long i=0; i<Q; i++){
			long long square=Wells[i].first;
			square=(square%m * square%m)%m; 
			square=(square%m*(N%m))%m; 
			sum=(sum%m + square%m)%m; 

			long long square2=Wells[i].second;
			square2=(square2%m * square2%m)%m; 
			square2=(square2%m*(N%m))%m; 
			sum=(sum%m + square2%m)%m; 
		}

		for (long long i=0; i<Q; i++){
			long long subtract= (Wells[i].first%m*sumXTree%m)%m; 
			subtract=(subtract*2)%m; 
			long long subtract2= (Wells[i].second%m*(sumYTree%m))%m;
			subtract2=(subtract2*2)%m; 

			sum=((sum%m - subtract%m)%m + m)%m; 
			sum=((sum%m - subtract2%m)%m + m)%m; 

		}

		

		cout << sum << endl; 
		
	}
}