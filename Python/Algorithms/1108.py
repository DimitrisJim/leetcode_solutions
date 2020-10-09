class Solution:
    def defangIPaddr(self, address: str) -> str:
        # comprehension builds the string contents.
        # "".join then creates the resulting string.
        return "".join([c if c != '.' else '[.]' for c in address])
