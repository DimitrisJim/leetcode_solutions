/**
 * @param {string[][]} paths
 * @return {string}
 */
let destCity = paths => {
    const sources = new Set;
    const dests = new Set;
    for(let path of paths){
        sources.add(path[0]);
        dests.add(path[1]);
    }
    for (let i of dests){
        if (!sources.has(i)){
            return i;
        }
    }
};
