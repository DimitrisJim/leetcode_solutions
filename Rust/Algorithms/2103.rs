impl Solution {
    pub fn count_points(rings: String) -> i32 {
        let (RED, BLUE, GREEN) = (1, 2, 4);
        let mut rods = vec![0; 10];
        
        let mut it = rings.chars();
        while let Some(color) = it.next() {
            // ok due to constraints.
            let rod = it.next().unwrap().to_digit(10).unwrap() as usize;
            rods[rod] |= match color {
                'R' => RED,
                'G' => GREEN,
                'B' => BLUE,
                _ => 0
            };
        }

        rods.iter().filter(|&&x| x == 7).count() as i32
    }
}