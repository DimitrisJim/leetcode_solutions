const table = [];
let encode = longUrl => {
    table.push(longUrl)
    return `${table.length - 1}`;
};

let decode = shortUrl => {
    return table[parseInt(shortUrl)];
};
