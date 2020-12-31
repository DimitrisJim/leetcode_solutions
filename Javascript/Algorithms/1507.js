let months = new Map([
    "Jan", "Feb", "Mar", "Apr", 
    "May", "Jun", "Jul", "Aug", 
    "Sep", "Oct", "Nov", "Dec"
].map((x, idx) => [x, idx + 1]));

let reformatDate = (date) =>  {
    let [day, month, year] = date.split(' ');
        index = months.get(month);
    
    // Slice of th or rd.
    day = day.slice(0, -2);
    month = index < 10? `0${index}`: index;
    return [
        year, 
        month, 
        day.length == 2? day: `0${day}`
    ].join("-");
};
