// Ammounts and mirrors can be precalculated 
// (by a script) based on p.
const power = 3;
const ammounts = [0, 4, 40, 316];
const mirrors = [
    1, 8, 10, 11, 18, 80, 81, 88, 100, 101, 
    108, 110, 111, 118, 180, 181, 188, 800, 
    801, 808, 810, 811, 818, 880, 881, 888
];
// mults stay the same independent from p.
const mults = [
    [1, 0], [2, 0], [2, 1], [2, 1], [2, 1], 
    [2, 2], [2, 3], [2, 3], [3, 3], [3, 4],
];

// Include any mirrored rotations.
let include_mirror_rotations = j => {
    let count = 1;
    for(let i of mirrors){
        if (j < i)
            break;
        count++;
    }
    return count;
}

const add_until_previous = (v, p) => {
    let [i, j] = mults[v-1];
    let prev = ammounts[p];
    return i * prev + j * (prev + Math.pow(3, p));
}

let rotatedDigits = N => {
    let div = Math.pow(10, power), good_numbers = 0, p = power;
    while (N) {
        let quot = Math.floor(N / div);
        N %= div;
        div /= 10;
        
        if (quot){
            good_numbers += add_until_previous(quot, p);
            
            if (quot == 3 || quot == 4 || quot == 7)
                return good_numbers;
            else if (quot == 2 || quot == 5 || quot == 6 || quot == 9)
                good_numbers += include_mirror_rotations(N);
        }
        p--;
    }
    
    return good_numbers;
}
