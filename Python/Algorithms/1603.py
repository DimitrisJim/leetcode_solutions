class ParkingSystem:
    # just wanted to see how much memory we can save. 
    __slots__ = ('A', 'B', 'C')
    
    def __init__(self, big: int, medium: int, small: int):
        setattr(self, 'A', big)
        setattr(self, 'B', medium)
        setattr(self, 'C', small)

    def addCar(self, carType: int) -> bool:
        cartype = chr(carType + 64)
        t = getattr(self, cartype)
        if t:
            setattr(self, cartype, t - 1)
            return True
        return False
