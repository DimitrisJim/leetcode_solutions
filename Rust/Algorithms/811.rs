use std::collections::HashMap;

impl Solution {
    pub fn subdomain_visits(cpdomains: Vec<String>) -> Vec<String> {
        let mut domains = HashMap::new();

        for cpd in cpdomains.iter() {
            // Split on ' ' and '.'.
            let parts: Vec<_> = cpd.split(|c| c == ' ' || c == '.').collect();
            let value: i32 = parts[0].parse().unwrap();
            let mut domain = parts[1..].join(".");

            // Add bottom and top level.
            *domains.entry(domain).or_insert(0) += value;
            *domains
                .entry(parts.last().expect("").to_string())
                .or_insert(0) += value;

            // If it exists, add middle level.
            if parts.len() == 4 {
                domain = parts[2..].join(".");
                *domains.entry(domain).or_insert(0) += value;
            }
        }
        // Build the result
        domains
            .iter()
            .map(|kv| [kv.1.to_string(), kv.0.to_string()].join(" "))
            .collect()
    }
}
