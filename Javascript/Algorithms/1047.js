let removeDuplicates = S => {
    let stack = [];
    for (let c of S) {
        if (stack.length && (stack[stack.length - 1] == c)){
            stack.pop();
        } else {
            stack.push(c);
        }
    }
    return stack.join("");
};
