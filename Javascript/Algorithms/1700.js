let countStudents = function(students, sandwiches) {
    const st = Queue.fromArray(students),
          sa = Queue.fromArray(sandwiches);
    let i = 0;
    
    while (i != st.size()){
        if (st.front() == sa.front()){
            st.dequeue();
            sa.dequeue();
            i = 0;
        } else {
            st.enqueue(st.dequeue());
            i++;
        }
    }
    return st.size();
};
