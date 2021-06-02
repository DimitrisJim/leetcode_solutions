use std::collections::HashSet;


impl Solution {
    pub fn find_poisoned_duration(time_series: Vec<i32>, duration: i32) -> i32 {
      if duration == 0 { 
        return 0;
      }
      if duration == 1 {
        return time_series.iter().collect::<HashSet<&i32>>().len() as i32; 
      } 

      let mut seconds = 0;
      for i in 1..time_series.len() {
        let a1 = time_series[i - 1];
        let a2 = time_series[i];
        if a1 != a2 { 
          seconds += if a2 < (a1 + duration) { a2 - a1 } else { duration };
        }
      }
      // add duration for final element.
      seconds + duration
    }
}