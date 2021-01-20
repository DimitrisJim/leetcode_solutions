impl Solution {
    pub fn reorder_log_files(logs: Vec<String>) -> Vec<String> {
        if logs.len() < 2 {
            return logs;
        }

        // Split once, will use through-out.
        let logs_tr: Vec<_> = logs
            .iter()
            .map(|s| s.split(" ").collect::<Vec<&str>>())
            .collect();
        // Collect rows with digits in Vec, won't alter again.
        let mut digit_rows: Vec<String> = logs_tr
            .iter()
            .filter(|v| char::is_numeric(v[1].chars().next().unwrap()))
            .map(|v| v.join(" ").to_string())
            .collect();
        // Collect rows with letters.
        let mut letter_rows: Vec<_> = logs_tr
            .iter()
            .filter(|v| char::is_alphabetic(v[1].chars().next().unwrap()))
            .collect();

        // Sort by the words after identifier, add identifier to end so it can
        // act as the tie-braker if needed.
        letter_rows.sort_by_key(|v| {
            let identifier = v[0];
            let mut key = v[1..].join(" ").to_string();
            key.push_str(v[0]);
            key
        });

        // Transfrom to Strings, extend with digit rows and return.
        let mut result: Vec<_> = letter_rows
            .into_iter()
            .map(|v| v.join(" ").to_string())
            .collect();
        result.append(&mut digit_rows);
        result
    }
}
