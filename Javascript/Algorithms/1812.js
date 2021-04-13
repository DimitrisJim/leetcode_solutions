/**
 * @param {string} coordinates
 * @return {boolean}
 */
let squareIsWhite = (coordinates) => {
    const col = coordinates[0].codePointAt() - 96,
        row = coordinates[1].codePointAt();

    return (col & 1) != (row & 1);
};