let numSpecial = mat => {
  const occupied_columns = new Set,
        rows = mat.length, 
        columns = mat[0].length;
  let special = 0;

  for (let r = 0; r < rows; r++) {
    let bail = false;
    for (let c = 0; c < columns; c++) {
      if (mat[r][c]) {
        // See if we've found a col with '1' previously.
        if (occupied_columns.has(c)){
          break;
        }

        // check the rest of the row:
        let row = mat[r];
        for (let k = c + 1; k < columns; k++) {
          if (row[k]) {
            // Add to occupied columns:
            occupied_columns.add(k);
            bail = true; // toggle
            break;
          }
        }
        if (bail) {
          occupied_columns.add(c);
          break;
        }

        // Check rows, all of them.
        for (let k = 0; k < rows; k++) {
          // Don't be tricked by our own row.
          if (mat[k][c] && k != r) {
            occupied_columns.add(c);
            bail = true;
            break;
          }
        }
        if (bail)
          break;

        // if we've reached this point, we're scot-free.
        occupied_columns.add(c);
        special++;
      }
    }
  }
  return special;    
};
