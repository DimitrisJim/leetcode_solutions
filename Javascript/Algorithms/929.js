let numUniqueEmails = emails => {
    const email_set = new Set;
    for (let email of emails){
        let [local, domain] = _.split(email, "@");
        local = _.split(local, '+', 1)[0];
        email_set.add([_.split(local, '.').join(""), domain].join("@"));
    }
    return email_set.size
};
