impl Solution {
    pub fn interpret(command: String) -> String {
        let length = command.len();
        let mut i = 0;
        let mut result = String::new();
        let mut char_it = command.chars();

        while let Some(c1) = char_it.next() {
            match c1 {
                // Match 'G', nothing else to do.
                'G' => {
                    result.push(c1);
                }
                '(' => {
                    // Cases () and (al)
                    match char_it.next() {
                        // Match '()'
                        Some(')') => {
                            result.push('o');
                        }
                        Some('a') => {
                            result.push_str("al");
                            // Better way to advance?
                            // skip won't do.
                            char_it.next();
                            char_it.next();
                        }
                        _ => {}
                    }
                }
                _ => {}
            }
        }
        result
    }
}
