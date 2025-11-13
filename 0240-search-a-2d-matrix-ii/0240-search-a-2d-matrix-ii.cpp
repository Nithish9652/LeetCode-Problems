class Solution {
public:

bool BinarySearch( int rvalue , vector<vector<int>>& matrix , int tar ){

    int st = 0 , end = matrix[rvalue].size() - 1 ;

    while( st <= end ){
         int mid = st + (end-st)/2;
         if( matrix[rvalue][mid] == tar ) return 1;
         else if( matrix[rvalue][mid] > tar ){
             end = mid - 1;
         }else{
            st = mid + 1;
         }
    }
    return 0;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
    int rowsize = matrix.size() - 1;
    int colsize = matrix[0].size() - 1 ;

    for( int r = 0 ; r <= rowsize ; ++r ){
         if( BinarySearch( r , matrix , target )) return 1;
    }

    return 0;
      
    }
};