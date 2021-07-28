use std::collections::HashMap;

struct AuthenticationManager {
    timeToLive: i32,
    tokens: HashMap<String, i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl AuthenticationManager {

    fn new(timeToLive: i32) -> Self {
        Self {
            timeToLive,
            tokens: HashMap::new()
        }
    }
    
    fn generate(&mut self, token_id: String, current_time: i32) {
        self.tokens.insert(token_id, current_time + self.timeToLive);
    }
    
    fn renew(&mut self, token_id: String, current_time: i32) {
        if let Some(v) = self.tokens.get_mut(&token_id) {
            if *v > current_time {
                *v = current_time + self.timeToLive;
            }
        }
    }
    
    fn count_unexpired_tokens(&self, current_time: i32) -> i32 {
        self.tokens.values().filter(|&&v| v > current_time).count() as i32
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * let obj = AuthenticationManager::new(timeToLive);
 * obj.generate(tokenId, currentTime);
 * obj.renew(tokenId, currentTime);
 * let ret_3: i32 = obj.count_unexpired_tokens(currentTime);
 */