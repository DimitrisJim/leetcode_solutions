class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        domain_counts = defaultdict(int)
        for cpd in cpdomains:
            _, domain = cpd.split()
            visits = int(_)
            # add original domain.
            domain_counts[domain] += visits
            parts = domain.split('.')
            # add final part (com, org etc)
            domain_counts[parts[-1]] += visits
            
            # if we have another sub-domain, add it.
            if len(parts) == 3:
                domain_counts[f"{parts[-2]}.{parts[-1]}"] += visits
                
        return [" ".join([repr(v), k]) for k,v in domain_counts.items()]
