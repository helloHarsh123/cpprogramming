/*
no. of painters A;// maximum amount of painters can be applied to work simultaineously
time taken to paint 1cm = Bsec
array of lengths of paintings  C0 C1 -- CN-1
say N <= A then print max(Ci)*B
N>A
put all painters at work but which paintings to choose

1. we cant change order of boards
2. contiguous boards for same worker

eg. A = 3 B = 1 C ={1,3,5,8,2}
                    ---   - -
                    a0   a1 a2
                    
qn has changed to
partition the n size array into k sections st max(wi) is minimum
and answer is this*B
gmin = 9
1 3 5 8 2     max = 9
     - -
dp[i][j]  sigma ci to cj  //precomputations n^2
p0 0-0 p1 1-1 p2 2-4 // (n^3)*k
*/

bool isPossible(int A, int B, vector<int> &C,long long int X){
    int n=C.size();
   long long int t=X;
    int i=0,cnt=1;
    while(i<n){
        if(cnt>A)
         return false;
        if(C[i]>t){
            cnt++;
            t=X;
        }
        else{
            t=t-C[i];
            i++;
        }
    }
    return true;
}

void precomputesums(vector<int> &C, vector<int> &sums)
{
    sums[0] = C[0];
    for(int i=1;i<C.size();i++)
    {
        sums[i] = (sums[i-1]%10000003+C[i]%10000003)%10000003;
    }
    return;
}

int Solution::paint(int A,int B,vector<int> &C)
{
    //A is number of partitions
    int n = C.size();
    int k = A;
    // do k partitions of n tasks st max of sums of each partition is minimal
    //T(n,k) = min{ maxi=1ton{T(i,k-1),sigmaj=i+1 to n(Cj)} }
    vector<int> sums(n);
    precomputesums(C,sums);
    vector< vector<int> > dp(n+1, vector<int> (k+1,0));
    for(int i=1;i<=k;i++)
    {
       dp[1][i] = C[0];
    }
    for(int j=1;j<=n;j++)
    {
        dp[j][1] = sums[j-1];
    }
    /*
    4   ; . . .
j   3   ; . . .
    2   ; . . .
    1   ; ; ; ;
        1 2 3 4 i
    */
   for(int i=2;i<=n;i++)
   {
       for(int j=2;j<=k;j++)
       {
           int mn = INT_MAX;
           for(int x = 1;x<=i;x++)
           {
               mn =min( mn, max( dp[x][j-1],sums[i-1] - sums[x-1] ) );
           }
           dp[i][j] = mn;
       }
   }
   return ((long long int)(dp[n][k]%10000003)*(B%10000003)+10000003)%10000003;
}
