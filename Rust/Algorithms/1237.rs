/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * struct CustomFunction;
 * impl CustomFunction {
 *    pub fn f(x:i32,y:i32)->i32{}
 * }
 */

impl Solution {
    pub fn find_solution(customfunction: &CustomFunction, z: i32) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        for i in 1..101 {
            for j in 1..101 {
                let result = customfunction.f(i, j);
                if result == z {
                    res.push(vec![i, j]);
                    break;
                }
                if result > z {
                    break;
                }
            }
        }
        res
    }
}
