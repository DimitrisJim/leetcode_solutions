let lastStoneWeight = stones => {
    let pq = new MaxPriorityQueue({priority: x => x});
    stones.forEach(x => pq.enqueue(x));
    
    while (1){
        let [e1, e2] = [pq.dequeue(), pq.dequeue()];
        if (!e1){
            return 0;
        }
        if (!e2){
            return e1.element;
        }
        let diff = e1.element - e2.element;
        if (diff){
            pq.enqueue(diff);
        }
    }
};
