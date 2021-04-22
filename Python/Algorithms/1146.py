class SnapshotArray:
    # could only use dicts iff snap_id > 0.
    # that complicates things and I'm not sure
    # how much we benefit.
    def __init__(self, length: int):
        self.storage = [{0: 0} for _ in range(length)]
        self.snap_id = 0

    def set(self, index: int, val: int) -> None:
        # while no snapshots have been made, just update value.
        self.storage[index][self.snap_id] = val

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id - 1

    def get(self, index: int, snap_id: int) -> int:
        snapshots = self.storage[index]
        if snap_id in snapshots:
            return snapshots[snap_id]
        # Go through keys (snapshots) and return
        # the largest snapshot <= snap_id.
        for i in reversed(snapshots.keys()):
            if i <= snap_id:
                return snapshots[i]
