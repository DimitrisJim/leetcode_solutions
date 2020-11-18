use std::collections::VecDeque;

struct RecentCounter {
    last_ping: i32,
    pings: VecDeque<i32>,
}

impl RecentCounter {
    fn new() -> Self {
        RecentCounter {
            last_ping: 0,
            pings: VecDeque::new(),
        }
    }

    fn ping(&mut self, t: i32) -> i32 {
        if self.last_ping == 0 || t - self.last_ping > 3000 {
            self.pings.clear();
            self.pings.push_front(t);
            self.last_ping = t;
            return 1;
        }

        loop {
            if t - self.pings.back().expect("Some.") <= 3000 {
                self.pings.push_front(t);
                self.last_ping = t;
                break;
            }
            self.pings.pop_back();
        }
        self.pings.len() as i32
    }
}
