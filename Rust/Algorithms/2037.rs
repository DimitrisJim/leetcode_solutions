impl Solution {
    pub fn min_moves_to_seat(mut seats: Vec<i32>, mut students: Vec<i32>) -> i32 {
        seats.sort_unstable();
        students.sort_unstable();
        
        // Available in 1.59 in iter::zip
        // zip(seats, students)
        seats.iter().zip(students.iter()).map(|(a, b)| if a > b { a - b } else {b - a}).sum()
    }
}