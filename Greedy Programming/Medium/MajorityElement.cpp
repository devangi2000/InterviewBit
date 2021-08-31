// Given an array of size n, find the majority element.
//  The majority element is the element that appears more than floor(n/2) times.
// You may assume that the array is non-empty and the majority element always exist in the array.

// Example :

// Input : [2, 1, 2]
// Return  : 2 which occurs 2 times which is greater than 3/2.


// DON'T DO THIS 

int Solution::majorityElement(const vector<int> &A) 
{
   int n = A.size();
   unordered_map<int, int> m;
   for(auto a : A) m[a]++;
   for(auto a : A)
        if(m[a] > (n/2))
            return a;
    return -1;
}


// DO THIS: MOORE'S ALGO

int Solution::majorityElement(const vector<int> &A) 
{
   int n = A.size();
   int el = A[0], count = 1;
   for(int i = 1; i < n; i++){
       if(count == 0){
           el = A[i];
       }
       if(el == A[i]){
           count++;
       }
       else count--;
   }
   return el;
}

