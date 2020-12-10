impl Solution {
    fn handle_op(op: &String, scores: &mut Vec<i32>) {
        let len = scores.len();
        if op == "C" {
            scores.pop();
        } else if op == "+" {
            let (i, j) = (scores[len - 1], scores[len - 2]);
            scores.push(i + j);
        } else if op == "D" {
            scores.push(scores[len - 1] * 2);
        } else {
            scores.push(op.parse::<i32>().unwrap());
        }
    }

    pub fn cal_points(ops: Vec<String>) -> i32 {
        let mut scores = Vec::new();
        let handle_op = Solution::handle_op;
        let mut i = 0;
        while i < ops.len() - 1 {
            let op = &ops[i];
            if ops[i + 1] == "C" && op != "C" {
                i += 2;
                continue;
            }
            handle_op(op, &mut scores);
            i += 1;
        }
        if (i < ops.len()) {
            handle_op(&ops[ops.len() - 1], &mut scores);
        }
        scores.iter().sum::<i32>()
    }
}
