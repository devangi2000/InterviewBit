int Solution::removeDuplicates(vector<int> &A) {
   int n = A.size();
   if(n==0 || n==1) return n;
   int j=0;
   for(int i=0; i<n-1; i++)
   {
       if(i<n-1 && A[i]!=A[i+1])
          A[j++]=A[i];
   }
   A[j++]=A[n-1];
   return j;
}