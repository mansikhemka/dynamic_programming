        #include<iostream>
     
        using namespace std;
     
        int MatrixChainOrder(int p[], int n){
        	int matrix[n+1][n+1];
     
        	for(int i=0;i<=n;i++)
        		matrix[i][i] = matrix[0][i]=0;
     
        	for(int s=1;s<=n;s++){
     
        		for(int i=1;i<=n-s;i++){
     
        			int j=s+i;
     
        			int mini=matrix[i][i]+matrix[i+1][j]+p[i-1]*p[i]*p[j];
     
        			for(int k=i+1;k<j;k++){
        				if(matrix[i][k]+matrix[k+1][j]+p[i-1]*p[k]*p[j]<mini)
        					mini = matrix[i][k]+matrix[k+1][j]+p[i-1]*p[k]*p[j];
        			}
        			matrix[i][j]=mini;
        		}
        	}
        	return matrix[1][n];
        }
     
        int main(){
        	int n;
        	cin>>n;
        	int p[n+1];
     
        	for(int i=0;i<=n;i++)
        		cin>>p[i];
     
        	cout<<MatrixChainOrder(p,n);
        }