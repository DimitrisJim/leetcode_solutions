let add_domain = (map, domain, count) => {
        // Insert or update domain-count pair.
        if (map.has(domain)){
            count += map.get(domain);
        }
        map.set(domain, count);
}

/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function(cpdomains) {
    let domain_counts = new Map;
    for (let cpd of cpdomains) {
        // Get count and domain.
        let [count, domain] = cpd.split(" ");
        count = parseInt(count);
        
        // Insert or update lowest-level domain-count pair.
        add_domain(domain_counts, domain, count);
        
        // Add lowest level.
        let parts = domain.split('.');
        add_domain(domain_counts, parts.slice(-1)[0], count);
        
        // If it exists, add middle level.
        if (parts.length == 3) {
            add_domain(domain_counts, parts[1] + '.' + parts[2], count);
        }
    }
    // Build and return list.
    let res = [];
    domain_counts.forEach((value, key) => {
        res.push(value + " " + key);
    })
    return res;
    };
