#include <bits/stdc++.h>
#define m 1000000007

using namespace std; 
int main(){
	long long T; 
	cin >> T; 
	long long n=1; 

	while(T--){
		 long long N; 
		 long long K; 
		 cin >>N; 
		 cin >>K; 
		 long long flag=1; 

		 vector <long long> first(N); 

		 for (long long i=0; i<N; i++){
		 	cin >> first[i]; 
		 }

		 vector <long long> second(N); 

		 for (long long i=0; i<N; i++){
		 	cin >> second[i]; 
		 }

		 long long found=-1; 

		 for (long long i=0; i<N; i++){
		 	if (second[0]==first[i]){
		 		found=i; 
		 		break; 
		 	}
		 }

		 if (found==-1){
		 	flag=0; 
		 }
		 else if (K==0){
		 	for (long long i=0; i<N; i++){
		 		if (first[i]!=second[i]){
		 			flag=0; 
		 		}
		 	}
		 }
		 else {
		 	for (long long i=0; i<N; i++){
		 		if (second[i]!=first[(i+found)%N]){
		 			flag=0; 
		 			break; 
		 		}
		 	}
		 }
		 

		 
		 if (flag==0) cout << "Case #" <<n++<< ": NO" << endl; 
		 else  cout << "Case #" <<n++<< ": YES" << endl; 
	}
}