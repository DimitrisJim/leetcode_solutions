class Solution:
    def numUniqueEmails(self, emails):
        """ Though I understand this calls C-impl functions, didn't
        expect discrepancy with other to be so big.
        """
        email_set = set()
        for email in emails:
            local, domain = email.split('@')
            local, *_ = local.split('+')
            email_set.add("@".join([local.replace('.', ''), domain]))
        return len(email_set)
    
    def numUniqueEmails_(self, emails):
        email_set = set()
        for email in emails:
            partial_result = []
            for idx, char in enumerate(email):
                if char == '+':
                    idx = email.find('@', idx)
                    break
                if char == '@':
                    break
                if char != '.':
                    partial_result.append(char)               
            partial_result.extend(email[idx:])
            email_set.add("".join(partial_result))
        return len(email_set)
