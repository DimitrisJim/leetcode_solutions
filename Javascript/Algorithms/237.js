// Also, [node.val, node.next] = [node.next.val, node.next.next];
let deleteNode = node => {
    const next = node.next;
    node.val = next.val;
    node.next = next.next;
};
