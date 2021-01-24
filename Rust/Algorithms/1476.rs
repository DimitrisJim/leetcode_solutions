struct SubrectangleQueries {
    rectangle: Vec<Vec<i32>>,
}

impl SubrectangleQueries {
    fn new(rectangle: Vec<Vec<i32>>) -> Self {
        Self { rectangle }
    }

    fn update_subrectangle(
        &mut self,
        row1: i32,
        col1: i32,
        row2: i32,
        col2: i32,
        new_value: i32,
    ) {
        // Get mut ref to rectangle.
        let rect = &mut self.rectangle;
        for i in row1..=row2 {
            for j in col1..=col2 {
                rect[i as usize][j as usize] = new_value;
            }
        }
    }

    fn get_value(&self, row: i32, col: i32) -> i32 {
        self.rectangle[row as usize][col as usize]
    }
}
