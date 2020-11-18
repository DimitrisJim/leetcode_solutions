
var RecentCounter = function() {
    this.last_ping = 0;
    this.pings = new Queue()
};

/** 
 * @param {number} t
 * @return {number}
 */
RecentCounter.prototype.ping = function(t) {
    let pings = this.pings;
    if (!this.last_ping || (t - this.last_ping > 3000)){
        pings.clear();
        pings.enqueue(t);
        this.last_ping = t;
        return 1;
    }
    
    while (true){
        if (t - pings.front() > 3000){
            pings.dequeue();
        } else {
            pings.enqueue(t);
            this.last_ping = t;
            return pings.size();
        }
    }
};
