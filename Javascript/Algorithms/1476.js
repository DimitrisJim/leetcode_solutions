var SubrectangleQueries = function(rectangle) {
    this.rect = rectangle;    
};

SubrectangleQueries.prototype.updateSubrectangle = function(row1, col1, row2, col2, newValue) {
    const rect = this.rect;
    for (let i = row1; i <= row2; i++)
        for (let j = col1; j <= col2; j++)
            rect[i][j] = newValue;
};

SubrectangleQueries.prototype.getValue = function(row, col) {
    return this.rect[row][col];
};
