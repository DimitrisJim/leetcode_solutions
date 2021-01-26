class Solution:
    def groupThePeople(self, groupSizes):
        # use a map: id -> group to store groups.
        d, result = {}, []
        for i in range(len(groupSizes)):
            # immediately push if group size == 1.
            if (group_i := groupSizes[i]) == 1:
                result.append([i])
                continue

            # Set to list with i and continue.
            if not (group := d.get(group_i, [])):
                d[group_i] = [i]
                continue
            # once a group has been filled up,
            # append it to result and clear
            # group.
            if len(group) == group_i:
                result.append(group)
                d[group_i] = [i]
            else:
                group.append(i)

        # append all remaining groups
        result.extend(d.values())
        return result
