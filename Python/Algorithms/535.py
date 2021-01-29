class Codec:
    """ This is just the most basic idiotic O(1) implementation. """
    _table = []

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL. """
        self._table.append(longUrl)
        return f'{len(self._table) - 1}'

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL. """
        return self._table[int(shortUrl)]
