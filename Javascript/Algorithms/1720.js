let decode = (encoded, first) => {
    const result = [first];
    let end = 0;
    encoded.forEach(x => {
        result.push(result[end++] ^ x);
    });
    return result;
};
