impl Solution {
    pub fn get_mults(size: i32) -> Vec<i32> {
        let mut arr: Vec<i32> = Vec::with_capacity(size as usize);
        let mut odds_occurs: Vec<(i32, i32)> = Vec::new();
    
        // create Vector of odd numbers and the number they 
        // occur in a Vector of size size.
        let mut i = 1;
        while i <= size{
            odds_occurs.push((i, (1 + (size - i))));
            i += 2;
        }
        // first element is # of odds.
        arr.push(odds_occurs.len() as i32);
        
        // find mid
        let mid = match size % 2 == 1 {
            false => size / 2,
            true => (size / 2) + 1,
        };
        
        // Build (half) vector of multiples.
        for idx in 2..mid+1 {
            let mut sum = 0;
            
            for (odd, occur) in &odds_occurs{
                if (idx < *odd) && (*occur > idx){
                    sum += idx;
                }
                else {
                    if *odd <= *occur{
                        sum += *odd;
                    } else {
                        sum += *occur;
                    }
                }
            }
            arr.push(sum);
        }
        
        // Build the other half.
        if size % 2 == 1 {
            for i in (0..=(arr.len() - 2)).rev(){
                arr.push(arr[i]);
            }
        } else {
            for i in (0..=(arr.len() - 1)).rev(){
                arr.push(arr[i]);
            }            
        }
        // return
        arr
    }
    
    pub fn sum_odd_length_subarrays(arr: Vec<i32>) -> i32 {
        // Handle fast edge cases.
        match arr.as_slice() {
            [x] => return *x,
            [x, y] => return *x + *y,
            [x, y, z] => return 2 * (*x + *y + *z),
            _ => (),
        }
        
        // Get Vec of multiples and make sum.
        let mut sum = 0;
        let mults = Solution::get_mults(arr.len() as i32);
        for i in 0..arr.len(){
            sum += arr[i] * mults[i];
        }
        
        sum
    }
}
