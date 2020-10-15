impl Solution {
    pub fn count_good_triplets(arr: Vec<i32>, a: i32, b: i32, c: i32) -> i32 {
        let mut count = 0;
        // Build combinations. 
        for i in 0..arr.len(){
            for j in i+1..arr.len(){
                // Bail early if we can.
                if a >= (arr[i] - arr[j]).abs(){
                    for k in j+1..arr.len(){
                        // Count if all conditions met.
                        if b >= (arr[j] - arr[k]).abs() && 
                           c >= (arr[i] - arr[k]).abs(){
                            count += 1;
                        }
                    }
                }
            }
        }
        count 
    }
}
