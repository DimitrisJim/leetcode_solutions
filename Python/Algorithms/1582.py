class Solution:
    def numSpecial(self, mat):
        occupied_columns = set()
        rows, columns = len(mat), len(mat[0])
        special = 0
        r_range, c_range = range(rows), range(columns)
        
        for r in r_range:
            for c in c_range:
                # found '1'
                if mat[r][c]:
                    # '1' present in a column, go to next row.
                    if c in occupied_columns:
                        break

                    bail = False
                    # reaching this point means we haven't seen
                    # another '1' so far in row, search till end.
                    row = mat[r]
                    for tc in range(c+1, columns):
                        # if we find another '1', add it to occ_cols
                        # and bail.
                        if row[tc]:
                            occupied_columns.update({c, tc})
                            bail = True
                            break
                    if bail:
                        break        
                    # Check em all here. 
                    for tr in r_range:
                        # if we find another '1', add it to occ_cols
                        # and bail. (don't count current row.)
                        if mat[tr][c] and tr != r:
                            occupied_columns.add(c)
                            bail = True
                            break
                    if bail:
                        break 

                    # add 'c' to occupied columns:
                    occupied_columns.add(c)    
                    # reaching this point means we have a special position.
                    special = special + 1
                    break
            
        # Finally, return.
        return special
